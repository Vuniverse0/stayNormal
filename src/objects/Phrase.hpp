#ifndef STAYNORMAL_PHRASE_HPP
#define STAYNORMAL_PHRASE_HPP

#include <string_view>
#include <array>


struct Phrase {
    std::string_view message;
};

struct Question : Phrase{
    struct{
        std::array<std::string_view, 5> answers;
        std::size_t answer{0}; // 0 < answer <= 5 valid state
    } answer;
};

#endif //STAYNORMAL_PHRASE_HPP
