#ifndef STAYNORMAL_PHONE_STATE_HPP
#define STAYNORMAL_PHONE_STATE_HPP

#include "Game_State.hpp"


struct PhoneData : Game_State::Data {
    enum class PhoneState{None, Taking, Talking, Putting, Size, Error} state{PhoneState::None};
    DATA_INDEX_DECL(PhoneData);///TODO
};

struct PhoneHandle : Game_State::Handle {
    USE_DATA(PhoneData);
    void handle(const sf::Event &event, Data *data) override;
    void update(sf::Time deltaTime, Data *data) override;
    HANDLE_DECL(PhoneHandle);

protected:
    PhoneHandle() = default;
};

#endif //STAYNORMAL_PHONE_STATE_HPP
