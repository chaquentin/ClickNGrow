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
            AGameObject(float price, float money);
            ~AGameObject() = default;
            virtual void update(float money, float deltaTime);
            virtual void display() const = 0;
            virtual void setDisplayMode(DisplayMode displayMode);
            virtual DisplayMode getDisplayMode(void) const;
            virtual float getPrice(void) const;
            virtual float getMoney(void) const;
            virtual void setAmount(int amount);
            virtual int getAmount(void) const;
        protected:
            DisplayMode _displayMode;
            const float _price;
            const float _money;
            int _amount;
        private:
    };
}

#endif /* !AGAMEOBJECT_HPP_ */
