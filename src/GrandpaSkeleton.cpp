/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrandpaSkeleton
*/

#include "GrandpaSkeleton.hpp"

using namespace clickNGrow;

GrandpaSkeleton::GrandpaSkeleton() : AGameObject(15000000, 100000, Hidden, 0)
{
    _rect = sf::IntRect(0, 1200, 640, 200);
    _position = sf::Vector2f(1280, 1200);
    _sprite->setTextureRect(_rect);
}

GrandpaSkeleton::~GrandpaSkeleton()
{
}

void GrandpaSkeleton::display(sf::RenderWindow &window) const
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
