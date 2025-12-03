#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm> // pour std::clamp

class Slider {
public:
    Slider(sf::Vector2f position, float width) : width(width) {
        // Configuration du rail (la barre)
        track.setSize({width, 5.0f});
        track.setPosition(position);
        track.setFillColor(sf::Color(200, 200, 200));
        track.setOutlineColor(sf::Color::Black);
        track.setOutlineThickness(1.0f);

        // Configuration du bouton (le rond qu'on bouge)
        knob.setRadius(10.0f);
        knob.setOrigin({10.0f, 10.0f}); // Centre le point d'origine
        knob.setPosition({position.x, position.y + 2.5f}); // Au début du rail
        knob.setFillColor(sf::Color::Red);
        knob.setOutlineColor(sf::Color::Black);
        knob.setOutlineThickness(1.0f);
    }

    // Gestion des événements (clic et déplacement)
    // Note: Adapté pour SFML 3 selon votre code
    void handleEvent(const sf::Window& window, const sf::Event& event) {
        // Si on clique
        if (const auto* mousePress = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePress->button == sf::Mouse::Button::Left) {
                sf::Vector2f mousePos(mousePress->position.x, mousePress->position.y);
                if (knob.getGlobalBounds().contains(mousePos)) {
                    isDragging = true;
                } else if (track.getGlobalBounds().contains(mousePos)) {
                    // Optionnel : Cliquer sur la barre déplace le bouton directement
                    isDragging = true;
                    updateKnobPosition(mousePos.x);
                }
            }
        }
        // Si on relâche
        else if (const auto* mouseRelease = event.getIf<sf::Event::MouseButtonReleased>()) {
             if (mouseRelease->button == sf::Mouse::Button::Left) {
                 isDragging = false;
             }
        }
        // Si on bouge la souris
        else if (const auto* mouseMove = event.getIf<sf::Event::MouseMoved>()) {
            if (isDragging) {
                updateKnobPosition(static_cast<float>(mouseMove->position.x));
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(track);
        window.draw(knob);
    }

    // Retourne une valeur entre 0.0 et 1.0
    float getValue() const {
        return value;
    }

private:
    sf::RectangleShape track;
    sf::CircleShape knob;
    float width;
    float value = 0.5f; // Entre 0 et 1
    bool isDragging = false;

    void updateKnobPosition(float mouseX) {
        float trackLeft = track.getPosition().x;
        float trackRight = trackLeft + width;
        
        // On limite la position X entre le début et la fin du rail
        float newX = std::clamp(mouseX, trackLeft, trackRight);
        
        knob.setPosition({newX, track.getPosition().y + 2.5f});
        
        // Calcul du pourcentage (0.0 à 1.0)
        value = (newX - trackLeft) / width;
    }
};