#pragma once

#include "Gui.h"


class Button : public Gui, public Activable{
    sf::Vector2f m_normal_scale{};
    Shorten m_onClick;
    Longen m_onMouse;
    Hover m_hover;
    void (*m_changer)();
public:
    explicit Button(void (*lambd)(), const std::string& a_string);
    ~Button() override = default;
    void update(sf::Time deltaTime) override;
    /// MouseMoved | MouseButtonReleased
    void handle(const sf::Event& event) override;
};