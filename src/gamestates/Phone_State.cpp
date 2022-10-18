#include "Phone_State.hpp"

#include <cassert>


DATA_INDEX_IMPL(PhoneData);

HANDLE_IMPL(PhoneHandle);

void PhoneHandle::update(sf::Time deltaTime, Data *data)
{
    DATA_CAST(phoneData);

}

void PhoneHandle::handle(const sf::Event &event, Data *data)
{
    DATA_CAST(phoneData);

}
