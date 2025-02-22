/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:28:49 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 08:28:53 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form(): _name("unknown"), 
    _required_sign_grade(1),
    _required_execute_grade(1),
    _is_signed(false) {
        std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string &name, const int _required_sign_grade, const int _required_execute_grade):
    _name(name),
    _required_sign_grade(_required_sign_grade),
    _required_execute_grade(_required_execute_grade), 
    _is_signed(false) {
        if (this->_required_sign_grade > 150 || this->_required_execute_grade > 150)
        {
            throw(Form::GradeTooLowException());
            return;
        }
        else if (this->_required_sign_grade < 1 || this->_required_execute_grade < 1)
        {
            throw(Form::GradeTooHighException());
            return;
        }
        std::cout << "Form " << this->_name << " with required sign grade " << this->getRequiredSignGrade(); 
        std::cout << " and required execute grade " << this->getRequiredExecuteGrade() << " was created" <<  std::endl;

}

Form::Form(const Form & other): _name(other._name), 
    _required_sign_grade(other._required_sign_grade),
    _required_execute_grade(other._required_execute_grade),
    _is_signed(false)  {
    std::cout << "Form copy constructor" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor for " << this->_name << std::endl;
}

Form& Form::operator=(const Form &other) {
    std::cout << "Form copy asignment operator" << std::endl;
    if (this == &other)
        return *this;
    this->_is_signed = other._is_signed;
    return *this;

}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_is_signed)
    {
        std::cout << "Form: " << this->_name << " is already signed" << std::endl;
    }
    else
    {
        if (bureaucrat.getGrade() > this->getRequiredSignGrade())
            throw (Form::GradeTooHighException());
        this->_is_signed = true;
        std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
    }
}

const std::string Form::getName() const {
    return this->_name;
}

int Form::getRequiredSignGrade() const {
    return this->_required_sign_grade;
}

int Form::getRequiredExecuteGrade() const {
    return this->_required_execute_grade;
}

bool Form::getIsSigned() const {
    return this->_is_signed;
}

const char * Form::GradeTooLowException::what() const throw() {
    return ("Form grade is to low.");
}

const char * Form::GradeTooHighException::what() const throw() {
    return ("Form grade is to high.");
}

std::ostream & operator<<(std::ostream & os, const Form & obj) {
    os << obj.getName() << (obj.getIsSigned() ? " - signed" : " - unsigned")
        << "Lowest grade to sign: " << obj.getRequiredSignGrade()
        << "Lowest grade to execute: " << obj.getRequiredExecuteGrade();
    return os;
}


