// ============================================================
// main_demo.cpp  — Démonstration de la partie Étudiante 3
// (Stubs minimaux de Colis et Transporteur pour tester seul)
// ============================================================
#include <iostream>
#include "include/EtatLivraison.h"
#include "include/Livraison.h"
#include "include/EntrepriseLivraison.h"

// ── Stub Colis (remplacé par la vraie classe de l'Étudiante 1) ──
class Colis {
public:
    std::string nom;
    double poids;
    Colis(const std::string& n, double p) : nom(n), poids(p) {}
};

// ── Stub Transporteur avec canDeliver polymorphique ──
class Transporteur {
public:
    std::string nom;
    double poidsMax;
    Transporteur(const std::string& n, double pMax) : nom(n), poidsMax(pMax) {}

    // Méthode virtuelle : le cœur du polymorphisme
    virtual bool canDeliver(Colis* c) const {
        return c->poids <= poidsMax;
    }
    virtual ~Transporteur() = default;
};

// Spécialisation : Drone (livraison légère uniquement)
class Drone : public Transporteur {
public:
    Drone() : Transporteur("Drone", 2.0) {}
    bool canDeliver(Colis* c) const override {
        return c->poids <= poidsMax;   // max 2 kg
    }
};

// Spécialisation : Camion (tout peut livrer)
class Camion : public Transporteur {
public:
    Camion() : Transporteur("Camion", 1000.0) {}
    bool canDeliver(Colis* c) const override {
        return true;   // peut tout livrer
    }
};

// ============================================================
// Programme principal
// ============================================================
int main() {
    std::cout << "=== Démo Étudiante 3 — Suivi des livraisons ===\n\n";

    // 1. Créer des colis
    Colis c1("Téléphone",  0.3);
    Colis c2("Réfrigérateur", 80.0);
    Colis c3("Livre",      0.5);

    // 2. Créer des transporteurs et les ajouter à l'entreprise
    EntrepriseLivraison entreprise;
    Drone  drone;
    Camion camion;
    entreprise.ajouterTransporteur(&drone);   // testé en premier
    entreprise.ajouterTransporteur(&camion);  // fallback

    // 3. Créer des livraisons (attribution automatique)
    std::cout << "── Création des livraisons ──\n";
    Livraison* l1 = entreprise.creerLivraison(&c1, "2026-05-21");
    Livraison* l2 = entreprise.creerLivraison(&c2, "2026-05-21");
    Livraison* l3 = entreprise.creerLivraison(&c3, "2026-05-22");

    // 4. Mise à jour des états
    std::cout << "\n── Mise à jour des états ──\n";
    entreprise.mettreAJourEtat(1, EtatLivraison::EnTransit, "2026-05-22");
    entreprise.mettreAJourEtat(1, EtatLivraison::Livre,     "2026-05-23");
    entreprise.mettreAJourEtat(2, EtatLivraison::EnTransit, "2026-05-22");

    // 5. Affichage de toutes les livraisons
    entreprise.afficherToutes();

    // 6. Rapport final
    entreprise.genererRapport();

    return 0;
}