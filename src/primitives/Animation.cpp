#include "Animation.h"


Animation::Animation(const std::string& a_sheet, pixels a_size_x, pixels a_size_y, frames a_count) ///x!=y
    :m_count{a_count}
    ,m_size_x{a_size_x}
    ,m_size_y{a_size_y}
{
    if(a_count == 0){
        m_count = (m_texture.getSize().x / m_size_x) * (m_texture.getSize().y / m_size_y);
    }
    m_texture.loadFromFile(a_sheet);
    m_texture.setSmooth(true);
    assert(m_texture.getSize().x / m_size_x >= 1);
    assert(m_texture.getSize().y / m_size_y >= 1);
    assert((m_texture.getSize().x / m_size_x) * (m_texture.getSize().y / m_size_y) == m_count);
}

#if 0 ///Animation& Animation::operator=(const Animation& other)
Animation& Animation::operator=(const Animation& other)
{
    if(this == &other)
        return *this;
    m_sprite = other.m_sprite;
    m_texture = other.m_texture;
    m_i = other.m_i;
    m_count = other.m_count;
    m_size_x = other.m_size_x;
    m_size_y = other.m_size_y;
    counter = other.counter;
    return *this;
}
#endif


bool Animation::play(sf::Sprite* sprite, float_t speed, bool direction)
{
    if(!m_alt_texture){
        m_alt_texture = sprite->getTexture();
        sprite->setTexture(m_texture);
    }
    bool result = false;
    counter += speed;
    if((direction
        ?( m_i == 0 )
        :( m_i == m_count ) )
       ){
        m_i = (direction ? m_count - (m_i - m_count): 0);
        result = true;
    }
    if(counter >= 1.f){
        pixels x = m_texture.getSize().x / m_size_x;
        sprite->setTextureRect(sf::IntRect{
            ((m_texture.getSize().y / m_size_y != 1) ? (m_i % x) : m_i ) * m_size_x,
            ((m_texture.getSize().y / m_size_y != 1) ? (m_i / x) : 0 ) * m_size_y,
            m_size_x,
            m_size_y});
        m_i = direction ? m_i - static_cast<frames>(counter) : m_i + static_cast<frames>(counter);
        counter = 0.f;
    }
    return result;
}

bool Animation::stop(sf::Sprite* sprite, bool setAlt)
{
    if (!m_alt_texture)
        return false;
    if(setAlt){
        sprite->setTexture(*m_alt_texture);
        counter = 0.f;
        m_i = 0;
    }
    m_alt_texture = nullptr;
    return true;
}

///return m_alt_texture != nullptr
bool Animation::setAltTexture(sf::Sprite *sprite)
{
    bool res = (m_alt_texture != nullptr);
    m_alt_texture = sprite->getTexture();
    return res;
}
