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
#include "DogPiss.hpp"
#include "Egg.hpp"
#include "Fertilizer.hpp"
#include "GrandpaSkeleton.hpp"
#include "GrandpasStool.hpp"
#include "GrannyBreaksHerWater.hpp"
#include "GrannysAshes.hpp"
#include "Rain.hpp"
#include "WaterDrop.hpp"
#include "WateringCan.hpp"

void Pub();

using namespace clickNGrow;

static const std::vector<clickNGrow::GameObject *> gameObjects = {
    new WaterDrop(),
    new DogPiss(),
    new GrannyBreaksHerWater(),
    new GrannysAshes(),
    new Fertilizer(),
    new GrandpasStool(),
    new GrandpaSkeleton(),
    new WateringCan(),
    new Egg(),
    new Rain(),
};

std::string convertMoney(double money);

int getMouseEvent(Hud &hud, sf::Event &event)
{
    bool is_new = false;

    if (event.mouseButton.x >= 0 && event.mouseButton.x <= 1280 && event.mouseButton.y >= 0 && event.mouseButton.y <= 1080) {
        hud += 1;
        if ((int)hud.getMoney() % 10 == 0 && rand() % 10 == 1)
            Pub();
    } else {
        for (auto &object : gameObjects) {
            if (is_new) {
                object->setDisplayMode(Revealed);
                is_new = false;
            }
            if (event.mouseButton.x >= object->getPosition().x && event.mouseButton.x <= object->getPosition().x + 640 && event.mouseButton.y >= object->getPosition().y && event.mouseButton.y <= object->getPosition().y + 200) {
                if (hud.getMoney() >= object->getPrice() && object->getDisplayMode() != Hidden) {
                    hud += - object->getPrice();
                    object->setAmount(object->getAmount() + 1);
                    object->setPrice(object->getPrice() * 1.25);
                    if (object->getAmount() == 1) {
                        is_new = true;
                        hud.setNbrDisplay(hud.getNbrDisplay() + 1);
                        hud.levelUp();
                    }
                }
            }
        }
    }
    return 0;
}

int manageScroll(Hud &hud, sf::Event &event)
{
    sf::Vector2f movement = sf::Vector2f(0, 200);

    if (hud.getNbrDisplay() < 6)
        return 0;
    if (event.mouseWheelScroll.delta > 0) {
        if (gameObjects[0]->getPosition().y >= - 200)
            movement.y = -gameObjects[0]->getPosition().y;
        for (auto &object : gameObjects) {
            object->setPosition(object->getPosition() + movement);
        }
    } else if (event.mouseWheelScroll.delta < 0) {
        if (gameObjects[hud.getNbrDisplay() - 1]->getPosition().y < 1080)
            movement.y = gameObjects[hud.getNbrDisplay() - 1]->getPosition().y - 880;
        for (auto &object : gameObjects) {
            object->setPosition(object->getPosition() - movement);
        }
    }
    return 0;
}

void display(sf::RenderWindow &window)
{
    for (auto &gameObject : gameObjects) {
        gameObject->display(window);
    }
}

void update(Hud &hud, float deltaTime)
{
    float money = hud.getMoney();
    for (auto &gameObject : gameObjects) {
        money = gameObject->update(money, deltaTime);
    }
    hud.setMoney(money);
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
    float timePassed = 0.f;
    sf::Clock clock;
    sf::Text money_text;
    sf::Font font;
    font.loadFromFile("assets/fonts/ClickNGrow.ttf");
    money_text.setFont(font);
    clickNGrow::Hud hud;
    srand(time(NULL));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                getMouseEvent(hud, event);
            if (event.type == sf::Event::MouseWheelScrolled)
                manageScroll(hud, event);
        }
        timePassed += getDeltaTime(clock);
        update(hud, timePassed);
        window.clear();
        hud.display(window);
        display(window);
        money_text.setString(convertMoney(hud.getMoney()) + "*");
        money_text.setFillColor(sf::Color::Black);
        money_text.setPosition(35, 30);
        window.draw(money_text);
        window.display();
        if (timePassed > 1.f) {
            timePassed = 0.f;
        }
    }
    for (auto &gameObject : gameObjects)
        delete gameObject;
    return 0;
}
