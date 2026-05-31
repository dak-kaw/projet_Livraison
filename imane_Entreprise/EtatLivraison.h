#pragma once
#include <string>

// ============================================================
// Enum class EtatLivraison
// Représente les 3 états possibles d'une livraison
// ============================================================
enum class EtatLivraison {
    EnAttente,   // Livraison créée, pas encore prise en charge
    EnTransit,   // Livraison en cours de transport
    Livre        // Livraison terminée
};

// Fonction utilitaire : convertit l'état en texte lisible
inline std::string etatToString(EtatLivraison etat) {
    switch (etat) {
        case EtatLivraison::EnAttente:  return "En attente";
        case EtatLivraison::EnTransit:  return "En transit";
        case EtatLivraison::Livre:      return "Livree";
        default:                         return "Inconnu";
    }
}