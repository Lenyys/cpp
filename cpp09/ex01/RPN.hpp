/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:36:24 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/21 07:36:26 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN
{
    private:
        std::stack<int> stack;
        int doOperation(int a, int b, const std::string &op);
        bool isOperator(const std::string & str);
        bool isNumber(const std::string & str);

    public:
        RPN();
        RPN(const RPN & other);
        RPN &operator=(const RPN & other);
        ~RPN();
        void doTheMath(const std::string & expression);
        


};


#endif