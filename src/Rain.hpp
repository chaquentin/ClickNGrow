/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Rain
*/

#ifndef RAIN_HPP_
#define RAIN_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class Rain : public AGameObject {
        public:
            Rain();
            ~Rain();
            void display() const;
        protected:
        private:
    };
}

#endif /* !RAIN_HPP_ */
