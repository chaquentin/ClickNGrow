/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Egg
*/

#include "Egg.hpp"

using namespace clickNGrow;

Egg::Egg() : AGameObject(1700000000, 10000000)
{
    _displayMode = Hidden;
    _amount = 0;
}

Egg::~Egg()
{
}

void Egg::display() const
{
    if (_displayMode == Revealed) {
        // Display egg at x = 1280 + height(amélio) * 8 & y = 0
    }
}
