#ifndef STAYNORMAL_GAMEEVENT_HPP
#define STAYNORMAL_GAMEEVENT_HPP


struct GameEvent {
    enum class GameEventType{None, Call, GameOver, Size, Error} type;
    union{
        struct{
            std::string
        }call;
    }data;
};

#endif //STAYNORMAL_GAMEEVENT_HPP
