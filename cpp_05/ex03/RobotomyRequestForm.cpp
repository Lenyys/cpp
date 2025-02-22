/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestsForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:56:46 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 09:56:47 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): 
    AForm("RobotomyRequestForm", RobotomyRequestForm::_required_sign_grade,
    RobotomyRequestForm::_required_execute_grade)
{
    this->_target = "unknown target";
    std::cout << "default RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): 
    AForm("RobotomyRequestForm", RobotomyRequestForm::_required_sign_grade,
    RobotomyRequestForm::_required_execute_grade)
{
    this->_target = target;
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & other):
    AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    if (this == &other)
        return *this;
    this->_target = other._target;
    return *this;
}

const std::string & RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::ExecuteForm() const {
    std::cout << this->_target << "some drilling noises" << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    }
    else
        std::cout << "robotomy failed" << std::endl;
}