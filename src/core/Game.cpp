#include "Game.h"

#include "Handler.h"

#include <iostream>


void Game::draw()
{
    if ( !m_setup )
        abort();
    word->draw();
    gui->draw();
}

void Game::handle(const sf::Event &event)
{
    if(
       event.type == sf::Event::MouseButtonReleased
                  or
       event.type == sf::Event::MouseMoved
       )
        gui->handle(event);
    if(
       event.type == sf::Event::MouseButtonReleased
       //           or
       //event.type == sf::Event::KeyReleased
       )
        word->handle(event);
    //TODO rewrite to case here
}

void Game::update(sf::Time deltaTime) const
{
    gui->update(deltaTime);
    word->update(deltaTime);
}

void Game::setup( Handler* a_handler )
{
    if ( !a_handler && !handler )
        std::cerr << "Game" << ": No Handler. Default Handler::gHandler" << std::endl;

    handler = a_handler ? a_handler : Handler::gHandler;

    if (!m_setup || a_handler) {
        if(!word)
            std::cerr<<"Game: no word" << std::endl;
        if(!word->handler)
            word->handler = handler;
        if(!gui)
            std::cerr<<"Game: no gui" << std::endl;
        if (!gui->handler)
            gui->handler = handler;
        m_setup = true;
    }
}
