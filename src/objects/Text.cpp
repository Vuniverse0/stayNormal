#include "Text.hpp"

#include <SFML/Graphics/RenderTarget.hpp>


void Text::update(sf::Time deltaTime)
{

}

void Text::handle(const sf::Event &event)
{

}

void Text::m_draw(sf::RenderTarget &target, const sf::RenderStates &states) const
{
    target.draw(m_text, states);
}
