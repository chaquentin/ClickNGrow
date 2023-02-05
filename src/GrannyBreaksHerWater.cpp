/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrannyBreaksHerWater
*/

#include "GrannyBreaksHerWater.hpp"

using namespace clickNGrow;

GrannyBreaksHerWater::GrannyBreaksHerWater() : AGameObject(1100, 10, Hidden, 0)
{
    _rect = sf::IntRect(0, 400, 640, 200);
    _position = sf::Vector2f(1280, 400);
    _sprite->setTextureRect(_rect);
}

GrannyBreaksHerWater::~GrannyBreaksHerWater()
{
}

void GrannyBreaksHerWater::display(sf::RenderWindow &window) const
{
    sf::Text text;
    sf::Font font;

    if (_displayMode == Revealed) {
        _sprite->setPosition(_position);
        window.draw(*_sprite);
        if (!font.loadFromFile("assets/fonts/ClickNGrow.ttf"))
            return;
        text.setFont(font);
        text.setCharacterSize(60);
        text.setFillColor(sf::Color::Black);
        text.setPosition(_position.x + 150, _position.y + 30);
        text.setString("NBR : " + std::to_string(_amount));
        window.draw(text);
        text.setString("PRICE : " + convertMoney(_price));
        text.setPosition(_position.x + 150, _position.y + 100);
        window.draw(text);
    }
}