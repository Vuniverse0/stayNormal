#ifndef STAYNORMAL_WALK_HPP
#define STAYNORMAL_WALK_HPP

#include "Game_State.hpp"

#include "../primitives/Entry.h"
#include "../interface/Directions.h"


struct WalkData : Data {
    explicit WalkData(Entry *a_entry, Direction a_view);
    Direction direction = Direction::None;
    Direction view;
    sf::Vector2i target;
    Entry* entry;

    static const std::size_t WalkData_type;
};

struct WalkHandle : Handle {
    void handle(const sf::Event &event, Data *data) override;
    void update(sf::Time deltaTime, Data *data) override;
    static WalkHandle Handle;
protected:
    WalkHandle() = default;
};


#endif //STAYNORMAL_WALK_HPP
