#include "player_animation.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>


// Initialzing variables
void AniControl::initVariables()
{
    this->texture_idle = {
        "../assets/player/front/player_front_idle.png",
        "../assets/player/back/player_back_idle.png",
        "../assets/player/side/player_left_idle.png",
        "../assets/player/side/player_right_idle.png"
    };

    this->texture_walk = {
        "../assets/player/front/player_front_walk.png",
        "../assets/player/back/player_back_walk.png",
        "../assets/player/side/player_left_walk.png",
        "../assets/player/side/player_right_walk.png"
    };

    this->player_texture.loadFromFile(this->texture_idle[0]);
    this->texture_rect = sf::IntRect(0, 0, 64, 64);
}

AniControl::AniControl()
{
    this->initVariables();
    this->timerReset();
}

/* 
 * front = 0;
 * back = 1;
 * left = 2;
 * side = 3;
*/

// Changes player image
void AniControl::updateTexture(std::string& direction, std::string& state)
{
    if (direction == "Front")
    {
        if (state == "IDLE")
        {
            this->player_texture.loadFromFile(this->texture_idle[0]);
        }
        if (state == "WALK")
        {
            this->player_texture.loadFromFile(this->texture_walk[0]);
        }
    }

    if (direction == "Back")
    {
        if (state == "IDLE")
        {
            this->player_texture.loadFromFile(this->texture_idle[1]);
        }
        if (state == "WALK")
        {
            this->player_texture.loadFromFile(this->texture_walk[1]);
        }
    }

    if (direction == "Left")
    {
        if (state == "IDLE")
        {
            this->player_texture.loadFromFile(this->texture_idle[2]);
        }
        if (state == "WALK")
        {
            this->player_texture.loadFromFile(this->texture_walk[2]);
        }
    }

    if (direction == "Right")
    {
        if (state == "IDLE")
        {
            this->player_texture.loadFromFile(this->texture_idle[3]);
        }
        if (state == "WALK")
        {
            this->player_texture.loadFromFile(this->texture_walk[3]);
        }
    }
}

// Updates animation
void AniControl::updateAnimation(std::string& state, sf::Sprite& player)
{
    // Updates frame ever 0.1 seconds
    if (this->clock.getElapsedTime().asSeconds() >= 0.1f)
    {
        // Switching state
        if (state == "IDLE")
        {
            this->texture_rect.left += 64.f;
            if (this->texture_rect.left > 704.f)
            {
                this->texture_rect.left = 0.f;
            }

            player.setTexture(this->player_texture);
            player.setTextureRect(this->texture_rect);
        }

        if (state == "WALK")
        {
            this->texture_rect.left += 64.f;
            if (this->texture_rect.left > 320.f)
            {
                this->texture_rect.left = 0.f;
            }
            
            player.setTexture(this->player_texture);
            player.setTextureRect(this->texture_rect);
        }

        // reseting the timer
        this->timerReset();
    }
}

// Reset
void AniControl::timerReset()
{
    this->clock.restart();
}

// Update 
void AniControl::update(std::string& state, std::string& direction, sf::Sprite& player)
{
    this->updateTexture(direction, state);
    this->updateAnimation(state, player);
}