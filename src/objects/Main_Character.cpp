#include "Main_Character.hpp"

#include <iostream>

#include "../denefitions/MainCharacterSettings.hpp"


CHARACTER_ANIMATIONS_LIST;


Main_Character::Main_Character()
    :Character(
        std::array<Animated<Animations_Size>, Skins_Size>{
            Animated<Animations_Size>{
                    &m_sprite,
                    CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Phone),
                    CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Walk),
                    CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Phone_Stay),
                    CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Stay)
            }
        },
        Sprite{
            "../resources/characters/main_character/main_character1.png",//todo make empty
        },
        &m_walk_state
    )
    ,m_walkData{this, Direction::Right}
{
    m_sprite.setOrigin(local_center(&m_sprite));
}

void Main_Character::flip()
{ m_sprite.scale(-1.f, 1.f); }

void Main_Character::update(sf::Time deltaTime)
{
    Character::update(deltaTime);
    if(m_walkData.direction != Direction::None){
        m_current_animation = Main_Character_Animation::Walk;
        if (m_walkData.view != m_walkData.direction)
            m_walkData.view = m_walkData.direction, flip();

        if (m_walkData.direction == Direction::Right)
            move(100 * deltaTime.asSeconds(), 0);
        else
            move(-100 * deltaTime.asSeconds(), 0), assert(m_walkData.direction == Direction::Left);
    }else if(m_current_animation == Main_Character_Animation::Walk){
        m_animations[static_cast<std::size_t>(m_skin)].stop(static_cast<std::size_t>(m_current_animation));
        m_current_animation = Main_Character_Animation::Stay; //WRITE THERE
    }
}

void Main_Character::handle(const sf::Event &event)
{
    Character::handle(event);
}
