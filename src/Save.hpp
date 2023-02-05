/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <vector>

#include "GameObject.hpp"


namespace clickNGrow {
    class Save {
        public:
            const std::vector<clickNGrow::GameObject *> getObjects(void) const;
            const std::vector<clickNGrow::GameObject *> load(std::string file = "save.json");
            void saveGame(const std::vector<clickNGrow::GameObject *>, double money);
            double getMoney(void) const;
            unsigned int getTimeSinceLastSave(void) const;
            std::vector<std::string> getElapsedTimeMoney(void);
            int getNbrUpgrades(void) const;
            Save(std::vector<clickNGrow::GameObject *> gameObjects);
            ~Save();
        private:
            unsigned int _timeSinceLastSave;
            std::vector<clickNGrow::GameObject *> _gameObjects;
            double _money;
            double _moneyGotten;
            int _nbrUpgrades;


    };
}

#endif /* !SAVE_HPP_ */
