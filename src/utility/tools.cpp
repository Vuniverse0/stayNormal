#include "typedefs_and_tools.h"

#include "../core/Handler.h"

#include <random>


bool isLess(const sf::Vector2f& a_left, const sf::Vector2f& a_right)
{
    return (a_left.x < a_right.x && a_left.y < a_right.y);
}

namespace ratio {
    cords valuable_ratio()
    {
        return
        Handler::gHandler->y_ratio > Handler::gHandler->x_ratio
            ? Handler::gHandler->x_ratio
            : Handler::gHandler->y_ratio;
    }

    cords x_ratio()
    {
        return Handler::gHandler->x_ratio;
    }

    cords y_ratio()
    {
        return Handler::gHandler->y_ratio;
    }

    pixels x_size()
    {
        return Handler::getSize().x;
    }

    pixels y_size()
    {
        return Handler::getSize().y;
    }
}

sf::Vector2f window_center(sf::Vector2u size)
{
    return {static_cast<std::float_t>(size.x) / 2.f, static_cast<std::float_t>(size.y) / 2.f};
}

sf::Vector2f global_half(const sf::Sprite * const sprite)
{
    auto temp = sprite->getGlobalBounds();
    return {temp.width / 2.0f, temp.height / 2.0f};
}

sf::Vector2f local_center (const sf::Sprite * const sprite)
{
    auto temp = sprite->getLocalBounds();
    return {temp.width / 2.0f, temp.height / 2.0f};
}

sf::Vector2f center(const sf::Sprite * const sprite)
{
    auto temp = sprite->getGlobalBounds();
    return{temp.left + temp.width / 2.0f, temp.top + temp.height / 2.0f};
}

void scale_by_mouse(sf::Sprite * const sprite, bool focus)
{
    if (focus) {
        sprite->scale(1.01f, 1.01f);
    }
    else {
        sprite->scale(0.99f, 0.99f);
    }
}

sf::FloatRect size_regulator(const sf::Sprite * const sprite)
{
    auto l_bounds = (sprite->getGlobalBounds());
    l_bounds.width*0.6;//Todo check if this work(REALLY?)
    return l_bounds;
}

std::uint8_t binominal_int(std::uint8_t a_start, std::uint8_t a_end, std::float_t a_binominal)
{
    if (a_start >= a_end || a_binominal <= 0.f || a_binominal >= 1.f) {
        return 0;
    }
    unsigned long rand_lol;
    std::default_random_engine generator{rand_lol};
    std::binomial_distribution<std::uint8_t> distribution((a_start + a_end), a_binominal);
    return ((distribution(generator) - a_start));
}

std::float_t binominal_float(std::float_t a_start, std::float_t a_end, std::float_t a_binominal)
{
    if (a_end > 25 || a_start >= a_end || a_start < 0.f || a_binominal <= 0.f || a_binominal >= 1.f) {
        return -1.f;
    }
    unsigned long rand_lol;//TODO wtf is it
    std::default_random_engine generator{rand_lol};
    int start = static_cast<std::uint8_t>(a_start * 10), end = static_cast<std::uint8_t>(a_end * 10);
    std::binomial_distribution<std::uint8_t> distribution((start + end), a_binominal);
    return (static_cast<std::float_t>(distribution(generator) - start) / 10.f);
}
