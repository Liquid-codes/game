#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include "player_animation.h"

class Player
{
private:

    // Private Variiables
    int health;
    sf::Vector2f speed;

    std::string location;
    sf::Texture player_texture;
    sf::Sprite player;

    bool ani_switch;
    
    // Private functions
    void initVariables();
    void initPlayer();

public:
    
    std::string direction = "Front";
    std::string state = "IDLE";

    Player();

    // Public functions
    void playerMovement(sf::RenderWindow& window, sf::Sprite& background);
    sf::Sprite& getShape();
    sf::Vector2f& returnSpeed();

    void update(sf::RenderWindow& window, sf::Sprite& background);
    void render(sf::RenderWindow* window);
};
