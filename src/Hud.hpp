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
            int getMoney() const;
            void setMoney(int);
            Hud &operator+=(int);

        protected:
            sf::Texture *_texture;
            sf::Texture *_levelTexture;
            sf::Sprite *_sprite;
            sf::Sprite *_level;
            sf::Vector2f _position;
            sf::IntRect _rect;
            double _money;
        private:
    };
}

#endif /* !HUD_HPP_ */
