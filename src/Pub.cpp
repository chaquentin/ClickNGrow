/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Pub
*/

#include <iostream>
#include <vector>
#include "Hud.hpp"
#include "GameObject.hpp"

using namespace clickNGrow;

void Pub()
{
    std::vector<std::string> videos = {"assets/pubs/axe.mp4", "assets/pubs/carrefour.mp4", "assets/pubs/tuneup.mp4", "assets/pubs/crazytyger.mp4", "assets/pubs/zalando.mp4"};
    std::string command = "vlc " + videos[rand() % videos.size()] + " --play-and-exit";
    std::system(command.c_str());
}

void PubForMoney(clickNGrow::Hud *hud, std::vector<clickNGrow::GameObject *> gameObjects)
{
    double total = 0;
    Pub();
    for (auto &object : gameObjects) {
        total += object->getMoney() * object->getAmount();
    }
    total *= 60;
    if (total < 50)
        total = 80;
    *hud += total;
}
