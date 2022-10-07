#include "Game_State.hpp"

#include <cassert>


std::size_t Data::getIndex()
{
    static std::size_t m_index{0};
    return m_index++;
}

const std::size_t Data::Data_type = getIndex();

void Game_State::operator()(const sf::Event& event)
{
    assert(handle);
    assert(data);
    assert(data->type);

    handle->handle(event, data);

    assert(m_next != this);
    if(m_next)
        m_next->operator()(event);
}

Game_State::Game_State(Handle &a_handle, Data &a_data, Game_State* gameState)
    :m_next{gameState}
    ,handle{&a_handle}
    ,data{&a_data}
{ assert(handle && data); }


void Game_State::operator()(sf::Time deltaTime)
{
    assert(handle);
    assert(data);
    assert(data->type);

    handle->update(deltaTime, data);

    assert(m_next != this);
    if(m_next)
        m_next->operator()(deltaTime);
}
