/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrannyBreaksHerWater
*/

#ifndef GRANNYBREAKSHERWATER_HPP_
#define GRANNYBREAKSHERWATER_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class GrannyBreaksHerWater : public AGameObject {
        public:
            GrannyBreaksHerWater();
            ~GrannyBreaksHerWater();
            void display(sf::RenderWindow &) const;
        protected:
        private:
    };
}

#endif /* !GRANNYBREAKSHERWATER_HPP_ */
