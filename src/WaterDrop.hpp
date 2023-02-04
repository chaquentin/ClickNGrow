/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WaterDrop
*/

#ifndef WATERDROP_HPP_
#define WATERDROP_HPP_
#include "GameObject.hpp"

namespace clickNGrow {
    class WaterDrop : public GameObject {
        public:
            WaterDrop();
            ~WaterDrop();
            void update(float money, float deltaTime);
            void display() const;
            void setDisplayMode(DisplayMode displayMode);
            DisplayMode getDisplayMode(void) const;
            float getPrice(void) const;
            float getMoney(void) const;
            void setAmount(int amount);
            int getAmount(void) const;
        protected:
            DisplayMode _displayMode;
            const float _price;
            const float _money;
            int _amount;
        private:
    };
}

#endif /* !WATERDROP_HPP_ */
