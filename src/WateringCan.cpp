/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WateringCan
*/

#include "WateringCan.hpp"

using namespace clickNGrow;

WateringCan::WateringCan() : AGameObject(160000000, 1000000)
{
    _displayMode = Hidden;
    _amount = 0;
}

WateringCan::~WateringCan()
{
}

void WateringCan::display() const
{
    if (_displayMode == Revealed) {
        // Display watering can at x = 1280 + height(amélio) * 7 & y = 0
    }
}
