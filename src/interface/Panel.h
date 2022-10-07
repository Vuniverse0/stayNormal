#pragma once

#include "Corner.h"
#include "../primitives/Entry.h"
#include "Button.h"


class Panel : public Gui {
    using iterator_type = std::array<Button*, 0>::iterator;
    Range<iterator_type> m_buttons;
public:
    Panel(Range<iterator_type> a_group, const std::string& a_sprite,
          std::float_t x_ratio = 1, std::float_t y_ratio = 1, bool smooth = false);
    void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const override;
    void update( sf::Time deltaTime ) override;
    void handle( const sf::Event& ) override;
};