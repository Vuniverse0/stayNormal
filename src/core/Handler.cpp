#include "Handler.hpp"

#include "Game.hpp"
#include "../interface/Gui.hpp"


Handler::Handler(Word* word, Ui* ui) noexcept(noexcept(sf::RenderWindow()))
    :m_window(//{1600,1000},
        sf::VideoMode::getFullscreenModes()[0],
        "Surviving Try Around Remote Stars",//sf::Style::Default, sf::ContextSettings(0,0,8));
        sf::Style::Fullscreen, sf::ContextSettings(0,0,8)
        )
    ,x_ratio {static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].width) / GAME_MAKER_SCREEN_WIDTH}
    ,y_ratio {static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].height) / GAME_MAKER_SCREEN_HEIGHT}
{
    if(gHandler)
        throw std::runtime_error("Second Handler");
    gHandler = this;

    if ( !m_ui.create(sf::VideoMode::getFullscreenModes()[0].width,
                     sf::VideoMode::getFullscreenModes()[0].height) )
        throw std::runtime_error("Cannot create UI");

    if ( !m_word.create(sf::VideoMode::getFullscreenModes()[0].width,
                      sf::VideoMode::getFullscreenModes()[0].height) )
        throw std::runtime_error("Cannot create Word");

    set_fps(DEFAULT_FPS);

    game.gui = ui;
    game.word = word;
    game.setup();
}

void Handler::set_fps(const frames& a_fps)
{
    m_window.setFramerateLimit(a_fps + 5 );
    m_time_per_frame = sf::seconds(1.f  / static_cast<float_t>(a_fps));
}

bool Handler::exit()
{
    m_window.close();
    if ( m_window.isOpen() )
        return false;
    return true;
}

void Handler::render()
{
    m_window.clear();
    m_word.clear();
    if(m_ui_updated)
        m_ui.clear(sf::Color(0,0,0,0));

    game.draw();

    if(m_ui_updated)
        m_ui.display();

    m_word.draw(sf::Sprite{m_ui.getTexture()}, game.gui->ui_states);

    m_word.display();

    m_window.draw(sf::Sprite{m_word.getTexture()}, game.word->states);

    m_window.display();

    m_ui_updated = false;
}

void Handler::process_events()
{
    sf::Event event{};
    while ( m_window.pollEvent(event) ) {
        switch (event.type) {
            case sf::Event::Closed:
                exit();
                break;
            default:
                game.handle(event);
        }
    }
}

void Handler::update_ui()
{
    m_ui_updated = true;
    game.gui->update();
}

void Handler::update(sf::Time deltaTime) { game.update(deltaTime); }

sf::Time Handler::TimePerFrame() { return gHandler->m_time_per_frame; }

void Handler::draw(const Entry* drawable, const sf::RenderStates& states) { drawable->draw(m_word, states); }

void Handler::draw_ui(const Gui *drawable, const sf::RenderStates &states) { drawable->draw(m_ui, states); }

bool Handler::isOpen() { return gHandler->m_window.isOpen(); }

sf::Vector2u Handler::getSize() { return gHandler->m_window.getSize(); }

void Handler::resume() { m_IsPaused = true; }

void Handler::pause() { m_IsPaused = false; }

Handler::~Handler() { gHandler = nullptr; }
