/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrandpasStool
*/

#include "GrandpasStool.hpp"

using namespace clickNGrow;

GrandpasStool::GrandpasStool() : AGameObject(1400000, 10000, Hidden, 0)
{
}

GrandpasStool::~GrandpasStool()
{
}

void GrandpasStool::display() const
{
    if (_displayMode == Revealed) {
        // Display granda's stool at x = 1280 + height(amélio) * 5 & y = 0
    }
}
