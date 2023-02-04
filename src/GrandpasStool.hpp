/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** GrandpasStool
*/

#ifndef GRANDPASSTOOL_HPP_
#define GRANDPASSTOOL_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class GrandpasStool : public AGameObject {
        public:
            GrandpasStool();
            ~GrandpasStool();
            void display() const;
        protected:
        private:
    };
}

#endif /* !GRANDPASSTOOL_HPP_ */
