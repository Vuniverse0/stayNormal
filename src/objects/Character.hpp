#pragma once

#include "../primitives/Sprite.h"
#include "../primitives/Animated.h"
#include "../gamestates/Game_State.hpp"


template<typename Skin_T, typename Animation_T>
struct Character : Entry{
protected:
    inline static constexpr std::size_t Animations_Size = static_cast<std::size_t>(Skin_T::Size);
    inline static constexpr std::size_t Animated_Size = static_cast<std::size_t>(Animation_T::Size);

public:
    Character(std::array<Animated<Animated_Size>,
              Animations_Size> animations,
              const std::string& a_string,
              float_t x_ratio = 1, float_t y_ratio = 1,
              Game_State *game_state = nullptr)
        :Entry(a_string, x_ratio, y_ratio)
        ,m_animations{animations}
        ,m_game_state{game_state}
    {}
    void update(sf::Time deltaTime) override;
    void handle(const sf::Event& event) override;
    ~Character() override = default;

protected:
    Game_State *m_game_state;
    Skin_T m_skin = enum_default<Skin_T>();
    Animation_T m_current_animation = enum_default<Animation_T>();
    std::array<Animated<Animated_Size>, Animations_Size> m_animations;
};

template<typename Skin_T, typename Animation_T>
void Character<Skin_T, Animation_T>::update(sf::Time deltaTime)
{
    assert(m_skin != Skin_T::Size && m_skin != Skin_T::Error);
    assert(m_current_animation != Animation_T::Size && m_current_animation != Animation_T::Error);

    if(m_game_state)
        (*m_game_state)(deltaTime);

    m_animations[static_cast<std::size_t>(m_skin)].play(
            static_cast<std::size_t>(m_current_animation),
            10.f * deltaTime.asSeconds());
}

template<typename Skin_T, typename Animation_T>
void Character<Skin_T, Animation_T>::handle(const sf::Event &event)
{
    if(m_game_state)
        (*m_game_state)(event);
}