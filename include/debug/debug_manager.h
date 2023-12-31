#pragma once

#ifndef VANQUISH_DEBUG_MANAGER_H
#define VANQUISH_DEBUG_MANAGER_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Clock.hpp>

#include <memory>

#include "common_constants.h"
#include "game_component.h"
#include "player.h"
#include "level.h"
#include "text_manager.h"
#include "game_state.h"

class DebugManager : public GameComponent
{
    public:
        DebugManager(std::shared_ptr<Player>& player, std::vector<std::shared_ptr<GameEntity>> entities,
                Level& level, std::shared_ptr<TextManager>& textManager);

        void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;
        void update(GameState& gameState) override;
        void updateDebugState(GameState& gameState);

    private:
        void drawBoundingBoxAroundEntity(sf::RenderTarget& renderTarget, const sf::RenderStates& states,
                const std::shared_ptr<GameEntity>& entity) const;

    private:
        sf::Clock debugClock;
        sf::String debugTextValue;

        std::shared_ptr<Player>& player;
        std::vector<std::shared_ptr<GameEntity>> entities;
        Level& level;
        std::shared_ptr<TextManager>& textManager;
};


#endif //VANQUISH_DEBUG_MANAGER_H
