#ifndef STAYNORMAL_PANEL_HPP
#define STAYNORMAL_PANEL_HPP

#include "Corner.hpp"
#include "Button.hpp"


struct Panel : Gui, Sprite{
    using iterator_type = std::array<Button*, 0>::iterator;

    Panel(Range<iterator_type> a_group, const std::string& a_sprite,
          std::float_t x_ratio = 1, std::float_t y_ratio = 1, bool smooth = false);

    void m_draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    void update( sf::Time deltaTime ) override;
    void handle( const sf::Event& ) override;

private:
    Range<iterator_type> m_buttons;
};

#endif //STAYNORMAL_PANEL_HPP
