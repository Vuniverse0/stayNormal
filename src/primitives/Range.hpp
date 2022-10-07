#ifndef STAYNORMAL_RANGE_HPP
#define STAYNORMAL_RANGE_HPP

template<typename Iterator>
class Range{
    Iterator m_begin, m_end;

public:
    Range(Iterator begin, Iterator end) : m_begin{begin}, m_end{end} {};

    template<typename T>
    Range(T &container) : m_begin{container.begin()}, m_end{container.end()} {};

    Range(const Range &range) : m_begin{range.begin()}, m_end{range.end()} {};

    Iterator begin() const { return m_begin;}
    Iterator end() const { return m_end;}

    void begin(Iterator begin) { m_begin = begin;}
    void end(Iterator end) { m_end = end;}
};

#endif //STAYNORMAL_RANGE_HPP
