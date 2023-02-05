/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GameObject
*/

#include "AGameObject.hpp"
#include <iostream>

using namespace clickNGrow;

AGameObject::AGameObject(float price, float money, DisplayMode mode, int amount)
{
    _displayMode = mode;
    _amount = amount;
    _price = price;
    _money = money;
    _sprite = new sf::Sprite();
    _texture = new sf::Texture();
    _texture->loadFromFile("assets/images/Case.png");
    _sprite->setTexture(*_texture);
}

AGameObject::~AGameObject()
{
    delete _sprite;
    delete _texture;
}

float AGameObject::update(float money, float deltaTime)
{
    if (deltaTime >= 1) {
        money += _money * _amount;
    }
    return money;
}

/*-----------------------------Getters/Setters-------------------------------*/

void AGameObject::setDisplayMode(DisplayMode displayMode)
{
    _displayMode = displayMode;
}

DisplayMode AGameObject::getDisplayMode(void) const
{
    return _displayMode;
}

float AGameObject::getPrice(void) const
{
    return _price;
}

void AGameObject::setPrice(float price)
{
    _price = price;
}

float AGameObject::getMoney(void) const
{
    return _money;
}

void AGameObject::setMoney(float money)
{
    _money = money;
}

void AGameObject::setAmount(float amount)
{
    _amount = amount;
}

int AGameObject::getAmount(void) const
{
    return _amount;
}

sf::Vector2f AGameObject::getPosition(void) const
{
    return _position;
}

void AGameObject::setPosition(sf::Vector2f position)
{
    _position = position;
}
