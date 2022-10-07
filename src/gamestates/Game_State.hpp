#ifndef STAYNORMAL_GAME_STATE_HPP
#define STAYNORMAL_GAME_STATE_HPP

#include <SFML/Window/Event.hpp>


struct Data {
    std::size_t type = Data_type;

    static const std::size_t Data_type;
protected:
    static std::size_t getIndex();
};

struct Handle {
    virtual void handle(const sf::Event &event, Data *data) = 0;
    virtual void update(sf::Time deltaTime, Data *data) = 0;
};

struct Game_State {
    explicit Game_State(Handle &a_handle, Data &a_data, Game_State* gameState = nullptr);
    Handle *handle;
    Data *data;
    void operator()(const sf::Event&);
    void operator()(sf::Time deltaTime);
protected:
    Game_State *m_next;
};

#endif //STAYNORMAL_GAME_STATE_HPP
