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

void AGameObject::setAmount(float amount)
{
    _amount = amount;
}

int AGameObject::getAmount(void) const
{
    return _amount;
}
