/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WaterDrop
*/

#include "WaterDrop.hpp"

using namespace clickNGrow;

WaterDrop::WaterDrop() : AGameObject(15, 0.1, Unrevealed, 0)
{
    _rect = sf::IntRect(0, 0, 640, 200);
    _position = sf::Vector2f(1280, 0);
    _sprite->setTextureRect(_rect);
    this->_displayMode = Revealed;
}

WaterDrop::~WaterDrop()
{
}

void WaterDrop::display(sf::RenderWindow &window) const
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
