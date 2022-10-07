#pragma once

#include "../utility/typedefs_and_tools.h"

#include "Game.h"

#include <iterator>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <iostream>


struct Entry;
struct Gui;

struct Handler {//singleton
private:
    sf::RenderWindow m_window;
    sf::RenderTexture m_ui;
    sf::RenderTexture m_word;
    sf::Time m_time_per_frame{};

    bool m_IsPaused{false}, m_ui_updated{true};
public:
    ///singleton
    inline static Handler* gHandler{nullptr};
    Handler(Word* word, Ui* ui);

    ///ui rerender
    void update_ui();

    ///draw any Entry by calling draw()
    void draw(const Entry* drawable, const sf::RenderStates& states = sf::RenderStates::Default);

    ///draw any Gui by calling draw()
    void draw_ui(const Gui* drawable, const sf::RenderStates& states = sf::RenderStates::Default);

    ///draw any Entries by calling draw() for whole
    template <typename Iterator>
    void draw(Iterator begin, Iterator end, const sf::RenderStates& states = sf::RenderStates::Default);

    ///draw any Guis by calling ->draw for whole
    template <typename Iterator>
    void draw_ui(Iterator begin, Iterator end, const sf::RenderStates& states = sf::RenderStates::Default);

    ///properties of monitor
    const float_t x_ratio, y_ratio;

    ///Game
    Game game;

    ///widow size
    static sf::Vector2u getSize();

    ///time per frame
    static sf::Time TimePerFrame();

    void resume();
    void pause();

    void render();
    void update(sf::Time deltaTime);
    void process_events();

    void set_fps(const frames&);

    static bool isOpen();

    bool exit();

    ~Handler();
};

template<typename Iterator>
void Handler::draw(Iterator begin, Iterator end, const sf::RenderStates &states)
{
    for(;begin != end; ++begin)
        draw(*begin, states);
}

template<typename Iterator>
void Handler::draw_ui(Iterator begin, Iterator end, const sf::RenderStates &states)
{
    for(;begin != end; ++begin)
        draw_ui(*begin, states);
}
