/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** ConvertMoney
*/

#include <iostream>

static const std::string symbol = " KMBTQ";

std::string convertMoney(double money)
{
    std::string moneyString;
    int i = 0;

    while (money >= 1000) {
        money /= 1000;
        i++;
    }
    moneyString = std::to_string(money);
    moneyString.resize(5);
    moneyString += symbol[i];
    return moneyString;
}
