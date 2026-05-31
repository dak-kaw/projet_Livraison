#include "../colis_zineb/ColisStandard.h"
#include "../colis_zineb/ColisFragile.h"

#include "../nadia_Transporteur/Velo.h"
#include "../nadia_Transporteur/Camion.h"
#include "../nadia_Transporteur/Drone.h"
#include "../nadia_Transporteur/Avion.h"

#include "../imane_Entreprise/EntrepriseLivraison.h"
#include "../imane_Entreprise/Livraison.h"

#include "Rapport.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <clocale>
#include <iostream>
#include <vector>

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::setlocale(LC_ALL, "");

    std::cout << "--------------------------\n"
              << "SIMULATEUR DE LIVRAISON\n"
              << "--------------------------\n\n";
            
    std::cout << "-- ETAPE 1 : Transporteurs --\n"; 
    
    EntrepriseLivraison entreprise;

    Velo*   velo   = new Velo();
    Camion* camion = new Camion();
    Drone*  drone  = new Drone();
    Avion*  avion  = new Avion();

    entreprise.ajouterTransporteur(velo);
    entreprise.ajouterTransporteur(camion);
    entreprise.ajouterTransporteur(drone);
    entreprise.ajouterTransporteur(avion);

    velo->afficher();
    camion->afficher();
    drone->afficher();
    avion->afficher();

    std::cout << "\n-- ETAPE 2 : Colis --\n";

   // Colis standard : 3 kg, 30x20x15 cm
    ColisStandard* c1 = new ColisStandard(3.0f, 30, 20, 15);
    c1->setDistance(40);

    // Colis standard : 8 kg, 50x40x30 cm
    ColisStandard* c2 = new ColisStandard(8.0f, 50, 40, 30);
    c2->setDistance(100);

    // Colis fragile : 1.5 kg, 20x15x10 cm
    ColisFragile* c3 = new ColisFragile(1.5f, 20, 15, 10);
    c3->setDistance(25);

    // Colis fragile : 0.8 kg, 15x10x10 cm
    ColisFragile* c4 = new ColisFragile(0.8f, 15, 10, 10);
    c4->setDistance(200);

    // Colis lourd : 150 kg, 80x60x50 cm
    ColisStandard* c5 = new ColisStandard(150.0f, 80, 60, 50);
    c5->setDistance(300);

    c1->afficher();
    c2->afficher();
    c3->afficher();
    c4->afficher();
    c5->afficher();

    std::cout << "\n-- ETAPE 3 : Creation des livraisons --\n";

    Livraison* liv1 = entreprise.creerLivraison(c1, "2025-05-01");
    Livraison* liv2 = entreprise.creerLivraison(c2, "2025-05-01");
    Livraison* liv3 = entreprise.creerLivraison(c3, "2025-05-02");
    Livraison* liv4 = entreprise.creerLivraison(c4, "2025-05-02");
    Livraison* liv5 = entreprise.creerLivraison(c5, "2025-05-03");

    std::cout << "\n-- ETAPE 4 : Suivi des livraisons --\n";

     if (liv1) {
        entreprise.mettreAJourEtat(liv1->getId(),
            EtatLivraison::EnTransit, "2025-05-02");
        entreprise.mettreAJourEtat(liv1->getId(),
            EtatLivraison::Livre,     "2025-05-03");
    }
    if (liv2) {
        entreprise.mettreAJourEtat(liv2->getId(),
            EtatLivraison::EnTransit, "2025-05-02");
    }
    if (liv3) {
        entreprise.mettreAJourEtat(liv3->getId(),
            EtatLivraison::EnTransit, "2025-05-03");
        entreprise.mettreAJourEtat(liv3->getId(),
            EtatLivraison::Livre,     "2025-05-04");
    }
    if (liv4) {
        entreprise.mettreAJourEtat(liv4->getId(),
            EtatLivraison::EnTransit, "2025-05-03");
    }
    // liv5 reste EnAttente - pas encore prise en charge

     // Demonstration de la protection contre les retours en arriere
    std::cout << "\n-- Test protection transition invalide --\n";
    try {
        if (liv1)
            liv1->setEtat(EtatLivraison::EnAttente, "2025-05-05");
    } catch (const std::logic_error& e) {
        std::cout << "Exception attrapee : " << e.what() << "\n";
    }

    std::cout << "\n-- ETAPE 5 : Affichage general --\n";
    entreprise.afficherToutes();

    std::cout << "\n-- ETAPE 6 : Rapport --\n";

     Rapport rapport(entreprise.getLivraisons(), "2025-05-09");
    rapport.afficherResume();
    rapport.afficherHistorique();
    rapport.exporterFichier("rapport_final.txt");

    delete c1; delete c2; delete c3; delete c4; delete c5;
    delete velo; delete camion; delete drone; delete avion;
    // Les Livraison* sont gérées par EntrepriseLivraison

    std::cout << "\nProgramme termine avec succes.\n";
    return 0;
}