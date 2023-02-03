/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

namespace clickNGrow {
    class GameObject {
        public:
            virtual ~GameObject() = default;
            virtual void start() = 0;
            virtual void update() = 0;

        protected:
        private:
    };
}

#endif /* !GAMEOBJECT_HPP_ */
