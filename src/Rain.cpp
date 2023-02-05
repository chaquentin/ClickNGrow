/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Rain
*/

#include "Rain.hpp"

using namespace clickNGrow;

Rain::Rain() : AGameObject(19000000000, 100000000, Hidden, 0)
{
    _rect = sf::IntRect(0, 1800, 640, 200);
    _position = sf::Vector2f(1280, 1800);
    _sprite->setTextureRect(_rect);
}

Rain::~Rain()
{
}

void Rain::display(sf::RenderWindow &window) const
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
