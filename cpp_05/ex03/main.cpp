/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:53:35 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 06:53:37 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main (void)
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* wrongFormName;
    Bureaucrat boss("Boss", 1);
    std::cout << "_____________________________________________" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << "_____________________________________________" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bob");
    std::cout << "_____________________________________________" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Boss1");
    std::cout << "_____________________________________________" << std::endl;
    try
    {
        wrongFormName = someRandomIntern.makeForm("wrong", "Target");
    }
    catch(Intern::NotFormNameError & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "_____________________________________________" << std::endl;
    try
    {
        boss.executeForm(*rrf);
        boss.executeForm(*scf);
        boss.executeForm(*ppf);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "_____________________________________________" << std::endl;
    try
    {
        boss.signForm(*rrf);
        boss.signForm(*scf);
        boss.signForm(*ppf);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "_____________________________________________" << std::endl;
    try
    {
        boss.executeForm(*rrf);
        boss.executeForm(*scf);
        boss.executeForm(*ppf);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "_____________________________________________" << std::endl;
    delete rrf;
    delete scf;
    delete ppf;
    return 0;
}