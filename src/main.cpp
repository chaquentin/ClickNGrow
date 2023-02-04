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
#include <iostream>

#include "GameObject.hpp"
#include "Hud.hpp"

void Pub();

static const std::vector<clickNGrow::GameObject *> gameObjects = {
    
};

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

float getDeltaTime(sf::Clock &clock)
{
    static float deltaTime = 0;

    deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    return deltaTime;
}

int main(void)
{
    // create SFML loop here
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ClickNGrow", sf::Style::Fullscreen);
    unsigned int scene = 0;
    float money = 0;
    float timePassed = 0.f;
    sf::Clock clock;
    clickNGrow::Hud hud;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
                Pub();
        }
        timePassed += getDeltaTime(clock);
        update(money, timePassed);
        window.clear();
        hud.display(window);
        display();
        window.display();
        if (timePassed > 1.f) {
            timePassed = 0.f;
        }
    }
    return 0;
}
