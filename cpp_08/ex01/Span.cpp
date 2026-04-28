#include "Span.hpp"

Span::Span(unsigned int n) : _max(n)
{
}

Span::Span(Span const &src) : _max(src._max), _numbers(src._numbers)
{
}

Span &Span::operator=(Span const &src)
{
    if (this != &src)
    {
        _max     = src._max;
        _numbers = src._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _max)
        throw std::runtime_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); i++)
    {
        if (sorted[i] - sorted[i - 1] < shortest)
            shortest = sorted[i] - sorted[i - 1];
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers");
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    return max - min;
}