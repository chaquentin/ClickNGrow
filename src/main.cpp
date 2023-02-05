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

#include "Save.hpp"

void Pub();
void PubForMoney(clickNGrow::Hud *hud, std::vector<clickNGrow::GameObject *> gameObjects);

using namespace clickNGrow;

static std::vector<clickNGrow::GameObject *> gameObjects = {
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
        if ((int)hud.getMoney() % 100 == 0 && rand() % 10 == 1)
            Pub();
        if (event.mouseButton.x >= 20 && event.mouseButton.x <= 120 && event.mouseButton.y >= 945 && event.mouseButton.y <= 1045)
            PubForMoney(&hud, gameObjects);
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

void displayTimeElapsed(sf::RenderWindow &window, sf::Text timeElapsed)
{
    window.draw(timeElapsed);
}

int main(void)
{

    Save save(gameObjects);

    size_t nbrUpgrades = save.load("save.json").size();

    for (unsigned int i = 0; i < nbrUpgrades; i++) {
        gameObjects[i] = save.getObjects()[i];
    };

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ClickNGrow", sf::Style::Fullscreen);
    float timePassed = 0.f;
    int totalseconds = 0;
    sf::Clock clock;
    sf::Text money_text;
    sf::Text pub_text;
    sf::Text timeElapsed;
    sf::Font font;
    sf::CircleShape circle;
    font.loadFromFile("assets/fonts/ClickNGrow.ttf");
    circle.setRadius(50);
    circle.setFillColor(sf::Color::White);
    money_text.setFont(font);
    money_text.setFillColor(sf::Color::Black);
    money_text.setPosition(35, 30);
    pub_text.setFont(font);
    pub_text.setFillColor(sf::Color::Black);
    pub_text.setString("PUB");
    pub_text.setPosition(42, 975);
    circle.setPosition(20, 945);
    timeElapsed.setFont(font);
    timeElapsed.setFillColor(sf::Color::Black);
    timeElapsed.setPosition(100, 300);
    timeElapsed.setString(save.getElapsedTimeMoney()[0] + " since last time played" + "\nMoney earned during this time : " + save.getElapsedTimeMoney()[1] + " *");
    clickNGrow::Hud hud;
    srand(time(NULL));

    hud += save.getMoney();
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
        double total = 0;
        for (auto &object : gameObjects)
            total += object->getMoney() * object->getAmount();
        money_text.setString(convertMoney(hud.getMoney()) + "*\n" + convertMoney(total) + "* / s");
        window.draw(money_text);
        window.draw(circle);
        window.draw(pub_text);
        if (totalseconds < 15)
            displayTimeElapsed(window, timeElapsed);
        window.display();
        if (timePassed > 1.f) {
            timePassed = 0.f;
            totalseconds++;
        }
    }

    save.saveGame(gameObjects, hud.getMoney());

    for (auto &gameObject : gameObjects)
        delete gameObject;
    return 0;
}
