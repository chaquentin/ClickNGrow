/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Fertilizer
*/

#include "Fertilizer.hpp"

using namespace clickNGrow;

Fertilizer::Fertilizer() : AGameObject(130000, 1000, Hidden, 0)
{
}

Fertilizer::~Fertilizer()
{
}

void Fertilizer::display() const
{
    if (_displayMode == Revealed) {
        // Display fertilizer at x = 1280 + height(amélio) * 4 & y = 0
    }
}
