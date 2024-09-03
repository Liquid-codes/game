#include "player.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

// Initalizing the variables
void Player::initVariables()
{
    this->health =3.;
    this->speed = sf::Vector2f(0, 0);
    this->location = "/home/max/Desktop/projects/game/assets/player/player_front_idle.png";
}

// Initaliizinig the player
void Player::initPlayer()
{
    this->player_texture.loadFromFile(this->location, sf::IntRect(0, 0, 64, 64));
    this->player.setTexture(this->player_texture);
    this->player.setScale(2.f, 2.f);
    this->player.setPosition(sf::Vector2f(908.f, 718.f));
}

// Calls on run
Player::Player()
{
    this->initVariables();
    this->initPlayer();
}

// Handling player movement
void Player::playerMovement(sf::RenderWindow& window, sf::Sprite& background)
{
    bool isMoving = false;

    // LEFT, RIGHT, UP, DOWN
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        state = "WALK";
        direction = "Left";
        isMoving = true;

        this->speed.x = (isMoving && background.getPosition().x < 0.f) ? 3.f : 0.f;
        this->player.move((this->speed.x == 3.f) ? -.5f : -3.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        state = "WALK";
        direction = "Right";
        isMoving = true;

        this->speed.x = (isMoving && background.getPosition().x > -1437.f) ? -3.f : 0.f;
        this->player.move((this->speed.x == -3.f) ? .5f : 3.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        state = "WALK";
        direction = "Back"; 
        isMoving = true;

        this->speed.y = (isMoving && background.getPosition().y < 0.f) ? 3.f : 0.f;
        this->player.move(0.f, (this->speed.y == 3.f) ? -0.5f : -3.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        state = "WALK";
        direction = "Front";
        isMoving = true;

        this->speed.y = (isMoving && background.getPosition().y > -1800.f) ? -3.f : 0.f;
        this->player.move(0.f, (this->speed.y == -3.f) ? 0.5f : 3.f);
    }

    if (!isMoving)
    {
        state = "IDLE";
        this->speed = sf::Vector2f(0.f, 0.f);
    }
}

// PlayerCollision with the barrier blocks
// Implement later

// Returns
sf::Sprite& Player::getShape()
{
    return this->player;
}

sf::Vector2f& Player::returnSpeed()
{
    return this->speed;
}

// Constanly updates player
void Player::update(sf::RenderWindow& window, sf::Sprite& background)
{
    this->playerMovement(window, background);
}

// Renders player on the screen
void Player::render(sf::RenderWindow* window)
{
    window->draw(this->player);
}
