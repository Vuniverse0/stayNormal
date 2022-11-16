#ifndef STAYNORMAL_HANDLER_HPP
#define STAYNORMAL_HANDLER_HPP

#include <iterator>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include "../utility/typedefs_and_tools.h"
#include "Game.hpp"


struct Entry;
struct Gui;

struct Handler {//singleton
    ///singleton
    Handler(Word* word, Ui* ui);
    ~Handler();

    inline static Handler* gHandler{nullptr};

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

private:
    sf::RenderWindow m_window;
    sf::RenderTexture m_ui;
    sf::RenderTexture m_word;
    sf::Time m_time_per_frame{};

    bool m_IsPaused{false}, m_ui_updated{true};
};

template<typename Iterator>
void Handler::draw(Iterator begin, Iterator end, const sf::RenderStates &states)
{
    for(auto it = begin; it != end; ++it)
        draw(*it, states);
}

template<typename Iterator>
void Handler::draw_ui(Iterator begin, Iterator end, const sf::RenderStates &states)
{
    for(auto it = begin; it != end; ++it)
        draw_ui(*it, states);
}

#endif //STAYNORMAL_HANDLER_HPP
