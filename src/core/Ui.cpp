#include "Game.h"

#include "Handler.h"
#include "../interface/Panel.h"

#include <iostream>


void Ui::draw()
{
    assert(handler);///Ui: No Handler

    if(uiChanged) {///states can be changed there↴ handler->draw(what, ui_states);
        uiChanged = false;
        assert(gui.begin());
        handler->draw_ui(gui.begin(), gui.end(), states);
    }
}

void Ui::update()
{
    uiChanged = true;
}

///TODO add comment what events accepts
void Ui::handle(const sf::Event& event)
{
    assert(MouseButtonReleased.begin());
    assert(MouseMoved.begin());

    switch (event.type) {
        case sf::Event::MouseButtonReleased:
            for(auto it : MouseButtonReleased)
                it->handle(event);
        case sf::Event::MouseMoved:
            for(auto it : MouseMoved)
                it->handle(event);
            break;
        default:
            std::cerr << "Ui Handle: wrong event passed" << std::endl;
            break;
    }
}

void Ui::update(sf::Time deltaTime)
{
    assert(gui.begin());
    for(auto it : gui)
        it->update(deltaTime);
}
