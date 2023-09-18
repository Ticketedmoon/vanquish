#pragma once

#ifndef VANQUISH_USER_INTERFACE_MANAGER_H
#define VANQUISH_USER_INTERFACE_MANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <vector>

#include "game_entity.h"
#include "user_interface/health_bar.h"
#include "experience_points_bar.h"
#include "player_banner.h"
#include "game_state.h"
#include "text_manager.h"

static constexpr uint8_t TOTAL_UI_COMPONENTS = 1;

class UserInterfaceManager : public GameComponent
{
    public:
        explicit UserInterfaceManager(std::shared_ptr<GameEntity> entity, std::shared_ptr<TextManager> textManager);

        void draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const override;
        void update(GameState& gameState) override;

    private:
        std::vector<std::shared_ptr<GameComponent>> uiComponents;

        std::shared_ptr<TextManager> textManager;
};

#endif //VANQUISH_USER_INTERFACE_MANAGER_H