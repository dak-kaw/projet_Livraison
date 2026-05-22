#pragma once
#include <vector>
#include <map>
#include <string>
#include "Livraison.h"

// Forward declarations
class Colis;
class Transporteur;

// ============================================================
// Classe EntrepriseLivraison  (Étudiante 3)
// Classe centrale : gère toutes les livraisons de l'entreprise
// ============================================================
class EntrepriseLivraison {
private:
    std::vector<Livraison>      livraisons;     // Liste de toutes les livraisons
    std::vector<Transporteur*>  transporteurs;  // Liste des transporteurs disponibles
    int                         prochainId;     // Compteur auto-incrémenté pour les IDs

public:
    // Constructeur
    EntrepriseLivraison();

    // Ajoute un transporteur disponible dans le système
    void ajouterTransporteur(Transporteur* t);

    // Crée une livraison en choisissant automatiquement le meilleur transporteur
    // Utilise canDeliver() en boucle (polymorphisme, pas de if/else sur les types)
    Livraison* creerLivraison(Colis* colis, const std::string& date);

    // Met à jour l'état d'une livraison existante (par ID)
    bool mettreAJourEtat(int idLivraison, EtatLivraison nouvelEtat, const std::string& date);

    // Recherche une livraison par son ID (retourne nullptr si non trouvée)
    Livraison* chercherParId(int idLivraison);

    // Affiche toutes les livraisons
    void afficherToutes() const;

    // Génère un rapport résumé (nombre par état, liste)
    void genererRapport() const;
};