#ifndef STAYNORMAL_WALK_STATE_HPP
#define STAYNORMAL_WALK_STATE_HPP

#include "Game_State.hpp"

#include "../interface/Directions.h"
#include "../primitives/Sprite.hpp"


struct WalkData : Game_State::Data {
    explicit WalkData(Sprite *a_entry, Direction a_view);
    Direction direction = Direction::None;
    Direction view;
    sf::Vector2i target;
    Sprite* entry;
    DATA_INDEX_DECL(WalkData);
};

struct WalkHandle : Game_State::Handle {
    USE_DATA(WalkData);
    void handle(const sf::Event &event, Data *data) override;
    void update(sf::Time deltaTime, Data *data) override;
    HANDLE_DECL(WalkHandle);

protected:
    WalkHandle() = default;
};

#endif //STAYNORMAL_WALK_STATE_HPP
