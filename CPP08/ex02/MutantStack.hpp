//
// Created by Juanito on 20/02/2024.
//

#ifndef CPP_MODULES_42_MUTANTSTACK_HPP
#define CPP_MODULES_42_MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>
# include <algorithm>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    private:

    public:
        MutantStack() {};
        ~MutantStack() {};

        MutantStack(const MutantStack& src) {
            *this = src;
        }
        MutantStack &operator=(const MutantStack& rhs) {
            if (this != &rhs) {
                std::stack<T, Container>::operator=(this, rhs);
            }
            return (*this);
        }

        typedef typename Container::iterator iterator;
        iterator begin(void) {
            return (this->c.begin());
        }
        iterator end(void) {
            return (this->c.end());
        }
};

#endif //CPP_MODULES_42_MUTANTSTACK_HPP
