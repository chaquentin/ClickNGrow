/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrandpaSkeleton
*/

#include "GrandpaSkeleton.hpp"

using namespace clickNGrow;

GrandpaSkeleton::GrandpaSkeleton() : AGameObject(15000000, 100000, Hidden, 0)
{
}

GrandpaSkeleton::~GrandpaSkeleton()
{
}

void GrandpaSkeleton::display() const
{
    if (_displayMode == Revealed) {
        // Display grandpa skeleton at x = 1280 + height(amélio) * 6 & y = 0
    }
}
