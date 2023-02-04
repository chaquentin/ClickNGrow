/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

#include "GameObject.hpp"

static const std::vector<clickNGrow::GameObject *> gameObjects = {
    
};

void displayScene(unsigned int scene)
{
    // Display scene rectangle with y = 1080 * scene & x = 0
}

void display()
{
    for (auto &gameObject : gameObjects) {
        gameObject->display();
    }
}

void update(float money, float deltaTime)
{
    for (auto &gameObject : gameObjects) {
        gameObject->update(money, deltaTime);
    }
}

int main(void)
{
    // create SFML loop here
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ClickNGrow");
    unsigned int scene = 0;
    float money = 0;
    float deltaTime = 0;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        deltaTime += clock.getElapsedTime().asSeconds();
        update(money, deltaTime);
        window.clear();
        displayScene(scene);
        display();
        window.display();
        if (deltaTime > 1)
            deltaTime = 0;
    }
    return 0;
}
