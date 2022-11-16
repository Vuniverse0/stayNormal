#ifndef STAYNORMAL_PHRASE_HPP
#define STAYNORMAL_PHRASE_HPP

#include <string_view>
#include <array>
#include <cassert>


struct Phrase {
    explicit Phrase(std::string_view message);

    ///return null pointer if this is end
    virtual Phrase* next();

    void next(Phrase& a_next);

    std::string_view getMessage();

    ///return 0 if its basic phrase, answer is question
    [[nodiscard]] virtual std::size_t answer() const;

private:
    std::string_view m_message;
    Phrase *m_next{nullptr};
};

struct Question : Phrase{
    using Phrase::Phrase;

    Phrase* next() override;

    template<typename ...Args>
    void next(Args&... args)
    { m_answers = sizeof...(args), assert(m_answers <= 5), m_next = {&args...}; }

    ///n from 1
    void answer(std::size_t n);

    [[nodiscard]] std::size_t answer() const override;

private:
    std::array<Phrase*, 5> m_next{};
    std::size_t m_answer{1}, m_answers{0};
};

#endif //STAYNORMAL_PHRASE_HPP
