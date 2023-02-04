/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrannyBreaksHerWater
*/

#include "GrannyBreaksHerWater.hpp"

using namespace clickNGrow;

GrannyBreaksHerWater::GrannyBreaksHerWater() : AGameObject(1100, 10)
{
    _displayMode = Hidden;
    _amount = 0;
}

GrannyBreaksHerWater::~GrannyBreaksHerWater()
{
}

void GrannyBreaksHerWater::display() const
{
    if (_displayMode == Revealed) {
        // Display granny breaks her water at x = 1280 + height(amélio) * 2 & y = 0
    }
}