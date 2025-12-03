# cpp-game-of-life-oop
Implémentation robuste du Jeu de la Vie de Conway en C++ moderne (C++20). Architecture Orientée Objet stricte respectant les principes SOLID, découplage Logique/UI et utilisation de la SFML.

# 🧬 Jeu de la Vie (Conway's Game of Life) - C++ OOP

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-blue.svg?style=for-the-badge)

Une implémentation orientée objet, modulaire et stricte du célèbre automate cellulaire de John Conway. Ce projet a été conçu pour démontrer l'application des principes **SOLID** et des design patterns en C++.

## 📋 Table des Matières
- [Fonctionnalités](#-fonctionnalités)
- [Architecture Technique](#-architecture-technique)
- [Prérequis](#-prérequis)
- [Installation et Compilation](#-installation-et-compilation)
- [Utilisation](#-utilisation)
- [Auteurs](#-auteurs)

## 🚀 Fonctionnalités

* **Simulation Robuste** : Implémentation fidèle des règles de Conway (Survie, Mort, Naissance).
* **Double Mode d'Affichage** :
    * 🖥️ **Mode Console** : Sortie texte et génération de fichiers de logs par itération.
    * 🎨 **Mode Graphique (GUI)** : Visualisation temps réel fluide avec **SFML**, incluant le zoom et le contrôle de la vitesse.
* **Chargement de Fichiers** : Importation de configurations initiales via des fichiers `.txt` structurés.
* **Architecture Extensible** : Les règles de simulation sont isolées, permettant de créer facilement des variantes du jeu sans toucher au moteur.

## 🏗 Architecture Technique

Ce projet se distingue par une conception logicielle rigoureuse privilégiant la maintenabilité et la séparation des responsabilités.

### Concepts Clés
* **Polymorphisme** : L'état des cellules est géré via une hiérarchie de classes (`Cellule` -> `CelluleVivante` / `CelluleMorte`), évitant les booléens magiques.
* **Stratégie (Strategy Pattern)** : La logique d'évolution est encapsulée dans une classe `Regle` indépendante.
* **Double Tampon (Double Buffering)** : Utilisation de deux grilles (état $t$ et état $t+1$) pour garantir des transitions d'état synchrones et sans effets de bord.
* **MVC (tendance)** : Séparation claire entre les données (`Grille`, `Cellule`), le moteur (`Jeu`) et la vue (`GUI`, `GestionnaireFichier`).

### Diagramme de Classes
*(Insérer ici l'image du diagramme de classes UML généré)*
`[Voir le diagramme de classes](./docs/class_diagram.png)`

## 🛠 Prérequis

* **Compilateur C++** compatible C++14 ou supérieur (g++, clang, MSVC).
* **CMake** (version 3.10+ recommandée).
* **Bibliothèque SFML** (Simple and Fast Multimedia Library).

## 📥 Installation et Compilation

1.  **Cloner le dépôt**
    ```bash
    git clone [https://github.com/votre-username/jeu-de-la-vie-poo.git](https://github.com/votre-username/jeu-de-la-vie-poo.git)
    cd jeu-de-la-vie-poo
    ```

2.  **Construire le projet (Via CMake)**
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3.  **Lancer l'exécutable**
    ```bash
    ./JeuDeLaVie
    ```

## 🎮 Utilisation

Le programme attend en entrée un fichier de configuration `.txt` formaté comme suit :

```text
5 10              <-- Lignes Colonnes
0 0 1 0 0 ...     <-- Matrice (0 = Mort, 1 = Vivant)
0 1 1 1 0 ...
...
