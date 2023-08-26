#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Clock.hpp>

class GameComponent : public sf::Drawable
{
    public:
        void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override = 0;
        virtual void update(sf::Clock& worldClock, sf::Time& deltaTime, uint32_t levelWidth, uint32_t levelHeight) = 0;
        virtual void reset() = 0;

};