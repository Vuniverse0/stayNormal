#pragma once

#include "../primitives/Sprite.hpp"
#include "../primitives/Animated.h"
#include "../gamestates/Game_State.hpp"


template<size_t Skin, size_t Anim>
using Files = std::array<const std::array<std::pair<const std::string, const frames>, Anim>, Skin>;

template<typename Skin_T, typename Animation_T>
struct Character : Sprite {
protected:
    inline static constexpr std::size_t Skins_Size = static_cast<std::size_t>(Skin_T::Size);
    inline static constexpr std::size_t Animations_Size = static_cast<std::size_t>(Animation_T::Size);
    using Character_Files = Files<Skins_Size, Animations_Size>;
public:
    Character(std::array<Animated<Animations_Size>, Skins_Size> animations,
              Sprite entry, Game_State *game_state = nullptr)
        :Sprite(entry)
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
    std::array<Animated<Animations_Size>, Skins_Size> m_animations;
};

template<typename Skin_T, typename Animation_T>
void Character<Skin_T, Animation_T>::update(sf::Time deltaTime)
{
    assert(m_skin != Skin_T::Size);
    assert(m_skin != Skin_T::Error);
    assert(m_current_animation != Animation_T::Size);
    assert(m_current_animation != Animation_T::Error);

    if(m_game_state)
        (*m_game_state)(deltaTime);

    m_animations[static_cast<std::size_t>(m_skin)].play(
            static_cast<std::size_t>(m_current_animation),
            10.f * deltaTime.asSeconds());
    //std::cout<<"Anim:"<<static_cast<std::size_t>(m_current_animation)<<std::endl;
}

template<typename Skin_T, typename Animation_T>
void Character<Skin_T, Animation_T>::handle(const sf::Event &event)
{
    if(m_game_state)
        (*m_game_state)(event);
}
