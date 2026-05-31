# projet_Livraison

# Projet 4 : Simulateur de Système de Livraison

## Description
ce projet consiste a devlopper une application de simulation d'un systeme de livraison permettant de gerer differents types de colis et de transporteurs.
L'application calcule automatiquement les couts et les delais de livraison tout en assurant le suivi logique des colis.

## Objectifs du projet
- Gerer les colis et les transporteurs
- Simuler les operations de livraison
- Calculer les coutes et delais automatiquement
- Suivre l'etat des livraisons 
- Generer des rapports et historiques

## Fonctionalites principales 

### Gestion des colis
- Creation d'un colis
- Modification des informations
- Suppression d'un colis
- Types de colis :
    - Standard
    - Fragile

### Gestion des transporteurs
- Velo
- Camion
- Drone
- Avion

Chaque transporteur possede : 
- une capacite maximale
- une vitesse
- un cout par kilometre
- un cout par kilogramme 

### Calcul automatique
Le systeme calcule :
- le cout de livraison
- le delai estime
- les frais supplementaires pour les colis fragiles 

### Suivi logique 
Etats possibles :
- En attente
- En transit
- Livre

### Historique et rapports
- Historique des livraisons
- Rapport de colis livres
- Rapport des coutes

## Technologies utilisees
- C++
- Git & GitHub

## Structure de projet 
PROJET_LIVRAISON/
├── CMakeLists.txt
├── README.md
├── build/
├── colis_zineb/
│   ├── Colis.h / Colis.cpp
│   ├── ColisStandard.h / ColisStandard.cpp
│   └── ColisFragile.h  / ColisFragile.cpp
├── nadia_Transporteur/
│   ├── Transporteur.h  / Transporteur.cpp
│   ├── Velo.h  / Velo.cpp
│   ├── Camion.h / Camion.cpp
│   ├── Drone.h  / Drone.cpp
│   └── Avion.h  / Avion.cpp
├── imane_Entreprise/
│   ├── EtatLivraison.h
│   ├── Livraison.h  / Livraison.cpp
│   └── EntrepriseLivraison.h / EntrepriseLivraison.cpp
└── kawtar_Rapport/
    ├── Rapport.h / Rapport.cpp
    └── main.cpp 
