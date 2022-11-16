#include "Game_State.hpp"


DATA_INDEX_IMPL(Game_State::Data);

Game_State::Game_State(Handle &a_handle, Data &a_data, Game_State* nextState)
    :m_next{nextState}
    ,handle{&a_handle}
    ,data{&a_data}
{ assert(handle && data); }

std::size_t Game_State::Data::getIndex()
{
    static std::size_t m_index{0};
    return m_index++;
}

void Game_State::operator()(const sf::Event& event)
{
    assert(handle);
    assert(data);

    handle->handle(event, data);

    if(m_next)
        m_next->operator()(event);
}

void Game_State::operator()(sf::Time deltaTime)
{
    assert(handle);
    assert(data);

    handle->update(deltaTime, data);

    if(m_next)
        m_next->operator()(deltaTime);
}
