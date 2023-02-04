/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** Hud
*/

#include "Hud.hpp"

using namespace clickNGrow;

Hud::Hud()
{
    _texture = new sf::Texture();
    _sprite = new sf::Sprite();
    _position = sf::Vector2f(0, 0);
    _rect = sf::IntRect(0, 0, 1280, 640);
    _texture->loadFromFile("assets/images/hud.png");
    _sprite->setTextureRect(_rect);
    _sprite->setTexture(*_texture);
}

Hud::~Hud()
{
    delete _texture;
    delete _sprite;
}

void Hud::display(sf::RenderWindow &window) const
{
    window.draw(*_sprite);
}
