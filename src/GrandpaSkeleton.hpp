/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrandpaSkeleton
*/

#ifndef GRANDPASKELETON_HPP_
#define GRANDPASKELETON_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class GrandpaSkeleton : public AGameObject {
        public:
            GrandpaSkeleton();
            ~GrandpaSkeleton();
            void display() const;
        protected:
        private:
    };
}

#endif /* !GRANDPASKELETON_HPP_ */
