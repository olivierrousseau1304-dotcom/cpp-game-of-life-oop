#pragma once
#include <SFML/Graphics.hpp>

#include "Slider.h"

class GameOfLifeUI {
public:
    GameOfLifeUI();
    void Display();
private:
    void GenerateGrid();
    int xSize = 30;
    int ySize = 30;
    float cellSize = 50. ;
    sf::RenderWindow window;

    Slider mySlider;
};
