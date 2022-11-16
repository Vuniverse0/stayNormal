#ifndef STAYNORMAL_GAMEEVENT_HPP
#define STAYNORMAL_GAMEEVENT_HPP


struct GameEvent {
    enum class GameEventType{None, Call, GameOver, Size, Error} type;
    union{
        struct{
           // std::string
        }call;
    }data;
};///TODO

#endif //STAYNORMAL_GAMEEVENT_HPP
