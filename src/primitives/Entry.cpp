#include "Entry.h"

#include <SFML/Graphics/RenderTarget.hpp>


bool Entry::hide() ///return true if state was changed
{
    if(m_visibility)
        m_visibility = false;
    else
        return false;
    return true;
}

bool Entry::show() ///return true if state was changed
{
    if(!m_visibility)
        m_visibility = true;
    else
        return false;
    return true;
}

void Entry::draw(sf::RenderTarget &target, const sf::RenderStates &states) const
{
    if(m_visibility)
        m_draw(target, states);
}

void Entry::update(sf::Time deltaTime)
{ assert(false); }

void Entry::handle(const sf::Event &event)
{ assert(false); }

void Entry::m_draw(sf::RenderTarget &target, const sf::RenderStates &states) const
{ assert(false); }
