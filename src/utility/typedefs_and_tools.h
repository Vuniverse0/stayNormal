#pragma once

#include <cstdint>
#include <cmath>
#include <cassert>

#include <SFML/Graphics/Sprite.hpp>


#define GAME_MAKER_SCREEN_WIDTH 1366.0f //TODO remake these maybe
#define GAME_MAKER_SCREEN_HEIGHT 768.0f
#define DEFAULT_FPS 60
#define EMPTY "null.png"


typedef std::uint16_t frames;
typedef std::uint16_t pixels;
typedef std::float_t cords;


namespace ratio {
    cords valuable_ratio();

    cords x_ratio();
    cords y_ratio();

    pixels x_size();
    pixels y_size();
}

//std::float_t binominal_float(std::float_t a_start, std::float_t a_end, std::float_t a_binominal);

//std::uint8_t binominal_int(std::uint8_t a_start, std::uint8_t a_end, std::float_t a_binominal);

sf::FloatRect size_regulator(const sf::Sprite * sprite);

//special tool TODO: move this
void scale_by_mouse(sf::Sprite * sprite, bool focus);
    
//for code trigger - anchors(center of sprite on globals)
sf::Vector2f center(const sf::Sprite * sprite);

//for local center
sf::Vector2f local_center (const sf::Sprite * sprite);

//for global center
sf::Vector2f global_half(const sf::Sprite * sprite);

//window center from size of window
sf::Vector2f window_center(sf::Vector2u size);

bool isLess(const sf::Vector2f &a_left, const sf::Vector2f &a_right);

template<typename T>
T enum_default()
{ assert(false); }

#define enum_default(enum_name, that) \
template<> \
inline enum_name enum_default<enum_name>() \
{ return enum_name::that; }
