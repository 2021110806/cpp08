#include "Span.hpp"

Span::Span()
{
	std::cout << "default constructor called" << std::endl;
}

Span::Span(unsigned int N) : size(N), numbers(std::set<int>())
{
	std::cout << "constructor called" << std::endl;
}

Span::Span(const Span &other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this !=& other)
	{
		this -> size = other.size;
		this -> numbers = other.numbers;
	}
	return (*this);
}

Span::~Span()
{
	numbers.clear();
	std::cout << "destructor called" << std::endl;
}

unsigned int Span::getSize() const
{
	return size;
}

unsigned long long Span::shortestSpan()
{
	if (numbers.size() <= 1)
        throw NotEnoughElementException();
	unsigned long long  minSpan = std::numeric_limits<unsigned long long>::max();
	ITERATOR it = numbers.begin();
	ITERATOR nextIt = numbers.begin();
	nextIt++;
	while (nextIt != numbers.end()) {
		unsigned long long span = static_cast<unsigned long long>(*nextIt - *it);
        if (span < minSpan) {
            minSpan = span;
        }
        ++it;
        ++nextIt;
	}
	return minSpan;
}

unsigned long long Span::longestSpan()
{
	if (numbers.size() <= 1)
		throw NotEnoughElementException();
	if (*numbers.rbegin() < *numbers.begin())
		throw GeneralException();
	return *numbers.rbegin() - *numbers.begin();
}

void Span::addNumber(int n)
{
	if (size <= numbers.size())
		throw SetFullException();
	numbers.insert(n);
}

void Span::addNumbers(ITERATOR begin, ITERATOR end)
{
	if (*numbers.rbegin() < *numbers.begin())
		throw GeneralException();
	unsigned int numberOfElements = std::distance(begin, end);
	 if (numberOfElements > size - numbers.size()) {
        throw std::out_of_range("Not enough space in Span to add all elements");
	 }
    for (ITERATOR it = begin; it != end; ++it) {
        numbers.insert(*it);
    }
}
