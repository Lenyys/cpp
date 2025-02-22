/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:28:49 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 08:28:53 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm(): _name("unknown"), 
    _required_sign_grade(1),
    _required_execute_grade(1),
    _is_signed(false) {
        std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string &name, const int _required_sign_grade, const int _required_execute_grade):
    _name(name),
    _required_sign_grade(_required_sign_grade),
    _required_execute_grade(_required_execute_grade), 
    _is_signed(false) {
        if (this->_required_sign_grade > 150 || this->_required_execute_grade > 150)
        {
            throw(AForm::GradeTooLowException());
            return;
        }
        else if (this->_required_sign_grade < 1 || this->_required_execute_grade < 1)
        {
            throw(AForm::GradeTooHighException());
            return;
        }
        std::cout << "AForm " << this->_name << " with required sign grade " << this->getRequiredSignGrade(); 
        std::cout << " and required execute grade " << this->getRequiredExecuteGrade() << " was created" <<  std::endl;

}

AForm::AForm(const AForm & other): _name(other._name), 
    _required_sign_grade(other._required_sign_grade),
    _required_execute_grade(other._required_execute_grade),
    _is_signed(false)  {
    std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor for " << this->_name << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
    std::cout << "AForm copy asignment operator" << std::endl;
    if (this == &other)
        return *this;
    this->_is_signed = other._is_signed;
    return *this;

}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_is_signed)
    {
        std::cout << "AForm: " << this->_name << " is already signed" << std::endl;
    }
    else
    {
        if (bureaucrat.getGrade() > this->getRequiredSignGrade())
            throw (AForm::GradeTooHighException());
        this->_is_signed = true;
        std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
    }
}

void AForm::execute(const Bureaucrat & bureaucrat) const {
    if (this->_is_signed == false)
    {
        throw (AForm::FormNotSignedException());
    }
    else if (bureaucrat.getGrade() > this->getRequiredExecuteGrade())
    {
        throw (AForm::GradeTooHighException());
    }
    else
    {
        std::cout << bureaucrat.getName() << " executed " << this->getName() << " form" << std::endl;
        this->ExecuteForm();
    }
    
}

const std::string AForm::getName() const {
    return this->_name;
}

int AForm::getRequiredSignGrade() const {
    return this->_required_sign_grade;
}

int AForm::getRequiredExecuteGrade() const {
    return this->_required_execute_grade;
}

bool AForm::getIsSigned() const {
    return this->_is_signed;
}

const char * AForm::GradeTooLowException::what() const throw() {
    return ("AForm grade is to low.");
}

const char * AForm::GradeTooHighException::what() const throw() {
    return ("AForm grade is to high.");
}

const char*AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed. So it can't be executed");
}

std::ostream & operator<<(std::ostream & os, const AForm & obj) {
    os << obj.getName() << (obj.getIsSigned() ? " - signed" : " - unsigned")
        << "Lowest grade to sign: " << obj.getRequiredSignGrade()
        << "Lowest grade to execute: " << obj.getRequiredExecuteGrade();
    return os;
}


