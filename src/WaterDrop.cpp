/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WaterDrop
*/

#include "WaterDrop.hpp"

using namespace clickNGrow;

WaterDrop::WaterDrop() : AGameObject(15, 0.1)
{
    _displayMode = Unrevealed;
    _amount = 0;
}

WaterDrop::~WaterDrop()
{
}

void WaterDrop::display() const
{
    if (_displayMode == Revealed) {
        // Display water drop at x = 1280 & y = 0
    }
}
