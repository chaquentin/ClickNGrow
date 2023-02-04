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
}

WaterDrop::~WaterDrop()
{
}

void WaterDrop::update(float money, float deltaTime)
{
    if (deltaTime > 1)
        money += _money * _amount;
}

void WaterDrop::display() const
{
    if (_displayMode == Revealed) {
        // Display water drop at x = 1280 & y = 0
    }
}

/*-----------------------------Getters/Setters-------------------------------*/

void WaterDrop::setDisplayMode(DisplayMode displayMode)
{
    _displayMode = displayMode;
}

DisplayMode WaterDrop::getDisplayMode(void) const
{
    return _displayMode;
}

float WaterDrop::getPrice(void) const
{
    return _price;
}

float WaterDrop::getMoney(void) const
{
    return _money;
}

void WaterDrop::setAmount(int amount)
{
    _amount = amount;
}

int WaterDrop::getAmount(void) const
{
    return _amount;
}
