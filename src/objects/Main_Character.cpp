#include "Main_Character.hpp"

#include <iostream>


Main_Character::Character_Files Main_Character::main_character_animations{
    {///Outside
        std::pair
        {"../resources/characters/main_character/phone-sheet.png", 14},
        {"../resources/characters/main_character/walk-sheet.png", 12},
        {"../resources/characters/main_character/phone_stay-sheet.png", 12}
    }
};

#define MAIN_CHARACTER_HEIGHT 112
#define MAIN_CHARACTER_WIDTH 50

#define MAIN_CHARACTER_ANIMATION(skin, animation)\
Animation{\
main_character_animations[static_cast<std::size_t>(skin)][static_cast<std::size_t>(animation)].first,\
MAIN_CHARACTER_WIDTH, MAIN_CHARACTER_HEIGHT,     \
main_character_animations[static_cast<std::size_t>(skin)][static_cast<std::size_t>(animation)].second\
}



Main_Character::Main_Character(Main_Character_Skin a_state)
    :Character(
        std::array<Animated<Animations_Size>, Skins_Size>{
            Animated<Animations_Size>{
                &m_sprite,

                MAIN_CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Phone),
                MAIN_CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Walk),
                MAIN_CHARACTER_ANIMATION(Main_Character_Skin::Outside, Main_Character_Animation::Phone_Stay)
            }
        },
        Entry{
            "../resources/characters/main_character/main_character1.png",//todo make empty
            1, 1
        },
        &m_walk_state
    )
    ,m_state{a_state}
    ,m_walkData{this, Direction::Right}
{
    m_skin = m_state;
    m_sprite.setOrigin(local_center(&m_sprite));
}

void Main_Character::flip()
{
    m_sprite.scale(-1.f, 1.f);
}

void Main_Character::update(sf::Time deltaTime)
{
    Character::update(deltaTime);
    if(m_walkData.direction != Direction::None){
        m_current_animation = Main_Character_Animation::Walk;
        if (m_walkData.view != m_walkData.direction)
            m_walkData.view = m_walkData.direction, flip();

        if (m_walkData.direction == Direction::Right)
            Entry::m_sprite.move(100 * deltaTime.asSeconds(), 0);
        else
            Entry::m_sprite.move(-100 * deltaTime.asSeconds(), 0), assert(m_walkData.direction == Direction::Left);
    }else if(m_current_animation == Main_Character_Animation::Walk){
        m_animations[static_cast<std::size_t>(m_skin)].stop(static_cast<std::size_t>(m_current_animation));
        m_current_animation = Main_Character_Animation::Phone; //WRITE THERE
    }
}

void Main_Character::handle(const sf::Event &event)
{
    Character::handle(event);
}
