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
            void update(float &money, float deltaTime);
            virtual void display() const = 0;
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

#endif /* !AGAMEOBJECT_HPP_ */
