/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:02:24 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/28 08:02:25 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>

Base * generate(void)
{
    srand(time(0));
    int num = std::rand() % 3;

    if (num == 0)
    {
        std::cout << "creating instance A" << std::endl;
        return (new A);
    }
    else if (num == 1)
    {
        std::cout << "creating instance B" << std::endl;
        return (new B);
    }
    else if (num == 2)
    {
        std::cout << "creating instance C" << std::endl;
        return(new C);
    }
    return (NULL);
}


void identify(Base* p)
{
    if (!p)
    {
        std::cout << "pointer: null pointer" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
    {
        std::cout << "pointer: instance of A class" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "pointer: instance of B class" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "pointer: instance of C class" << std::endl;
    } 
    else
    {
        std::cout << "pointer: unknown" << std::endl; 
    }  
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "reference: " << a << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "reference: " << b << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                std::cout << "reference: " << c << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "reference: unknown" << std::endl;
            }
        }
    }    
}

int main(void)
{
    Base *instance;

    instance = generate();
    identify(instance);
    identify(*instance);
    delete instance;

    return (0);
}