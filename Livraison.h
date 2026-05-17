#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <string>
#include <vector>
#include <iostream>

// Forward declarations pour éviter les inclusions cycliques
class Colis;
class Transporteur;

// Enum class pour une gestion d'état sécurisée
enum class EtatLivraison {
    EN_ATTENTE,
    EN_TRANSIT,
    LIVRE
};

class Livraison {
private:
    Colis* colis;                     // Composition : pointeur vers le colis
    Transporteur* transporteur;       // Composition : pointeur vers le transporteur
    EtatLivraison etat;
    std::vector<std::string> historique; // STL : historique des événements

public:
    Livraison(Colis* c, Transporteur* t);
    
    void mettreAJourEtat(EtatLivraison nouvelEtat);
    void ajouterEvenement(const std::string& message);
    
    std::string getEtatString() const;
    void afficherHistorique() const;
};

#endif