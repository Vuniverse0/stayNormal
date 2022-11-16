#ifndef STAYNORMAL_GAME_STATE_HPP
#define STAYNORMAL_GAME_STATE_HPP

#include <cassert>

#include <SFML/Window/Event.hpp>


#define DATA_INDEX_DECL(what) static const std::size_t data_type
#define DATA_INDEX_IMPL(what) const std::size_t what::data_type = getIndex()

#define HANDLE_DECL(what) static what Handle
#define HANDLE_IMPL(what) what what::Handle{}

#define DATA_CAST(to) \
assert(data->type == Data_t::data_type);\
Data_t *to{ reinterpret_cast<Data_t*>(data) }

#define USE_DATA(what)     \
using Data_t = what; \
using Data = Game_State::Data


struct Game_State {
    struct Data {
        std::size_t type = data_type;
        DATA_INDEX_DECL(Data);
    protected:
        static std::size_t getIndex();
    };

    struct Handle {
        virtual void handle(const sf::Event &event, Data *data) = 0;
        virtual void update(sf::Time deltaTime, Data *data) = 0;
    };

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
