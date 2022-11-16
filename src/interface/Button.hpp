#ifndef STAYNORMAL_BUTTON_HPP
#define STAYNORMAL_BUTTON_HPP

#include "Gui.hpp"
#include "../primitives/Sprite.hpp"


struct Button :  Gui, Sprite, Activable{
    explicit Button(std::function<void()> callback, const std::string& a_string);
    ~Button() override = default;
    void update(sf::Time deltaTime) override;
    /// MouseMoved | MouseButtonReleased
    void handle(const sf::Event& event) override;

private:
    sf::Vector2f m_normal_scale{};
    Shorten m_onClick;
    Longen m_onMouse;
    Hover m_hover;
    std::function<void()> m_changer;
};

#endif //STAYNORMAL_BUTTON_HPP
