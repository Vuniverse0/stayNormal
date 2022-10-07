#include "Panel.h"
#include "../core/Handler.h"


void Panel::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    if ( !m_visibility )
        return;
    target.draw(m_sprite, states);
    for (auto it : m_buttons)
        it->draw(target, states);
}

void Panel::update(sf::Time deltaTime)
{
    for(auto it : m_buttons)
        it->update(deltaTime);
}

void Panel::handle(const sf::Event& event)
{
    for(auto it : m_buttons)
        it->handle(event);
}

Panel::Panel(Range<iterator_type> a_group, const std::string &a_sprite,
             std::float_t x_ratio, std::float_t y_ratio, bool smooth)
    :Gui(a_sprite, x_ratio, y_ratio, smooth)
    ,m_buttons{a_group}
{
    m_sprite.setPosition(Corner::ship(Anchor::CenterLeft, m_sprite));
    Place::group<Vertical>(
            {m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width / 2.f,
             m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height/2.f},
            15.f * ratio::valuable_ratio(), m_buttons);
}
