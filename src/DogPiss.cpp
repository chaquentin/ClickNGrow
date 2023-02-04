/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** DogPiss
*/

#include "DogPiss.hpp"

using namespace clickNGrow;

DogPiss::DogPiss() : AGameObject(100, 1)
{
    _displayMode = Hidden;
    _amount = 0;
}

DogPiss::~DogPiss()
{
}

void DogPiss::display() const
{
    if (_displayMode == Revealed) {
        // Display dog piss at x = 1280 + height(amélio) * 1 & y = 0
    }
}
