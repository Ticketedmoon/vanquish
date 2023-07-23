#include "../include/player.h"
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdint>

Player::Player()
{
    if (!texture.loadFromFile("resources/assets/character_sprite_sheet_v2.png"))
    {
        std::cout << "Failed to load character sprite sheet" << std::endl;
    }
    texture.setSmooth(true);

    playerPos = sf::Vector2f(0.0f, 0.0f);
    rectSourceSprite = sf::IntRect(0, 0, SPRITE_SHEET_X, SPRITE_SHEET_Y);
    playerDir = PlayerDirection::DOWN;
    playerSprite = sf::Sprite(texture, rectSourceSprite);
}

void Player::update()
{
    uint32_t tileUnderPlayerX = round(playerPos.x/SPRITE_SHEET_X);
    uint32_t tileUnderPlayerY = round(playerPos.y/SPRITE_SHEET_Y);

    tilePosition = sf::Vector2u(tileUnderPlayerX, tileUnderPlayerY);
    playerSprite.setPosition(playerPos);
    playerSprite.setTextureRect(rectSourceSprite);
}

void Player::updatePlayerPosition(uint32_t levelWidth, uint32_t levelHeight)
{
    sf::Vector2f acceleration;

    // adjust this at will
    const float dAcc = 1.5f;

    if (playerDir == PlayerDirection::UP)
    {
        acceleration.y -= dAcc;
    }
    if (playerDir == PlayerDirection::DOWN)
    {
        acceleration.y += dAcc;
    }
    if (playerDir == PlayerDirection::LEFT)
    {
        acceleration.x -= dAcc;
    }
    if (playerDir == PlayerDirection::RIGHT) 
    {
        acceleration.x += dAcc;
    }

    // update velocity through acceleration
    velocity += acceleration;

    // TODO REFACTOR ME CAN WE USE tilePosition?
    uint32_t tileMapWidth = ((levelWidth-1) * SPRITE_SHEET_X);
    uint32_t tileMapHeight = ((levelHeight-1) * SPRITE_SHEET_Y);

    if ((playerPos.x+velocity.x >= 0) && (playerPos.x+velocity.x < tileMapWidth))
    {
        //std::cout << "yo: " << playerPos.x << ", " << velocity.x << std::endl;
        playerPos.x += velocity.x;
        velocity.x = 0.5f * velocity.x;
    }
    else 
    {
        velocity.x = 0;
    }


    if ((playerPos.y+velocity.y >= 0) && (playerPos.y+velocity.y <= tileMapHeight))
    {
        playerPos.y += velocity.y;
        velocity.y = 0.5f * velocity.y;
    }
    else
    {
        velocity.y = 0;
    }

}

void Player::updateAnimation(sf::Clock& clock, uint32_t spriteSheetTopOffset, PlayerDirection newDirection)
{
    sf::Time currentTime = clock.getElapsedTime();
    if (currentTime - animationFrameStartTime >= animationFrameDuration)
    {
        rectSourceSprite.top = SPRITE_SHEET_X * spriteSheetTopOffset;
        if (rectSourceSprite.left == LAST_SPRITE_LEFT_POS)
        {
            rectSourceSprite.left = 0;
        }
        else
        {
            rectSourceSprite.left += SPRITE_SHEET_X;
        }

        animationFrameStartTime = currentTime;
    }
    playerDir = newDirection;
}

sf::Vector2f Player::getPlayerPos()
{
    return playerPos;
}

PlayerDirection Player::getPlayerDir()
{
    return playerDir;
}

sf::Sprite Player::getSprite()
{
    return playerSprite;
}
