#ifndef SPAN_HPP
#define SPAN_HPP
#define ITERATOR std::set<int>::iterator
#include <iostream>
#include <exception>
#include <set>
class Span
{
	private:
		Span();
		unsigned int size;
		std::set<int> numbers;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		unsigned long long shortestSpan();
		unsigned long long longestSpan();
		unsigned int getSize() const;
		void addNumber(int n);
		void addNumbers(ITERATOR begin, ITERATOR end);
		class GeneralException: public std::exception {
			const char *what() const throw() {
				return "Error";
			}
		};
		class SetFullException : public std::exception {
			const char * what() const throw() {
				return "Set is Full!";
			}
		};
		class NotEnoughElementException : public std::exception {
			const char * what() const throw() {
				return "Not Enough Elements";
			}
		};
};
#endif