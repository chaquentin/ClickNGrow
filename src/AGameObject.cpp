/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GameObject
*/

#include "AGameObject.hpp"

using namespace clickNGrow;

AGameObject::AGameObject(float price, float money, DisplayMode mode, int amount) : _price(price), _money(money)
{
    _displayMode = mode;
    _amount = amount;
}

void AGameObject::update(float &money, float deltaTime)
{
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

float AGameObject::getMoney(void) const
{
    return _money;
}

void AGameObject::setAmount(int amount)
{
    _amount = amount;
}

int AGameObject::getAmount(void) const
{
    return _amount;
}
