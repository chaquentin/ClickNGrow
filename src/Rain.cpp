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
}

Rain::~Rain()
{
}

void Rain::display() const
{
    if (_displayMode == Revealed) {
        // Display rain at x = 1280 + height(amélio) * 9 & y = 0
    }
}
