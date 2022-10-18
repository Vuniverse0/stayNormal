#include "Entry.h"

#include "../utility/typedefs_and_tools.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>


Entry::Entry(const std::string& a_string, std::float_t x_ratio, std::float_t y_ratio, bool smooth)
{
    if ( a_string != EMPTY ) {
        m_object_texture.loadFromFile(a_string);
        m_object_texture.setSmooth(smooth);
        m_sprite.setTexture(m_object_texture);
        m_sprite.scale(ratio::x_ratio() * x_ratio, ratio::y_ratio() * y_ratio);
    }
}

Entry::Entry(const Entry& ent)
{
    m_object_texture = ent.m_object_texture;
    m_sprite = ent.m_sprite;
    m_sprite.setTexture(m_object_texture);
}

bool Entry::hide() ///return true if state was changed
{
    if ( m_visibility ) m_visibility = false;
    else return false;
    return true;
}

bool Entry::show() ///return true if state was changed
{
    if (!m_visibility) m_visibility = true;
    else return false;
    return true;
}

void Entry::draw(sf::RenderTarget &target, const sf::RenderStates &states) const
{
    if(m_visibility)
        target.draw(m_sprite);
    //std::cout << m_object_texture.getSize().x<<std::endl;
}

void Entry::setPosition(cords x, cords y)
{
    m_sprite.setPosition(x, y);
}

void Entry::setPositionWord(cords x, cords y)
{
    m_sprite.setPosition(
            static_cast<cords>(ratio::x_size()) * x,
            static_cast<cords>(ratio::y_size()) * y);
}

void Entry::move(cords x, cords y)
{
    m_sprite.move(x, y);
}

void Entry::moveWord(cords x, cords y)
{
    m_sprite.move(
            static_cast<cords>(ratio::x_size()) * x,
            static_cast<cords>(ratio::y_size()) * y);
}

sf::Rect<std::float_t> Entry::getGlobalBounds() const { return m_sprite.getGlobalBounds(); }

sf::Vector2f Entry::getOrigin() const { return m_sprite.getOrigin(); }

sf::Vector2f Entry::getScale() const { return m_sprite.getScale(); }

sf::Vector2f Entry::getPosition() const
{
    return m_sprite.getPosition();
}

sf::Vector2f Entry::getPositionWord() const
{
    return {static_cast<cords>(ratio::x_size()) / m_sprite.getPosition().x,
            static_cast<cords>(ratio::y_size()) / m_sprite.getPosition().y };
}

void Entry::scale(std::float_t x, std::float_t y)
{
    m_sprite.scale(x, y);
}

void Entry::update(sf::Time deltaTime)
{ assert(false); }

void Entry::handle(const sf::Event &event)
{ assert(false); }
