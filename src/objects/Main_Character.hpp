#ifndef STAYNORMAL_MAIN_CHARACTER_HPP
#define STAYNORMAL_MAIN_CHARACTER_HPP

#include "Character.hpp"

#include "../gamestates/Walk_State.hpp"

#define MAIN_CHARACTER_ANIMATIONS \
Main_Character::Character_Files Main_Character::main_character_animations{{std::pair\
    {"../resources/characters/main_character/phone-sheet.png", 14},\
    {"../resources/characters/main_character/walk-sheet.png", 12},\
    {"../resources/characters/main_character/phone_stay-sheet.png", 12},\
    {"../resources/characters/main_character/stay-sheet.png", 12}\
}}


enum class Main_Character_Skin{Outside, Size, Error};
enum class Main_Character_Animation{Phone, Walk, Phone_Stay, Stay, Size, Error};//TODO draw Stay today

enum_default(Main_Character_Animation, Phone)
enum_default(Main_Character_Skin, Outside)

struct Main_Character : Character<Main_Character_Skin, Main_Character_Animation> {
   explicit Main_Character(Main_Character_Skin a_state = enum_default<Main_Character_Skin>());

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
