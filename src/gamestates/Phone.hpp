#ifndef STAYNORMAL_PHONE_HPP
#define STAYNORMAL_PHONE_HPP

#include "Game_State.hpp"


enum class PhoneState{Taking, Talking, Putting, Size, Error};

struct PhoneData : Data {
    Direction direction = Direction::None;
    Direction view;
    sf::Vector2i target;
    Entry* entry;

    DATA_INDEX_DECL(PhoneData);
};

struct PhoneHandle : Handle {
    void handle(const sf::Event &event, Data *data) override;
    void update(sf::Time deltaTime, Data *data) override;
    static WalkHandle Handle;
protected:
    WalkHandle() = default;
};

#endif //STAYNORMAL_PHONE_HPP
