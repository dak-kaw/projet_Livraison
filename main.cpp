#include <iostream>
#include "EntrepriseLivraison.h"
#include "Livraison.h"
#include "EtatLivraison.h"

int main() {
    std::cout << "=== Démonstration : Suivi des Livraisons & États ===\n\n";

    // ─── 1. Création de l'entreprise ─────────────────────────────────────────
    EntrepriseLivraison entreprise;

    // ─── 2. Ajout de livraisons ───────────────────────────────────────────────
    // Les données colis et transporteur viennent des autres parties du groupe.
    // Ici on les passe directement en paramètres.
    Livraison& l1 = entreprise.ajouterLivraison(
        "PKG-001", "Téléphone Samsung 0.5kg", 0.5,
        "Drone Express", "Drone",
        "Casablanca, Quartier Maarif", 19.0, 1
    );

    Livraison& l2 = entreprise.ajouterLivraison(
        "PKG-002", "Moniteur Dell 8kg", 8.0,
        "Vélo Coursier", "Vélo",
        "Rabat, Agdal", 34.0, 1
    );

    Livraison& l3 = entreprise.ajouterLivraison(
        "PKG-003", "Livre C++ 1.2kg", 1.2,
        "Vélo Coursier", "Vélo",
        "Marrakech, Guéliz", 13.6, 2
    );

    Livraison& l4 = entreprise.ajouterLivraison(
        "PKG-004", "Meuble 80kg", 80.0,
        "Camion Régional", "Camion",
        "Agadir, Hay Mohammadi", 230.0, 3
    );

    std::cout << "▶ " << entreprise.nbTotal() << " livraisons créées\n\n";

    // ─── 3. Résumé initial de chaque livraison ────────────────────────────────
    std::cout << l1.resume() << "\n\n";
    std::cout << l2.resume() << "\n\n";

    // ─── 4. Mise à jour d'états ────────────────────────────────────────────────
    std::cout << "=== Mise à jour des états ===\n";

    // Livraison 1 : cycle complet EN_ATTENTE → EN_TRANSIT → LIVRE
    entreprise.mettreEnTransit(l1.getId(), "Pris en charge à l'entrepôt d'Agadir");
    entreprise.marquerLivree(l1.getId(), "Remis en main propre au client");

    // Livraison 2 : seulement en transit
    entreprise.mettreEnTransit(l2.getId());

    // Livraison 3 : cycle complet
    l3.mettreEnTransit("Chargé sur le vélo, départ 08h00");
    l3.marquerLivree("Déposé en boîte aux lettres");

    // Livraison 4 : reste en attente

    std::cout << "✓ États mis à jour\n\n";

    // ─── 5. Test de transition invalide ──────────────────────────────────────
    std::cout << "=== Test : transition invalide ===\n";
    try {
        l1.marquerLivree("tentative invalide"); // déjà LIVRE → doit lever une exception
    } catch (const std::logic_error& e) {
        std::cout << "Exception attendue : " << e.what() << "\n\n";
    }

    // ─── 6. Historiques ────────────────────────────────────────────────────────
    std::cout << l1.rapportHistorique() << "\n";
    std::cout << l4.rapportHistorique() << "\n";

    // ─── 7. Filtrage par état (STL vector) ────────────────────────────────────
    std::cout << "=== Filtrage : livraisons EN ATTENTE ===\n";
    auto enAttente = entreprise.filtrerParEtat(EtatLivraison::EN_ATTENTE);
    for (Livraison* l : enAttente)
        std::cout << "  " << *l << "\n";
    std::cout << "\n";

    std::cout << "=== Filtrage : livraisons EN TRANSIT ===\n";
    auto enTransit = entreprise.filtrerParEtat(EtatLivraison::EN_TRANSIT);
    for (Livraison* l : enTransit)
        std::cout << "  " << *l << "\n";
    std::cout << "\n";

    // ─── 8. Statistiques par état (STL map) ───────────────────────────────────
    std::cout << "=== Statistiques par état (STL map) ===\n";
    auto stats = entreprise.statistiquesParEtat();
    for (const auto& [etat, nb] : stats)
        std::cout << "  " << etatToString(etat) << " : " << nb << "\n";
    std::cout << "\n";

    // ─── 9. Rapport global ────────────────────────────────────────────────────
    std::cout << entreprise.genererRapport();

    // ─── 10. Tableau de bord ─────────────────────────────────────────────────
    entreprise.afficherTableauDeBord(std::cout);

    // ─── 11. Démonstration des surcharges d'opérateurs ───────────────────────
    std::cout << "\n=== Surcharges d'opérateurs ===\n";
    std::cout << "operator<<  (Livraison)          : " << l1 << "\n";
    std::cout << "operator==  (l1 == l1)           : " << (l1 == l1 ? "vrai" : "faux") << "\n";
    std::cout << "operator==  (l1 == l2)           : " << (l1 == l2 ? "vrai" : "faux") << "\n";
    std::cout << "operator<<  (EntrepriseLivraison) : " << entreprise << "\n";
    std::cout << "operator[]  (accès par ID)       : " << entreprise[l2.getId()].getNomTransporteur() << "\n";

    // ─── 12. Export CSV ──────────────────────────────────────────────────────
    std::cout << "\n=== Export CSV ===\n";
    std::cout << entreprise.genererCSV();

    return 0;
}
