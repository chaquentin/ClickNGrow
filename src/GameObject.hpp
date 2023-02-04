/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

enum DisplayMode {
    Hidden,
    Unrevealed,
    Revealed
};

namespace clickNGrow {
    class GameObject {
        public:
            virtual ~GameObject() = default;
            virtual void start() = 0;
            virtual void update(float money, float deltaTime) = 0;
            virtual void display() const = 0;

            virtual void setDisplayMode(DisplayMode displayMode) = 0;
            virtual DisplayMode getDisplayMode(void) const = 0;
            virtual float getPrice(void) const = 0;
            virtual float getMoney(void) const = 0;
            virtual void setAmount(float amount) = 0;
            virtual int getAmount(void) const = 0;
        protected:
        private:
    };
}

#endif /* !GAMEOBJECT_HPP_ */
