#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		MutantStack() {};
		MutantStack(const MutantStack &other) : std::stack<T>(other){};
		MutantStack &operator=(const MutantStack &other) {
			if (this == &other)
				return (*this);
			std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack() {};
		
	
		iterator begin() { return std::stack<T>::c.begin(); }
		const_iterator begin() const { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		const_iterator end() const { return std::stack<T>::c.end(); }
		iterator rbegin() { return std::stack<T>::c.begin(); }
		const_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
		iterator rend() { return std::stack<T>::c.rend(); }
		const_iterator rend() const { return std::stack<T>::c.rend(); }
};

#endif