#ifndef STAYNORMAL_DIALOGUE_STATE_HPP
#define STAYNORMAL_DIALOGUE_STATE_HPP

#include <SFML/Graphics/Text.hpp>

#include "Game_State.hpp"
#include "../objects/Phrase.hpp"


struct DialogueData : Game_State::Data {
    enum class DialogueState{None, Talking, Waiting, Done, Size, Error} state {DialogueState::None};

    DATA_INDEX_DECL(Dialogue);

    sf::Text text;
    Phrase *phrase{nullptr};
};

struct DialogueHandle : Game_State::Handle {
    USE_DATA(DialogueData);
    void handle(const sf::Event &event, Data *data) override;
    void update(sf::Time deltaTime, Data *data) override;
    HANDLE_DECL(DialogueHandle);
protected:
    DialogueHandle() = default;
};

#endif //STAYNORMAL_DIALOGUE_STATE_HPP
