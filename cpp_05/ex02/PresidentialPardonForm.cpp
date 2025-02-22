/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:57:14 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 09:57:15 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("Presidential Pardon Form", PresidentialPardonForm::_required_sign_grade,
    PresidentialPardonForm::_required_execute_sign)
{
    this->_target = "unknown target";
    std::cout << "default Presidential Pardon Form constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): 
    AForm("Presidential Pardon Form", PresidentialPardonForm::_required_sign_grade,
    PresidentialPardonForm::_required_execute_sign)
{
    this->_target = target;
    std::cout << "Presidential Pardon Form constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & other):
    AForm(other), _target(other._target) {
    std::cout << "Presidential Pardon Form copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Pardon Form destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    if (this == &other)
        return *this;
    this->_target = other._target;
    return *this;
}

const std::string & PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::ExecuteForm() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
