#ifndef STAYNORMAL_ENTRY_HPP
#define STAYNORMAL_ENTRY_HPP

#include <cmath>
#include <string>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "../utility/typedefs_and_tools.h"


struct Entry {
    virtual ~Entry() = default; ///Maybe unused because I don`t have habit to allocate dynamically

    bool hide(), show();
    virtual void update(sf::Time deltaTime);
    virtual void handle(const sf::Event &event);
    void draw(sf::RenderTarget &target, const sf::RenderStates &states = sf::RenderStates::Default) const;

protected:
    virtual void m_draw(sf::RenderTarget &target, const sf::RenderStates &states) const;
    bool m_visibility{true};
};

#endif //STAYNORMAL_ENTRY_HPP
