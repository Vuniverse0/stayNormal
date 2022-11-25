#ifndef STAYNORMAL_DIALOGUE_HPP
#define STAYNORMAL_DIALOGUE_HPP

#include "../primitives/Entry.hpp"
#include "../gamestates/DialogueState.hpp"


struct Dialogue : Entry{
    void update(sf::Time deltaTime) override;
    void handle(const sf::Event &event) override;

private:
    DialogueData m_dialogue_data;
    Game_State m_dialogue_state{DialogueHandle::Handle, m_dialogue_data};
};

#endif //STAYNORMAL_DIALOGUE_HPP
