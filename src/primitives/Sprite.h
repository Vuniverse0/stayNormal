#pragma once

#include "Entry.h"

template<typename T = Entry>
struct Sprite : T {
    using T::T;
    void update( sf::Time deltaTime ) override {};
    void handle(const sf::Event& event) override {};
    ~Sprite() override = default;
};