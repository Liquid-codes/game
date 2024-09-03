#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

//Created by me
#include "player.h"
#include "collider.h"
#include "background.h"
#include "player_animation.h"

class Game
{
private:

    // Private variables
    sf::RenderWindow* window;
    sf::Event ev;
    sf::View viewport;

    // Private functions
    void initVariables();
    void initWindow();

    // Classes
    Player player;
    Collider collider;
    Background background_image;
    AniControl ani_control;

public:
    Game();
    virtual ~Game();

    // Public functions
    const bool isRunning() const;

    void pollEvents();

    void update();
    void render();
};
