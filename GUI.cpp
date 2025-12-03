#include "GUI.h"
#include <iostream>

GameOfLifeUI::GameOfLifeUI() :
window(sf::VideoMode({800, 600}), "SFML window"),
mySlider({10.0f, 550.0f}, 200.0f)
{
}

void GameOfLifeUI::Display() {
    sf::View view = window.getDefaultView();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* resized = event->getIf<sf::Event::Resized>()){
                view.setSize(sf::Vector2f(resized->size.x,resized->size.y));
                window.setView(view);

            }
            mySlider.handleEvent(window, *event);
        }
        window.clear();
        float slidervalue = mySlider.getValue();
        cellSize = 50 + slidervalue*(100-50);
        GenerateGrid();
        mySlider.draw(window);
        window.display();
    }
}

void GameOfLifeUI::GenerateGrid() {
    bool test = true;
    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            sf::RectangleShape rectangle({cellSize, cellSize});
            if (test)
                rectangle.setFillColor(sf::Color::Blue);
            else
                rectangle.setFillColor(sf::Color::White);

            rectangle.setOutlineThickness(5.);
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.setPosition(sf::Vector2f(x*cellSize, y*cellSize));
            window.draw(rectangle);
            test = !test;
        }

    }
}
