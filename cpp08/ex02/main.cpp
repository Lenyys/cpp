/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 08:43:34 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/06 08:43:35 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);


    std::cout << "list-------------------------------" << std::endl;
    std::list<int> my_list;
    my_list.push_back(5);
    my_list.push_back(17);
    std::cout << my_list.back() << std::endl;
    my_list.pop_back();
    std::cout << my_list.size() << std::endl;
    my_list.push_back(3);
    my_list.push_back(5);
    my_list.push_back(737);
    my_list.push_back(0);
    std::list<int>::iterator itl = my_list.begin();
    std::list<int>::iterator itel = my_list.end();
    ++itl;
    --itl;
    while (itl != itel)
    {
    std::cout << *itl << std::endl;
    ++itl;
    }
    return 0;
}