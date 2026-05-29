#pragma once
#include "Livraison.h"
#include <vector>
#include <string>
#include <fstream>

class Rapport {
    private:
        const std::vector<Livraison>& livraisons;
        std::string dateGeneration;
        int   compterParEtat(EtatLivraison e) const;
        float calculerCoutTotal() const;
        float calculerDelaiMoyen() const;
        float calculerCoutMoyen() const;
    public:
        Rapport(const std::vector<Livraison>& livs, std::string date);

        // Affichage console
        void afficherResume()    const;
        void afficherDetail()    const;
        void afficherHistorique() const;

        // Exportation
        void exporterFichier(const std::string& nomFichier) const;
    };