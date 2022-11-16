#ifndef STAYNORMAL_SPRITE_HPP
#define STAYNORMAL_SPRITE_HPP

#include <cmath>
#include <string>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Entry.hpp"

#include "../utility/typedefs_and_tools.h"


struct Sprite : virtual Entry{

    explicit Sprite(const std::string& a_string, cords x_ratio = 1, cords y_ratio = 1, bool smooth = false);

    void scale(cords x, cords y);
    virtual void move(cords x, cords y);
    void moveWord(cords x, cords y);
    void setPosition(cords x, cords y);
    void setPositionWord(cords x, cords y);
    sf::Rect<std::float_t> getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getPositionWord() const;
    sf::Vector2f getScale() const;
    sf::Vector2f getOrigin() const;

protected:
    void m_draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    sf::Sprite m_sprite{};
    sf::Texture m_object_texture{};
};


#endif //STAYNORMAL_SPRITE_HPP
