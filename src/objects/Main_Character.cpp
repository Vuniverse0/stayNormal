#include "Main_Character.hpp"


Main_Character::Main_Character(Main_Character_Skin a_state)
    :Character(
        std::array<Animated<Character::Animated_Size>, Character::Animations_Size>{
            Animated{
                &(Entry::m_sprite),
                std::array<Animation, Character::Animated_Size>{
                    Animation{
                        "../resources/characters/main_character/main_character.png",
                        50, 112, 12,
                    }
                }
            }
        },
        "../resources/characters/main_character/main_character1.png",
        1, 1, &m_walk_state
    )
    ,m_state{a_state}
    ,m_walkData{this, Direction::Right}
{
    m_skin = m_state;
    m_current_animation = Main_Character_Animation::Walk; //TODO remove;
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
        if (m_walkData.view != m_walkData.direction)
            m_walkData.view = m_walkData.direction, flip();
        if (m_walkData.direction == Direction::Right)
            Entry::m_sprite.move(100 * deltaTime.asSeconds(), 0);
        else
            Entry::m_sprite.move(-100 * deltaTime.asSeconds(), 0), assert(m_walkData.direction == Direction::Left);
    }else if(m_current_animation == Main_Character_Animation::Walk)
        m_current_animation;
}

void Main_Character::handle(const sf::Event &event)
{
    Character::handle(event);
}
