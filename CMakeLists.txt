cmake_minimum_required(VERSION 3.10)
project(SimulateurLivraison)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    colis_zineb
    nadia_Transporteur
    imane_Entreprise
    kawtar_Rapport
)

add_executable(projet_Livraison 
    colis_zineb/Colis.cpp
    colis_zineb/ColisStandard.cpp
    colis_zineb/ColisFragile.cpp
    
    nadia_Transporteur/Transporteur.cpp
    nadia_Transporteur/Velo.cpp
    nadia_Transporteur/Camion.cpp
    nadia_Transporteur/Drone.cpp
    nadia_Transporteur/Avion.cpp
    
    imane_Entreprise/Livraison.cpp
    imane_Entreprise/EntrepriseLivraison.cpp
    
    kawtar_Rapport/Rapport.cpp
    kawtar_Rapport/main.cpp
    )

