/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Egg
*/

#ifndef EGG_HPP_
#define EGG_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class Egg : public AGameObject {
        public:
            Egg();
            ~Egg();
            void display() const;
        protected:
        private:
    };
}

#endif /* !EGG_HPP_ */
