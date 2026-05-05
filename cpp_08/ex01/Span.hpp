#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
    private:
        unsigned int     _max;
        std::vector<int> _numbers;

    public:
        Span(unsigned int n);
        Span(Span const &src);
        Span &operator=(Span const &src);
        ~Span();

        void addNumber(int n);
        int  shortestSpan();
        int  longestSpan();

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if ((_numbers.size() + std::distance(begin, end)) > _max)
                throw std::runtime_error("Span is full");
            _numbers.insert(_numbers.end(), begin, end);
        }
};

#endif