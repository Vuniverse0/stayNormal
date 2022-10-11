#pragma once

#include "../utility/Range.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <array>


struct Handler;
struct Entry;
struct Gui;
struct Panel;
struct Button;

struct Ui{
    Ui() = default;

    Handler* handler = nullptr;

    using array_iterator = std::array<Gui*,0>::iterator;

    Range<array_iterator> gui{nullptr, nullptr};
    Range<array_iterator> MouseButtonReleased{nullptr, nullptr};
    Range<array_iterator> MouseMoved{nullptr, nullptr};

    void draw();
    void update();

    void handle(const sf::Event& event);
    void update(sf::Time deltaTime);

    sf::RenderStates ui_states = sf::BlendAdd;
            //sf::BlendAdd; ///TODO create self made blend mode
    sf::RenderStates states = sf::RenderStates::Default;
private:
    /// true when events or process animation (need to set from inside of ui classes, by Handler(he draw ui on window))
    bool uiChanged = true;
};

struct Word{
    Word() = default;

    Handler* handler = nullptr;

    using array_iterator = std::array<Entry*,0>::iterator;

    Range<array_iterator> MouseButtonReleased{nullptr, nullptr};
    Range<array_iterator> entries{nullptr, nullptr};

    void draw();

    void handle(const sf::Event& event);
    void update(sf::Time deltaTime);

    sf::RenderStates states = sf::RenderStates::Default;
};

struct Game {
    Game() = default;

    Handler* handler = nullptr;

    Ui* gui = nullptr;
    Word* word = nullptr;

    void setup( Handler* a_handler = nullptr );

    void draw();

    void handle(const sf::Event& event);
    void update(sf::Time deltaTime) const;

private:
    bool m_setup = false;
};