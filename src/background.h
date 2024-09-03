#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include "player.h"

class Background
{
private:

    // Private variables
    sf::Texture image;
    sf::Sprite background;
    std::string image_location;
    float max_X;
    float max_Y;

    // Private functions
    void initVariables();
    void initBackground();

public:
    bool move;
    
    Background();

    // Public functions
    sf::Sprite& attributes();

    void update(Player& player);
    void render(sf::RenderWindow* window);
};
