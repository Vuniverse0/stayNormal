#include "Text.hpp"

#include <SFML/Graphics/RenderTarget.hpp>


void Text::draw(sf::RenderTarget &target, const sf::RenderStates &states) const
{ if(m_visibility) Entry::draw(target, states), target.draw(m_text, states); }

void Text::update(sf::Time deltaTime)
{

}

void Text::handle(const sf::Event &event)
{

}
