#include "Sprite.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


Sprite::Sprite(const std::string& a_string, std::float_t x_ratio, std::float_t y_ratio, bool smooth)
{
    if ( a_string != EMPTY ) {
        m_object_texture.loadFromFile(a_string);
        m_object_texture.setSmooth(smooth);
        m_sprite.setTexture(m_object_texture);
        m_sprite.scale(ratio::x_ratio() * x_ratio, ratio::y_ratio() * y_ratio);
    }
}

void Sprite::setPosition(cords x, cords y)
{ m_sprite.setPosition(x, y); }

void Sprite::setPositionWord(cords x, cords y)
{
    m_sprite.setPosition(//Todo review this question
            static_cast<cords>(ratio::x_size()) * x,
            static_cast<cords>(ratio::y_size()) * y);
}

void Sprite::move(cords x, cords y)
{ m_sprite.move(x, y); }

void Sprite::moveWord(cords x, cords y)
{ m_sprite.move(static_cast<cords>(ratio::x_size()) * x, static_cast<cords>(ratio::y_size()) * y); }

sf::Rect<std::float_t> Sprite::getGlobalBounds() const
{ return m_sprite.getGlobalBounds(); }

sf::Vector2f Sprite::getOrigin() const
{ return m_sprite.getOrigin(); }

sf::Vector2f Sprite::getScale() const
{ return m_sprite.getScale(); }

sf::Vector2f Sprite::getPosition() const
{ return m_sprite.getPosition(); }

sf::Vector2f Sprite::getPositionWord() const
{
    return{
        static_cast<cords>(ratio::x_size()) / m_sprite.getPosition().x,
        static_cast<cords>(ratio::y_size()) / m_sprite.getPosition().y};
}

void Sprite::scale(std::float_t x, std::float_t y)
{ m_sprite.scale(x, y); }

void Sprite::m_draw(sf::RenderTarget &target, const sf::RenderStates &states) const
{ target.draw(m_sprite, states); }
