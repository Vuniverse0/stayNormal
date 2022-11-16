#include "Button.hpp"

#include <utility>

#include "../core/Handler.hpp"

#define MAGIC_RATIO_BUTTONS 0.5f //TODO delete this shit, or no)))


Button::Button(std::function<void()> callback, const std::string& a_string)
        :Sprite(a_string, MAGIC_RATIO_BUTTONS, MAGIC_RATIO_BUTTONS)
        ,Activable{&m_sprite}
        ,m_changer{std::move(callback)}
        ,m_normal_scale{m_sprite.getScale()}
        ,m_hover{&m_sprite}
        ,m_onMouse{m_normal_scale, &m_sprite}
        ,m_onClick{m_normal_scale, &m_sprite}
{
    m_sprite.setOrigin(local_center(&m_sprite));//for nice size change
}


void Button::update(sf::Time deltaTime)
{
    if(m_hover.isOnClick() && is_active()){
        m_changer();
        m_onClick.use();
    }
    m_onClick.handle();
    if(m_hover.isMouseOn() || m_onMouse.is())
        m_onMouse.handle(m_hover.isMouseOn());
}

void Button::handle(const sf::Event& event)
{
    assert(
        event.type == sf::Event::MouseMoved
                   or
        event.type == sf::Event::MouseButtonReleased
    ); //update me only in this cases
    m_hover.handle(event);
}