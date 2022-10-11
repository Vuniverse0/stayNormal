#include "Walk.hpp"

#include <cassert>
#include <iostream>


DATA_INDEX_IMPL(WalkData);

HANDLE_IMPL(WalkHandle);

WalkData::WalkData(Entry *a_entry, Direction a_view)
    :entry{a_entry}
    ,view{a_view}
{   Data::type = WalkData_type; }

void WalkHandle::handle(const sf::Event &event, Data *data)
{
    assert(event.type == sf::Event::MouseButtonReleased);
    assert(data);
    assert(data->type == WalkData::WalkData_type);

    WalkData *walkData{ reinterpret_cast<WalkData*>(data) };

    assert(walkData->entry);

    if(event.mouseButton.button == sf::Mouse::Right){
        walkData->target.x = event.mouseButton.x;
        walkData->target.y = event.mouseButton.y;
        std::float_t delta = walkData->entry->getPosition().x - static_cast<std::float_t>(walkData->target.x);
        if(delta > 0.f)
            walkData->direction = Direction::Left;
        else
            walkData->direction = Direction::Right;
        //std::cout<<"\nwalkData->entry->getPosition().x : "<<walkData->entry->getPosition().x<<std::endl;
        //std::cout<<"\nwalkData->target.x : "<<walkData->target.x<<std::endl;
    }
}

void WalkHandle::update(sf::Time deltaTime, Data *data)
{
    assert(data);
    assert(data->type == WalkData::WalkData_type);

    WalkData *walkData{ reinterpret_cast<WalkData*>(data) };

    assert(walkData->entry);

    ///TODO write switch make walk faster and draw other animations;
    if(walkData->direction != Direction::None)
        walkData->direction =
            std::abs(walkData->entry->getPosition().x - static_cast<std::float_t>(walkData->target.x)) < 10.f
            ? Direction::None : walkData->direction;
}

