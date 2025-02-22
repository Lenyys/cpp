/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:52:05 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/22 11:52:06 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


Intern::Intern() {
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern & other) {
    std::cout << "Intern copy constructor" << std::endl;
    *this = other;
}

Intern::~Intern() {
    std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(const Intern &other) {
    std::cout << "Intern copy asigment operator" << std::endl;
    (void)other;
    return *this;
}


AForm * Intern::makeForm(const std::string &form_name, const std::string &target) {
    std::string form_names[3] = {"shrubbery creation", "robotomy request","presidential pardon" };
    int i = 0;
    while (i < 3)
    {
        if (form_names[i] == form_name)
            break;
        i++;
    }
    switch (i) 
    {
        case 0:
            std::cout << "Intern creates shrubbery form" << std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates robotomy form" << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates presidential form" << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            throw NotFormNameError();
    }
}

const char * Intern::NotFormNameError::what() const throw() {
    return ("This type of form dosn't exist");
}