#pragma once

#include "../utility/typedefs_and_tools.h"

#include <SFML/Graphics/Texture.hpp>


struct Animation{
private:
    sf::Texture m_texture{};
    ///Alt_texture sets when animation play calls firstly, its current texture of sprite what passed.
    const sf::Texture* m_alt_texture{nullptr};
    frames m_i{0}, m_count;
    pixels m_size_x, m_size_y;
    float_t counter = 1.0f;
public:
    Animation(const std::string& a_sheet, pixels a_size_x, pixels a_size_y, frames a_count);
    Animation(Animation const& other) = default;
    Animation& operator=(const Animation& other) = default;
    ~Animation() = default;
    bool play(sf::Sprite* sprite,float_t speed = 1, bool direction = false);//return true when m_animation finish
    bool stop(sf::Sprite* sprite, bool setAlt );
    bool setAltTexture(sf::Sprite* sprite);
};