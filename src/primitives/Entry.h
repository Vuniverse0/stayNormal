#pragma once

#include "../utility/typedefs_and_tools.h"

#include <cmath>
#include <string>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>


struct Entry {
    //explicit Entry(const std::string& a_string, cords x_ratio = 1, cords y_ratio = 1, bool smooth = false);
    virtual ~Entry() = default;

    /*void scale(cords x, cords y);
    virtual void move(cords x, cords y);
    void moveWord(cords x, cords y);
    void setPosition(cords x, cords y);
    void setPositionWord(cords x, cords y);
    sf::Rect<std::float_t> getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getPositionWord() const;
    sf::Vector2f getScale() const;
    sf::Vector2f getOrigin() const;*/

    bool hide(), show();
    virtual void update(sf::Time deltaTime);
    virtual void handle(const sf::Event &event);
    void draw(sf::RenderTarget &target, const sf::RenderStates &states = sf::RenderStates::Default) const;

protected:
    virtual void m_draw(sf::RenderTarget &target, const sf::RenderStates &states) const;
    bool m_visibility{true};
};
