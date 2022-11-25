#ifndef STAYNORMAL_MAIN_CHARACTER_HPP
#define STAYNORMAL_MAIN_CHARACTER_HPP

#include "Character.hpp"

#include "../gamestates/Walk_State.hpp"


enum class Main_Character_Skin{Outside, Size, Error};
enum class Main_Character_Animation{Phone, Walk, Phone_Stay, Stay, Size, Error};

enum_default(Main_Character_Animation, Stay)
enum_default(Main_Character_Skin, Outside)

struct Main_Character : Character<Main_Character_Skin, Main_Character_Animation> {
    Main_Character();

    void update(sf::Time deltaTime) override;

    /// MouseButtonReleased
    void handle(const sf::Event& event) override;

    void flip();

private:
    WalkData m_walkData;
    Game_State m_walk_state{WalkHandle::Handle, m_walkData};
    Main_Character_Skin m_state;
    static Character_Files main_character_animations;
};

#endif //STAYNORMAL_MAIN_CHARACTER_HPP
