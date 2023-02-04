/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Fertilizer
*/

#ifndef FERTILIZER_HPP_
#define FERTILIZER_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class Fertilizer : public AGameObject {
        public:
            Fertilizer();
            ~Fertilizer();
            void display() const;
        protected:
        private:
    };
}

#endif /* !FERTILIZER_HPP_ */
