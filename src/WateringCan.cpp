/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WateringCan
*/

#include "WateringCan.hpp"

using namespace clickNGrow;

WateringCan::WateringCan() : AGameObject(160000000, 1000000, Hidden, 0)
{
    _rect = sf::IntRect(0, 1400, 640, 200);
    _position = sf::Vector2f(1280, 1400);
    _sprite->setTextureRect(_rect);
}

WateringCan::~WateringCan()
{
}

void WateringCan::display(sf::RenderWindow &window) const
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
