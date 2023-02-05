/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** AGameObject
*/

#ifndef AGAMEOBJECT_HPP_
#define AGAMEOBJECT_HPP_

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

namespace clickNGrow {
    class AGameObject : public GameObject {
        public:
            AGameObject(float price, float money, DisplayMode mode, int amount);
            ~AGameObject();
            float update(float money, float deltaTime);
            virtual void display(sf::RenderWindow &) const = 0;
            void setDisplayMode(DisplayMode displayMode);
            DisplayMode getDisplayMode(void) const;
            float getPrice(void) const;
            void setPrice(float price);
            float getMoney(void) const;
            void setAmount(float amount);
            void setMoney(float money);
            int getAmount(void) const;
            sf::Vector2f getPosition(void) const;
            void setPosition(sf::Vector2f position);
        protected:
            sf::Sprite *_sprite;
            sf::Texture *_texture;
            sf::Vector2f _position;
            sf::IntRect _rect;
            DisplayMode _displayMode;
            float _price;
            float _money;
            int _amount;
        private:
    };
}

std::string convertMoney(double money);

#endif /* !AGAMEOBJECT_HPP_ */
