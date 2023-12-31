#include "user_interface/experience_points_bar.h"

ExperiencePointsBar::ExperiencePointsBar(const std::shared_ptr<Player>& player, sf::Vector2f fillDimensions,
        sf::Vector2f backgroundDimensions, sf::Vector2f position,
        sf::Color fillColor, sf::Color outlineColour, float outlineThickness)
        : m_player(player)
{
    experienceBarBackground = sf::RectangleShape(backgroundDimensions);
    experienceBarBackground.setPosition(position);
    experienceBarBackground.setFillColor(sf::Color::Black);
    experienceBarBackground.setOutlineColor(outlineColour);
    experienceBarBackground.setOutlineThickness(outlineThickness);

    experienceBar = sf::RectangleShape(fillDimensions);
    experienceBar.setPosition(position);
    experienceBar.setFillColor(fillColor);
    experienceBar.setOutlineColor(outlineColour);
    experienceBar.setOutlineThickness(outlineThickness);
}

void ExperiencePointsBar::update(GameState& gameState)
{
    sf::Vector2f newFillBarSize = sf::Vector2f(m_player->getTotalExperiencePoints(), experienceBar.getSize().y);
    experienceBar.setSize(newFillBarSize);
}

void ExperiencePointsBar::draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const
{
    renderTarget.draw(experienceBarBackground);
    renderTarget.draw(experienceBar);
}
