#pragma once

#include "../primitives/Entry.h"
#include "Place.h"


struct Gui : Entry{
    using Entry::Entry;
    ~Gui() override = default;
};

struct Hover{
    void handle(const sf::Event& event);
    explicit Hover(sf::Sprite* a_p_sprite);
    [[nodiscard]] bool isMouseOn() const;
    [[nodiscard]] bool isOnClick();
protected:
    sf::Sprite* m_p_sprite;
private:
    bool m_mouse_click{false};
    bool m_mouse_on{false};
};

struct Shorten{
    void handle();
    void use();
    explicit Shorten(sf::Vector2f a_normal_scale, sf::Sprite* a_p_sprite);
protected:
    sf::Sprite* m_p_sprite;
    sf::Vector2f m_normal_scale;
    bool m_mouse{false};
};

struct Longen : private Shorten{
    void handle( bool mouse );
    [[nodiscard]] bool is() const;
    using Shorten::Shorten;
};

struct Activable{
    void enable();
    void disable();
    [[nodiscard]] bool is_active() const;
    explicit Activable(sf::Sprite* a_p_sprite);
protected:
    sf::Sprite* m_p_sprite;
private:
    bool m_active{true};
};

struct Unfold{
    using iterator_type = std::array<sf::Sprite*, 0>::iterator;
    Unfold(Direction direction, sf::Sprite* a_p_sprite, Range<iterator_type> a_group, std::float_t separator);
    bool unfold();
    bool fold();
private:
    bool handle( bool fold );
    Direction m_direction{None};
    sf::Sprite* m_p_sprite;
    Range<iterator_type> m_group;
    float_t sum_a, m_separator;
};