#include "Player.h"
#include <chrono>

Player::Player(sf::Vector2f position)
    : health(1000), shootCooldown(0.2f) {  // Cooldown ustawiony na 0.5 sekundy
    shape.setSize(sf::Vector2f(20, 50));  // Ustawienie rozmiaru gracza
    shape.setFillColor(sf::Color::Green);  // Ustawienie koloru gracza
    shape.setPosition(position);  // Ustawienie początkowej pozycji gracza
    lastShotTime = std::chrono::steady_clock::now();  // Inicjalizacja czasu ostatniego strzału
}

void Player::move(float dx) {
    shape.move(dx, 0);  // Ruch gracza w poziomie
}

void Player::shoot(std::vector<Projectile>& projectiles) {
    auto now = std::chrono::steady_clock::now();
    float elapsedTime = std::chrono::duration<float>(now - lastShotTime).count();

    if (elapsedTime >= shootCooldown) {
        // Dodanie nowego pocisku na górze gracza
        projectiles.emplace_back(shape.getPosition() + sf::Vector2f(shape.getSize().x / 2, -10), -5);
        lastShotTime = now;  // Aktualizacja czasu ostatniego strzału
    }
}

void Player::takeDamage() {
    --health;  // Zmniejszenie liczby żyć gracza
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();  // Pobranie granic gracza (do kolizji)
}

int Player::getHealth() const {
    return health;  // Zwrócenie liczby żyć gracza
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);  // Rysowanie gracza na ekranie
}
