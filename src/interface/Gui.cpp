#include "Gui.h"
#include "../core/Handler.h"


Shorten::Shorten(sf::Vector2f a_normal_scale, sf::Sprite* a_p_sprite)
    :m_normal_scale{a_normal_scale}
    ,m_p_sprite{a_p_sprite}
{}

void Shorten::handle()
{
    if(m_mouse ){
        if(m_p_sprite->getScale().x > m_normal_scale.x){
            scale_by_mouse( m_p_sprite, false );
            scale_by_mouse( m_p_sprite, false );
            Handler::gHandler->update_ui();
        }else{
            m_mouse = false;
        }
    }
}

void Shorten::use() { m_mouse = true; }




Activable::Activable(sf::Sprite *a_p_sprite)
    :m_p_sprite{a_p_sprite}
{}

void Activable::enable()
{
    m_active = true;
    m_p_sprite->setColor(sf::Color(m_light, m_light, m_light));
}

void Activable::disable()
{
    m_active = false;
    m_p_sprite->setColor(sf::Color(m_dark, m_dark, m_dark));
}

bool Activable::is_active() const { return m_active; }

void Activable::set(sf::Uint8 light, sf::Uint8 dark)
{ m_dark = dark, m_light = light; }


bool Unfold::handle(bool fold)
{
    static const std::float_t fold_speed_up = 2.f;
    const std::float_t fold_speed = fold ? 10.f * fold_speed_up : 10.f;
    std::float_t x{}, y{}, sum = sum_a;
    switch(fold ? !m_direction : m_direction){
        case None: break;
        case Up: y -= fold_speed; break;
        case Down: y += fold_speed; break;
        case Left: x -= fold_speed; break;
        case Right: x += fold_speed; break;
        default: assert(false);//No viable direction in Unfold
    }

    bool(*cmp [2])(std::float_t, std::float_t)=
    {
        +[](std::float_t f, std::float_t s){ return f > s; }
        ,+[](std::float_t f, std::float_t s){ return f < s; }
    };
    std::float_t(*op [2])(std::float_t, std::float_t)=
    {
            +[](std::float_t f, std::float_t s){ return f + s; }
            ,+[](std::float_t f, std::float_t s){ return f - s; }
    };
    int isVertical = ( m_direction == Up || m_direction == Down ? 1 : 0 );
    int isRightDown = ( m_direction == Right || m_direction == Down ? 1 : 0 );
    auto ort = isVertical
            ? &sf::Vector2<std::float_t>::y
            : &sf::Vector2<std::float_t>::x;
    auto ort2 = isVertical
            ? &sf::Rect<std::float_t>::height
            : &sf::Rect<std::float_t>::width;
    //TODO if fold
    bool some_moved = false;
    for(auto item : m_group){
        if ( cmp[isRightDown]
            (
                    item->getPosition().*ort,
                    op[isRightDown]
                (
                m_p_sprite->getPosition().*ort,
                sum + (item->getScale().*ort * item->getOrigin().*ort) + m_separator / 2
                )
            )
        )
            item->move(x, y), some_moved = true;
        sum -= (item->getGlobalBounds().*ort2 + m_separator);
    }
#if 0
    for(auto& arg : args)
        sum_a += ( ( arg->sprite().getGlobalBounds().width + separator ) );
    sum_a /= 2;
    for(auto& arg : args){
        auto& tmp = arg->sprite();
        tmp.setPosition(
                v.x - sum_a + (
                        tmp.getScale().x * tmp.getOrigin().x
                )
                + separator / 2,
                v.y
        );
        sum_a -= (tmp.getGlobalBounds().height + separator);
    }
#endif
    return !some_moved; //moving ended
}


Unfold::Unfold(Direction direction, sf::Sprite* a_p_sprite, Range<iterator_type> a_group, std::float_t separator)
    :m_group{a_group}
    ,m_direction{direction}
    ,sum_a{0}
    ,m_separator{separator}
    ,m_p_sprite{a_p_sprite}
{
    auto ort = direction == Up || direction == Down
            ? &sf::Rect<std::float_t>::height
            : &sf::Rect<std::float_t>::width;
    for ( auto arg : m_group )
        sum_a += ( ( arg->getGlobalBounds().*ort + m_separator ) );
}

bool Unfold::unfold(){return handle(false);}

bool Unfold::fold(){return handle(true);}




Hover::Hover(sf::Sprite *a_p_sprite)
    :m_p_sprite{a_p_sprite}
{}

void Hover::handle(const sf::Event &event)
{
    if ( sf::Event::MouseMoved == event.type || sf::Mouse::Left  == event.mouseButton.button)
        (sf::Event::MouseMoved == event.type ? m_mouse_on : m_mouse_click) =
            size_regulator(m_p_sprite).contains(
            {
                static_cast<std::float_t>(
                    sf::Event::MouseMoved == event.type
                        ? event.mouseMove.x
                        : event.mouseButton.x),
                static_cast<std::float_t>(
                    sf::Event::MouseMoved == event.type
                        ? event.mouseMove.y
                        : event.mouseButton.y)
            });
}

bool Hover::isOnClick()
{
    if ( m_mouse_click ) m_mouse_click = false;
    else return false;
    return true;
}

bool Hover::isMouseOn() const { return m_mouse_on; }




void Longen::handle( bool mouse )
{
    if(mouse and m_p_sprite->getScale().x - m_normal_scale.x < 0.03f){
        scale_by_mouse(m_p_sprite, true);
        m_mouse = true;
    }else if(m_mouse and !mouse and isLess(m_normal_scale, m_p_sprite->getScale())){
        scale_by_mouse(m_p_sprite, false);
    }else if(m_mouse and !mouse){ ///and m_p_sprite->getScale() != m_normal_scale ) {
        m_p_sprite->setScale(m_normal_scale);
        m_mouse = false;
    }else{
        return;
    }
    Handler::gHandler->update_ui();
}

bool Longen::is() const { return m_mouse; }
