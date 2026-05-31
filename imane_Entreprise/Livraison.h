#pragma once
#include <string>
#include <vector>
#include "EtatLivraison.h"

// Forward declarations (les vraies classes viennent des autres étudiantes)
class Colis;
class Transporteur;

// ============================================================
// Classe Livraison  (Étudiante 3)
// Associe un Colis à un Transporteur avec un état et un historique
// ============================================================
class Livraison {
private:
    float coutTotal;       // Coût total de la livraison (calculé à partir du colis et du transporteur)
    int   delaiJours;     // Délai de livraison en jours (calculé à partir du colis et du transporteur)
    int             id;             // Identifiant unique de la livraison
    Colis*          colis;          // Pointeur vers le colis à livrer
    Transporteur*   transporteur;   // Pointeur vers le transporteur assigné
    EtatLivraison   etat;           // État actuel de la livraison
    std::string     dateCreation;   // Date de création (format simple : "YYYY-MM-DD")
    
    // Historique des transitions d'état : chaque entrée = "état → nouvel état : date"
    std::vector<std::string> historiqueEtats;

public:

    float getCout()  const;
    int   getDelai() const;
    // Constructeur
    Livraison(int id, Colis* colis, Transporteur* transporteur, const std::string& date);

    // Getters
    int             getId()            const;
    Colis*          getColis()         const;
    Transporteur*   getTransporteur()  const;
    EtatLivraison   getEtat()          const;
    std::string     getDateCreation()  const;
    const std::vector<std::string>& getHistorique() const;

    // Met à jour l'état et enregistre la transition dans l'historique
    void setEtat(EtatLivraison nouvelEtat, const std::string& date);

    // Affiche un résumé de la livraison
    void afficher() const;

    // Surcharge de << pour affichage facile
    friend std::ostream& operator<<(std::ostream& os, const Livraison& l);
};