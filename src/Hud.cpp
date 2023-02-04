/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** Hud
*/

#include <iostream>
#include "Hud.hpp"

using namespace clickNGrow;

Hud::Hud()
{
    _texture = new sf::Texture();
    _sprite = new sf::Sprite();
    _levelTexture = new sf::Texture();
    _level = new sf::Sprite();
    _position = sf::Vector2f(0, 0);
    _rect = sf::IntRect(0, 0, 1280, 1080);
    _texture->loadFromFile("assets/images/Countor.png");
    _levelTexture->loadFromFile("assets/images/Niv.png");
    _sprite->setPosition(_position);
    _sprite->setTexture(*_texture);
    _level->setPosition(_position);
    _level->setTextureRect(_rect);
    _level->setTexture(*_levelTexture);
    _money = 0;
}

Hud::~Hud()
{
    delete _texture;
    delete _sprite;
}

void Hud::display(sf::RenderWindow &window) const
{
    window.draw(*_level);
    window.draw(*_sprite);
}

void Hud::levelUp()
{
    _rect.top += 1080;
    _level->setTextureRect(_rect);
}

int Hud::getMoney() const
{
    return _money;
}

void Hud::setMoney(int money)
{
    _money = money;
}

Hud &Hud::operator+=(int money)
{
    _money += money;
    return *this;
}
