/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** WaterDrop
*/

#ifndef WATERDROP_HPP_
#define WATERDROP_HPP_
#include "AGameObject.hpp"

namespace clickNGrow {
    class WaterDrop : public AGameObject {
        public:
            WaterDrop();
            ~WaterDrop();
            void display() const;
        protected:
        private:
    };
}

#endif /* !WATERDROP_HPP_ */
