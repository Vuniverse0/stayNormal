#ifndef STAYNORMAL_GAME_HPP
#define STAYNORMAL_GAME_HPP

#include <array>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "../utility/Range.hpp"


struct Handler;
struct Entry;
struct Gui;
struct Panel;
struct Button;

struct Ui{
    Handler* handler = {nullptr};

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
    ///true when events or process animation (need to set from inside of ui classes, by Handler(he draw ui on window))
    bool uiChanged{true};
};

struct Word{
    Handler* handler{nullptr};

    using array_iterator = std::array<Entry*,0>::iterator;

    Range<array_iterator> MouseButtonReleased{nullptr, nullptr};
    Range<array_iterator> entries{nullptr, nullptr};

    void draw();

    void handle(const sf::Event& event);
    void update(sf::Time deltaTime);

    sf::RenderStates states = sf::RenderStates::Default;
};

struct Game {
    Handler* handler{nullptr};

    Ui* gui{nullptr};
    Word* word{nullptr};

    void setup( Handler* a_handler = nullptr );

    void draw();

    void handle(const sf::Event& event);
    void update(sf::Time deltaTime) const;

private:
    bool m_setup{false};
};

#endif //STAYNORMAL_GAME_HPP
