#include "Game.h"

#include "Handler.h"
#include "../primitives/Entry.h"

#include <iostream>
#include <cassert>


void Word::draw()
{
    assert(handler);///Word: No Handler

    assert(entries.begin());
    handler->draw(entries.begin(), entries.end(), states);
    ///states can be changed there↴
    ///handler->draw(what, states);
}

///TODO same as with ui but fix pass event filter
void Word::handle(const sf::Event &event)
{
    //for(auto item : entries) // item->handle(event);
    assert(MouseButtonReleased.begin());

    switch (event.type) {
        case sf::Event::MouseButtonReleased:
            for(auto it : MouseButtonReleased)
                it->handle(event);
            break;
        default:
            std::cerr << "Word Handle: wrong event passed" << std::endl;
            break;
    }
}

void Word::update(sf::Time deltaTime)
{
    assert(entries.begin());
    for(auto item : entries)
        item->update(deltaTime);
}
