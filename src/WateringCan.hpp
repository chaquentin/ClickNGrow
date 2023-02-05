/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WateringCan
*/

#ifndef WATERINGCAN_HPP_
#define WATERINGCAN_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class WateringCan : public AGameObject {
        public:
            WateringCan();
            ~WateringCan();
            void display(sf::RenderWindow &) const;
        protected:
        private:
    };
}

#endif /* !WATERINGCAN_HPP_ */
