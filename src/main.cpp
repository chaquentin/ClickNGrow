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
#include "iostream"

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

void display()
{
    for (auto &gameObject : gameObjects) {
        gameObject->display();
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
    float money = 0;
    float timePassed = 0.f;
    sf::Clock clock;
    sf::Text money_text;
    sf::Font font;
    font.loadFromFile("assets/fonts/ClickNGrow.ttf");
    money_text.setFont(font);
    clickNGrow::Hud hud;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
                Pub();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                if (event.mouseButton.x >= 0 && event.mouseButton.x <= 1280 && event.mouseButton.y >= 0 && event.mouseButton.y <= 1080) {
                    hud += 1;
                    if ((int)hud.getMoney() % 10 == 0 && rand() % 10 == 1)
                        Pub();
                }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::J) {
                for (auto &gameObject : gameObjects) {
                    if (WaterDrop *water = dynamic_cast<WaterDrop *>(gameObject))
                        if (hud.getMoney() >= water->getPrice()) {
                            water->setAmount(water->getAmount() + 1);
                            hud += -water->getPrice();
                            water->setPrice(water->getPrice() * 1.25);
                        }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K) {
                for (auto &gameObject : gameObjects) {
                    if (DogPiss *dogpiss = dynamic_cast<DogPiss *>(gameObject))
                        if (hud.getMoney() >= dogpiss->getPrice()) {
                            dogpiss->setAmount(dogpiss->getAmount() + 1);
                            hud += -dogpiss->getPrice();
                            dogpiss->setPrice(dogpiss->getPrice() * 1.25);
                        }
                }
            }
        }
        timePassed += getDeltaTime(clock);
        update(hud, timePassed);
        window.clear();
        hud.display(window);
        display();
        money_text.setString(std::to_string((int)money) + "*");
        money_text.setFillColor(sf::Color::White);
        money_text.setPosition(0, 0);
        window.draw(money_text);
        window.display();
        if (timePassed > 1.f) {
            timePassed = 0.f;
        }
    }
    return 0;
}
