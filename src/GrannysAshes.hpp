/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrannysAshes
*/

#ifndef GRANNYSASHES_HPP_
#define GRANNYSASHES_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class GrannysAshes : public AGameObject {
        public:
            GrannysAshes();
            ~GrannysAshes();
            void display(sf::RenderWindow &) const;
        protected:
        private:
    };
}

#endif /* !GRANNYSASHES_HPP_ */
