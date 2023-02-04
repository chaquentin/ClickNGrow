/*
** EPITECH PROJECT, 2023
** gameJam
** File description:
** Hud
*/

#ifndef HUD_HPP_
#define HUD_HPP_

#include <SFML/Graphics.hpp>

namespace clickNGrow {
    class Hud {
        public:
            Hud();
            ~Hud();
            void display(sf::RenderWindow &) const;
            void levelUp();

        protected:
            sf::Texture *_texture;
            sf::Sprite *_sprite;
            sf::Vector2f _position;
            sf::IntRect _rect;
        private:
    };
}

#endif /* !HUD_HPP_ */
