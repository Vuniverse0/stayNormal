#include "Game.hpp"

#include <iostream>

#include "Handler.hpp"


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
    if(!a_handler && !handler)
        std::cerr << "Game" << ": No Handler. Default Handler::gHandler" << std::endl;

    handler = a_handler ? a_handler : Handler::gHandler;

    if(!m_setup || a_handler){
        assert(word);///Game: no word;
        if(!word->handler)
            word->handler = handler;

        assert(gui);///Game: no gui;
        if (!gui->handler)
            gui->handler = handler;

        m_setup = true;
    }
}
