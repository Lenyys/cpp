/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 08:43:53 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 08:43:54 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T> 
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

        const_iterator begin() const {
            return this->c.begin();
        }
        const_iterator end() const {
            return this->c.end();
        }
};
