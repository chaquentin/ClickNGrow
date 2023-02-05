/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** AGameObject
*/

#ifndef AGAMEOBJECT_HPP_
#define AGAMEOBJECT_HPP_
#include "GameObject.hpp"

namespace clickNGrow {
    class AGameObject : public GameObject {
        public:
            AGameObject(float price, float money, DisplayMode mode, int amount);
            ~AGameObject() = default;
            float update(float money, float deltaTime);
            virtual void display() const = 0;
            void setDisplayMode(DisplayMode displayMode);
            DisplayMode getDisplayMode(void) const;
            float getPrice(void) const;
            void setPrice(float price);
            float getMoney(void) const;
            void setAmount(float amount);
            void setMoney(float money);
            int getAmount(void) const;
        protected:
            DisplayMode _displayMode;
            float _price;
            float _money;
            int _amount;
        private:
    };
}

#endif /* !AGAMEOBJECT_HPP_ */
