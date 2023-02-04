/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrannysAshes
*/

#include "GrannysAshes.hpp"

using namespace clickNGrow;

GrannysAshes::GrannysAshes() : AGameObject(12000, 100)
{
    _displayMode = Hidden;
    _amount = 0;
}

GrannysAshes::~GrannysAshes()
{
}

void GrannysAshes::display() const
{
    if (_displayMode == Revealed) {
        // Display granny ashes at x = 1280 + height(amélio) * 3 & y = 0
    }
}
