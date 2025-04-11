/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:36:17 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/21 07:36:19 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int RPN::doOperation(int a, int b, const std::string &op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
        return a / b;
    return 0;
}

bool RPN::isOperator(const std::string & str)
{
    return str == "+" || str == "-" || str == "*" || str == "/";
}
        
bool RPN::isNumber(const std::string & str)
{
    return str.length() == 1 && str[0] >= '0' && str[0] <= '9';
}

RPN::RPN() {}

RPN::RPN(const RPN & other) {
    stack = other.stack;
}
        
RPN &RPN::operator=(const RPN & other) {
    if (this != &other)
        stack = other.stack;
    return *this;
}
        
RPN::~RPN() {}
        
void RPN::doTheMath(const std::string & expression)
{
    std::stringstream stream(expression);
    std::string token;

    while (stream >> token)
    {
        if (isNumber(token))
            stack.push(std::atoi(token.c_str()));
        else if (isOperator(token))
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: invalid expression" << std::endl;
                return ;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            if (token == "/" && b == 0)
            {
                std::cerr << "Error: division by 0" << std::endl;
                return ;
            } 
            int operationResult = doOperation(a, b, token);
            stack.push(operationResult);
        }
        else
        {
            std::cerr << "Error: invalid expresion" << std::endl;
            return ;
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: invalid expresion" << std::endl;
        return ;
    }
    std::cout << stack.top() << std::endl;
}
