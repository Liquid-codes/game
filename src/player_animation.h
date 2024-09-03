#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

class AniControl
{
private:

    sf::Clock clock;
    sf::Texture player_texture;
    std::string location;
    sf::IntRect texture_rect;
    std::vector<std::string> texture_idle;
    std::vector<std::string> texture_walk;
    
    void initVariables();

public:

    AniControl();

    void updateTexture(std::string& direction, std::string& state);
    void updateAnimation(std::string& state, sf::Sprite& player);
    void update(std::string& state, std::string& direction, sf::Sprite& player);
    void timerReset();
};
