/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <SFML/Graphics.hpp>

enum DisplayMode {
    Hidden,
    Unrevealed,
    Revealed
};

namespace clickNGrow {
    class GameObject {
        public:
            virtual ~GameObject() = default;
            virtual float update(float money, float deltaTime) = 0;
            virtual void display(sf::RenderWindow &) const = 0;

            virtual void setDisplayMode(DisplayMode displayMode) = 0;
            virtual DisplayMode getDisplayMode(void) const = 0;
            virtual float getPrice(void) const = 0;
            virtual float getMoney(void) const = 0;
            virtual void setAmount(float amount) = 0;
            virtual void setPrice(float price) = 0;
            virtual void setMoney(float money) = 0;
            virtual int getAmount(void) const = 0;
            virtual sf::Vector2f getPosition(void) const = 0;
            virtual void setPosition(sf::Vector2f position) = 0;
        protected:
        private:
    };
}

#endif /* !GAMEOBJECT_HPP_ */
