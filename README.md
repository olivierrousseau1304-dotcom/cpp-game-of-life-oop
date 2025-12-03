# 🧬 Jeu de la Vie (Conway's Game of Life) - C++ OOP

![C++](https://img.shields.io/badge/c++-17-blue.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-3.0.2-8CC445?style=for-the-badge&logo=sfml&logoColor=white)
![Build](https://img.shields.io/badge/build-CMake-red?style=for-the-badge)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg?style=for-the-badge)

Une implémentation robuste et modulaire du célèbre automate cellulaire de John Conway. Ce projet a été conçu pour démontrer l'application stricte des principes **SOLID**, des design patterns et une architecture C++ moderne découplée.

## 📋 Table des Matières
- [Fonctionnalités](#-fonctionnalités)
- [Architecture Logicielle](#-architecture-logicielle)
- [Structure du Projet](#-structure-du-projet)
- [Installation et Compilation](#-installation-et-compilation)
- [Contrôles](#-contrôles)
- [Auteurs](#-auteurs)

## 🚀 Fonctionnalités

* **Moteur de Simulation** : Implémentation fidèle des règles de Conway (Survie, Mort, Naissance) avec gestion des bords.
* **Architecture Découplée** : Séparation stricte entre la logique métier (`Jeu`, `Grille`) et l'interface utilisateur (`GUI`).
* **Interface Graphique (SFML 3)** :
    * Visualisation temps réel de la grille.
    * Système de **Zoom dynamique** via Slider personnalisé.
    * Redimensionnement de fenêtre réactif.
* **Configuration** : Système extensible pour charger des états initiaux (fichiers).

## 🏗 Architecture Logicielle

Ce projet privilégie la maintenabilité et l'évolutivité.

### Concepts Clés
1.  **Polymorphisme & Héritage** : L'état des cellules est géré via une hiérarchie de classes (`Cellule` abstraite $\rightarrow$ `CelluleVivante` / `CelluleMorte`), éliminant les conditions booléennes complexes.
2.  **Stratégie (Strategy Pattern)** : La logique d'évolution est encapsulée dans une classe `Regle` indépendante.
3.  **Double Tampon (Double Buffering)** : Utilisation de deux grilles (état $t$ et état $t+1$) pour garantir des transitions atomiques synchrones.

### Diagramme de Classes
L'architecture complète est documentée ci-dessous :

![Architecture UML](./docs/architecture_uml.png)
*(Assurez-vous que l'image est présente dans le dossier docs/)*

## 📂 Structure du Projet

```text
cpp-game-of-life-oop/
├── CMakeLists.txt       # Configuration de build (Télécharge SFML auto)
├── main.cpp             # Point d'entrée
├── UI/                  # Couche Interface Utilisateur
│   ├── GUI.h / .cpp     # Gestion fenêtre et boucle de rendu
│   └── Slider.h / .cpp  # Composants UI personnalisés
├── Core/                # (À venir) Logique Métier
│   ├── Cellule.h ...
│   ├── Grille.h ...
│   └── Jeu.h ...
└── data/                # Fichiers de configuration (.txt)
```

Installation et Compilation
Ce projet utilise CMake avec FetchContent. Vous n'avez pas besoin d'installer la SFML manuellement, CMake la téléchargera et la compilera pour vous.

Prérequis
Compilateur C++ compatible C++17 (GCC, Clang, MSVC).

CMake (Version 3.14 ou supérieure).

Git.

Étapes de build
Cloner le dépôt

Bash

git clone [https://github.com/olivierrousseau1304-dotcom/cpp-game-of-life-oop.git](https://github.com/olivierrousseau1304-dotcom/cpp-game-of-life-oop.git)
cd cpp-game-of-life-oop
Générer et Compiler

Bash

mkdir build
cd build
cmake ..
cmake --build .
Lancer le jeu

Linux/Mac : ./JeuDeLaVie

Windows : Debug\JeuDeLaVie.exe (selon la config)

🎮 Contrôles
Souris : Interagir avec les éléments UI (Slider de zoom).

Fenêtre : Redimensionnable à la volée.

(Fonctionnalités à venir : Pause/Play avec Espace, Speed Control)

👥 Auteurs
Olivier Rousseau - Conception, Architecture et Développement
