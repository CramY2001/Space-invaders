#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include <vector>

class Enemy : public sf::Drawable {
private:
    sf::ConvexShape shape;  
    bool destroyed;  // Flaga oznaczająca, czy wróg został zniszczony

    // Funkcja rysująca obiekt Enemy na ekranie
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Enemy(sf::Vector2f position);  // Konstruktor inicjalizujący wroga na podanej pozycji

    void update();  // Aktualizacja pozycji wroga
    void dropBomb(std::vector<Projectile>& bombs);  // Zrzucenie bomby
    void destroy();  // Oznaczenie wroga jako zniszczonego

    sf::FloatRect getBounds() const;  // Pobranie granic wroga 
    bool isDestroyed() const;  // Sprawdzenie, czy wróg został zniszczony
};

#endif // ENEMY_h
