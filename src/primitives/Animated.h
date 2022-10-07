#pragma once

#include "Animation.h"


template<std::size_t N>
class Animated {
    std::array<Animation, N> m_animations;
    sf::Sprite* m_p_sprite;
public:
    Animated(sf::Sprite* sprite, std::array<Animation, N> init)
        :m_animations{init}
        ,m_p_sprite{sprite}
    {}
    bool play(std::size_t index = 0, float_t speed = 1, bool direction = false);//return true when m_animation finish
    bool stop(std::size_t index, bool setAlt  = true );
};


template<std::size_t N>
bool Animated<N>::play(std::size_t index, float_t speed, bool direction)
{
    return m_animations[index].play(m_p_sprite, speed, direction);
}

template<std::size_t N>
bool Animated<N>::stop(std::size_t index, bool setAlt)
{
    return m_animations[index].stop(m_p_sprite, setAlt);
}
