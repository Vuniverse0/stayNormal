#ifndef STAYNORMAL_MAIN_CHARACTER_HPP
#define STAYNORMAL_MAIN_CHARACTER_HPP

#include "Character.hpp"

#include "../gamestates/Walk.hpp"


enum class Main_Character_Skin{Outside, Size, Error};
enum class Main_Character_Animation{Walk, Size, Error};//TODO draw Stay today

enum_default(Main_Character_Animation, Walk)
enum_default(Main_Character_Skin, Outside)

struct Main_Character : Character<Main_Character_Skin, Main_Character_Animation> {
   explicit Main_Character(Main_Character_Skin a_state);

    void update(sf::Time deltaTime) override;

    /// MouseButtonReleased
    void handle(const sf::Event& event) override;

    void flip();

private:
    WalkData m_walkData;
    Game_State m_walk_state{WalkHandle::Handle, m_walkData};
    Main_Character_Skin m_state;
};

#endif //STAYNORMAL_MAIN_CHARACTER_HPP
