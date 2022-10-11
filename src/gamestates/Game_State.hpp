#ifndef STAYNORMAL_GAME_STATE_HPP
#define STAYNORMAL_GAME_STATE_HPP

#include <SFML/Window/Event.hpp>


#define DATA_INDEX_DECL(what) static const std::size_t what##_type
#define DATA_INDEX_IMPL(what) const std::size_t what::what##_type = getIndex()

#define HANDLE_DECL(what) static what Handle
#define HANDLE_IMPL(what) what what::Handle{}


struct Data {
    std::size_t type = Data_type;
    DATA_INDEX_DECL(Data);
protected:
    static std::size_t getIndex();
};

struct Handle {
    virtual void handle(const sf::Event &event, Data *data) = 0;
    virtual void update(sf::Time deltaTime, Data *data) = 0;
};

struct Game_State {
    ///States can called by chain if you pass nextState
    explicit Game_State(Handle &a_handle, Data &a_data, Game_State* nextState = nullptr);
    Handle *handle;
    Data *data;
    void operator()(const sf::Event&);
    void operator()(sf::Time deltaTime);
protected:
    Game_State * const m_next;
};

#endif //STAYNORMAL_GAME_STATE_HPP
