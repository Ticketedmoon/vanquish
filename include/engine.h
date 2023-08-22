#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/View.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <string>
#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <vector>

#include "texture_manager.h"
#include "user_interface_manager.h"
#include "player.h"
#include "enemy.h"
#include "level.h"
#include "tilemap.h"

static uint32_t WINDOW_WIDTH = 1280;
static uint32_t WINDOW_HEIGHT = 720;

static constexpr std::string_view WINDOW_TITLE = "vanquish";
static bool USE_VERTICAL_SYNC = false;
static uint32_t APP_FRAME_RATE = 60;

static constexpr size_t TOTAL_PLAYERS = 1;
static constexpr size_t TOTAL_ENEMIES = 8;
static constexpr size_t TOTAL_UI_COMPONENTS = 8;
static constexpr size_t TOTAL_ENTITIES = TOTAL_PLAYERS + TOTAL_ENEMIES + TOTAL_UI_COMPONENTS;

static const std::string FONT_PATH = "resources/fonts/calibri.ttf";

class Engine {
public:
    void initialise();

private:
    void listenForEvents(sf::RenderWindow &window, Level &level, sf::Time &deltaTime);

    void render(sf::RenderWindow &window, sf::Clock &clock, std::shared_ptr<Player> &player, Level &level,
                std::vector<std::shared_ptr<GameEntity>> &gameEntities);

    static void update(sf::Time &deltaTime, sf::Clock &worldClock, Level &level,
                       std::vector<std::shared_ptr<GameEntity>> &gameEntities);

    static void centerViewOnPlayer(sf::RenderWindow &window, std::shared_ptr<Player> &player, uint32_t levelWidth,
                                   uint32_t levelHeight);

    static void initialiseGameEntities(TextureManager& textureManager, std::shared_ptr<Player>& player,
                                       std::vector<std::shared_ptr<GameEntity>>& gameEntities);

    static void configureGameWindow(sf::RenderWindow &window);

    void startDebugMode(sf::RenderWindow &window, sf::Clock &clock, std::shared_ptr<Player> &player, Level &level);

    void configureTextRendering();

    sf::Font font;
    sf::Text debugText;
    bool debugMode = false;
};
