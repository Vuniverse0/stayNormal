#include "Phrase.hpp"


Phrase::Phrase(std::string_view message)
    :m_message{message}
{}

Phrase* Phrase::next()
{ return m_next; }

void Phrase::next(Phrase &a_next)
{ m_next = &a_next; }

std::string_view Phrase::getMessage()
{ return m_message; }

std::size_t Phrase::answer() const
{ return 0; }


void Question::answer(std::size_t n)
{
    assert(n <= m_answers);
    m_answer = n;
}

Phrase* Question::next()
{ return m_next[m_answer - 1]; }

std::size_t  Question::answer() const
{ return m_answer; }
