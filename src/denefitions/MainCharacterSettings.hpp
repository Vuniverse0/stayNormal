#ifndef STAYNORMAL_MAINCHARACTERSETTINGS_HPP
#define STAYNORMAL_MAINCHARACTERSETTINGS_HPP

#include "CharacterSettings.hpp"

#define ANIMATIONS_NAME main_character_animations
#define CLASS_NAME Main_Character

#define SKIN_TYPE Main_Character_Skin
#define ANIMATION_TYPE Main_Character_Animation

#define CHARACTER_ANIMATIONS_LIST                                               \
ANIMATIONS_START_STAYNORMAL_CHARACTERSETTINGSUNDEFS(CLASS_NAME, ANIMATIONS_NAME) \
                                  \
    {"../resources/characters/main_character/phone-sheet.png", 14},     \
    {"../resources/characters/main_character/walk-sheet.png", 12},       \
    {"../resources/characters/main_character/phone_stay-sheet.png", 12},  \
    {"../resources/characters/main_character/stay-sheet.png", 12}          \
                                  \
ANIMATIONS_END_STAYNORMAL_CHARACTERSETTINGSUNDEFS

#define CHARACTER_ANIMATION(skin, animation)                            \
(TYPE_CHECK_STAYNORMAL_CHARACTERSETTINGSUNDEFS(skin, SKIN_TYPE),         \
TYPE_CHECK_STAYNORMAL_CHARACTERSETTINGSUNDEFS(animation, ANIMATION_TYPE), \
ANIMATION_CTOR_STAYNORMAL_CHARACTERSETTINGSUNDEFS(skin, animation))

#endif //STAYNORMAL_MAINCHARACTERSETTINGS_HPP
