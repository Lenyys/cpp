/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:33:37 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 06:33:39 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int Bureaucrat::heighest_grade = 1;
const int Bureaucrat::lowest_grade = 150; 

Bureaucrat::Bureaucrat(): _name("unknown"), _grade(150) {
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
    _name(name), _grade(grade) {
        if (grade > 150)
        {
            throw(Bureaucrat::GradeTooLowException());
            return;
        }
        else if ( grade < 1)
        {
            throw(Bureaucrat::GradeTooHighException());
            return;
        }
        std::cout << "Bureaucrat " << this->_name << " with grade " << this->getGrade(); 
        std::cout << " was created" <<  std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name): _name(name), _grade(150) {
    std::cout << "Bureaucrat " << this->_name << " with lowest grade was created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor for " << this->_name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy asignment operator" << std::endl;
    if (this == &other)
        return *this;
    this->_grade = other._grade;
    return *this;
}

const std::string & Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
    {
        throw(Bureaucrat::GradeTooHighException());
        return;
    }
    this->_grade -= 1;
    std::cout << this->_name << " was promoted to grade " << this->_grade << std::endl;
    return;
}

void Bureaucrat::decrementGrade() {
     if (this->_grade + 1 > 150)
    {
        throw(Bureaucrat::GradeTooLowException());
        return;
    }
    this->_grade += 1;
    std::cout << this->_name << " was demoted to grade " << this->_grade << std::endl;
    return;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat's grade is to hight.");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat's grade is to low.");
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & src) {
    os << "Bureaucrat: " << src.getName() << ", grade: " << src.getGrade();
    return os;
}

int Bureaucrat::getHeighestGrade()
{
    return heighest_grade;
}

int Bureaucrat::getLowestGrade()
{
    return lowest_grade;
}

void Bureaucrat::signForm(AForm & form) const {
    try
    {
        form.beSigned(*this);
        // std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception const & e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName();
        std::cout << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try
    {
        form.execute(*this);
        // std::cout << *this << " executed" << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't execute because of: " << e.what() << std::endl;
    }
    
}