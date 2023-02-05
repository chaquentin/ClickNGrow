/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Save
*/

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include "Save.hpp"

#include "GameObject.hpp"
#include "Hud.hpp"
#include "DogPiss.hpp"
#include "Egg.hpp"
#include "Fertilizer.hpp"
#include "GrandpaSkeleton.hpp"
#include "GrandpasStool.hpp"
#include "GrannyBreaksHerWater.hpp"
#include "GrannysAshes.hpp"
#include "Rain.hpp"
#include "WaterDrop.hpp"
#include "WateringCan.hpp"

#include "Hud.hpp"

#include <tuple>

std::vector<std::string> clickNGrow::Save::getElapsedTimeMoney(void)
{
    unsigned int timeSinceLastSave = _timeSinceLastSave;

    int day = timeSinceLastSave / 86400;
    timeSinceLastSave -= (day * 86400);
    int hour = timeSinceLastSave / 3600;
    timeSinceLastSave -= (hour * 3600);
    int minute = timeSinceLastSave / 60;
    timeSinceLastSave -= (minute * 60);
    int second = timeSinceLastSave;

    std::string date = std::to_string(day) + " Days, " + std::to_string(hour) + " Hours, " + std::to_string(minute) + " Minutes, " + std::to_string(second) + " Seconds";
    
    return std::vector<std::string>{date, std::to_string(_moneyGotten)};
;
}

const std::vector<clickNGrow::GameObject *> clickNGrow::Save::getObjects(void) const
{
    return _gameObjects;
}

void clickNGrow::Save::saveGame(const std::vector<clickNGrow::GameObject *> gameObject, double money)
{
    std::ofstream file;
    
    file.open("save.json");
    file << "{\n\t\"Upgrades\": [\n";
    for (unsigned int i = 0; i < gameObject.size(); i++) {
        file << "\t\t{\n";
        file << "\t\t\t\"amount\": " << gameObject[i]->getAmount() << ",\n";
        file << "\t\t\t\"price\": " << gameObject[i]->getPrice() << ",\n";
        file << "\t\t\t\"money\": " << gameObject[i]->getMoney() << "\n";
        file << "\t\t}";
        if (i != gameObject.size() - 1)
            file << ",\n";
    }
    file << "\t],\n";
    file << "\t\"Data\": {\n";
    file << "\t\t\t\"LastUpdate\": " << time(NULL) << ",\n";
    file << "\t\t\t\"Money\": " << money << "\n";
    file << "\t}\n}";

    file.close();
}

unsigned int clickNGrow::Save::getTimeSinceLastSave(void) const
{
    return _timeSinceLastSave;
}

double clickNGrow::Save::getMoney(void) const
{
    return _money;
}

clickNGrow::Save::Save(std::vector<clickNGrow::GameObject *> gameObjects)
{
    _timeSinceLastSave = 0;
    _money = 0.0;
    _gameObjects = gameObjects;
    _moneyGotten = 0;
}

clickNGrow::Save::~Save()
{
}

const std::vector<clickNGrow::GameObject *> clickNGrow::Save::load(std::string file)
{
    std::ifstream ifs(file, std::ifstream::binary);
    int multTime = 0;

    if (ifs.is_open()) {

        Json::Reader reader;
        Json::Value completeJsonData;
        reader.parse(ifs, completeJsonData);

        _money = completeJsonData["Data"]["Money"].asDouble();
        _timeSinceLastSave = time(NULL) - completeJsonData["Data"]["LastUpdate"].asUInt();
        multTime = _timeSinceLastSave;
        if (_timeSinceLastSave > 14400) {
            multTime = 14400;
        }

        for (unsigned int i = 0; i < completeJsonData["Upgrades"].size(); i++) {
            _gameObjects[i]->setAmount(completeJsonData["Upgrades"][i]["amount"].asInt());
            _gameObjects[i]->setPrice(completeJsonData["Upgrades"][i]["price"].asFloat());
            _gameObjects[i]->setMoney(completeJsonData["Upgrades"][i]["money"].asFloat());
            _moneyGotten += (completeJsonData["Upgrades"][i]["amount"].asInt() * completeJsonData["Upgrades"][i]["money"].asFloat() * multTime);
            if (i > 0 && completeJsonData["Upgrades"][i - 1]["amount"].asInt()) {
                _gameObjects[i]->setDisplayMode(Revealed);
            }
        }
        _money += _moneyGotten;
        ifs.close();
        return _gameObjects;
    }
    return _gameObjects;
}
