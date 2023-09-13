#include "debug/debug_manager.h"

DebugManager::DebugManager(std::shared_ptr<Player>& player, Level& level, std::shared_ptr<TextManager>& textManager)
    : player(player), level(level), textManager(textManager)
{
}

void DebugManager::draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const
{
    renderTarget.setView(renderTarget.getDefaultView());
    textManager->drawText(debugTextValue, sf::Color::Green, 12, sf::Vector2f(25, 50));

    level.enableEntityTileHighlightsForDebug({
        {EntityType::PLAYER, sf::Color{0, 196, 128, 255}},
        {EntityType::ENEMY, sf::Color{255, 64, 128, 255}}
    });
}

void DebugManager::update(GameClock& gameClock)
{
    std::string fps = std::to_string(1.0f / debugClock.restart().asSeconds());
    const std::string& playerPosX = std::to_string(player->getPosition().x);
    const std::string& playerPosY = std::to_string(player->getPosition().y);
    const std::string& playerTileX = std::to_string(player->tilePosition.x);
    const std::string& playerTileY = std::to_string(player->tilePosition.y);
    const std::string& worldTimeSeconds = std::to_string(gameClock.getWorldTimeSeconds());

    debugTextValue =
            "fps: " + fps + "\n" +
            "window position (x, y): " + "(" + playerPosX + ", " + playerPosY + ")" + "\n" +
            "tile position (x, y): " + "(" + playerTileX + ", " + playerTileY + ")" + "\n" +
            "Game World Time (seconds): " + "(" + worldTimeSeconds + ")" + "\n";
}

void DebugManager::updateDebugState(GameState gameState)
{
    if (gameState.getState() == GameState::State::PLAYING)
    {
        gameState.updateState(GameState::State::DEBUG);
    }
    else
    {
        gameState.updateState(GameState::State::PLAYING);
        // Clear tiles of highlighting
        level.enableEntityTileHighlightsForDebug({
            {EntityType::PLAYER, sf::Color::White},
            {EntityType::ENEMY,  sf::Color::White}
        });
    }
}