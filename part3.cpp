#include <SFML/Graphics.hpp>

class Bullet {
public:
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

class SimpleBullet : public Bullet {
public:
    void update() override {
        // Update position (move vertically down)
    }

    void render(sf::RenderWindow& window) override {
        // Render bullet on the window
    }
};

class Ship {
protected:
    std::vector<Bullet*> bullets;
public:
    virtual void fire() = 0;
    void updateBullets() {
        for (auto& bullet : bullets) {
            bullet->update();
        }
    }
    void renderBullets(sf::RenderWindow& window) {
        for (auto& bullet : bullets) {
            bullet->render(window);
        }
    }
};

class PlayerShip : public Ship {
public:
    void fire() override {
        // Create and add a new SimpleBullet to the bullets vector
    }
};


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");

    PlayerShip playerShip;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                playerShip.fire();
            }
        }
        playerShip.updateBullets();
        window.display();
    }

    return 0;
}
