#ifndef STAYNORMAL_TEXT_HPP
#define STAYNORMAL_TEXT_HPP

#include "../primitives/Entry.h"

#include <SFML/Graphics/Text.hpp>

struct Text : Entry {

    void update(sf::Time deltaTime) override;
    void handle(const sf::Event &event) override;
    void draw(sf::RenderTarget &target, const sf::RenderStates &states = sf::RenderStates::Default) const override;

private:
    sf::Text m_text;
};

#endif //STAYNORMAL_TEXT_HPP
