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

void createBureaucrat(std::string name, int grade)
{
    try
    {
        Bureaucrat name_grade_bureaucrat(name, grade);
        return;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}
Bureaucrat* createReturnBureaucrat(std::string name, int grade)
{
    try
    {
        return new Bureaucrat(name, grade);
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return NULL;
}

int main (void)
{
    std::cout << "_____________________________________" << std::endl;
    std::cout << "testing constructors exeptions" << std::endl;
    createBureaucrat("Boss", 1);
    createBureaucrat("Intern", 150);
    createBureaucrat("ToHight", 0);
    createBureaucrat("ToHight2", -2);
    createBureaucrat("ToLow", 151);
    createBureaucrat("ToLow2", 200);
    std::cout << "_____________________________________" << std::endl;
    
    std::cout << "creating bureaucrats" << std::endl;
    Bureaucrat def_bureacrat;
    Bureaucrat george("George");
    Bureaucrat robert("Robert", 20);
    Bureaucrat* boss = createReturnBureaucrat("Boss", 1);
    boss->getName();
    std::cout << "_____________________________________" << std::endl;
    std::cout << "asignment bureaucrats" << std::endl;
    std::cout << "Bureaucrat: " << def_bureacrat.getName();
    std::cout << " grade: " << def_bureacrat.getGrade() << std::endl;
    def_bureacrat = robert;
    std::cout << "Bureaucrat: " << def_bureacrat.getName();
    std::cout << " grade: " << def_bureacrat.getGrade() << std::endl;
    std::cout << "_____________________________________" << std::endl;
    std::cout << "copy bureaucrats" << std::endl;
    Bureaucrat copy_robert(robert);
    std::cout << "Bureaucrat: " << copy_robert.getName();
    std::cout << " grade: " << copy_robert.getGrade() << std::endl;
    Bureaucrat copy_boss(*boss);
    std::cout << "Bureaucrat: " << copy_boss.getName();
    std::cout << " grade: " << copy_boss.getGrade() << std::endl;
    delete boss;


    std::cout << "_____________________________________" << std::endl;
    std::cout << "grade increment and decrement" << std::endl;
    Bureaucrat bureaucratMax("max", 1);
    try {
        bureaucratMax.decrementGrade();
        std::cout << "Bureaucrat: " << bureaucratMax.getName();
        std::cout << " grade: " << bureaucratMax.getGrade() << std::endl;
        bureaucratMax.incrementGrade();
        std::cout << "Bureaucrat: " << bureaucratMax.getName();
        std::cout << " grade: " << bureaucratMax.getGrade() << std::endl;
        bureaucratMax.incrementGrade();
        std::cout << "Bureaucrat: " << bureaucratMax.getName();
        std::cout << " grade: " << bureaucratMax.getGrade() << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "Bureaucrat: " << bureaucratMax.getName();
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "Bureaucrat: " << bureaucratMax.getName();
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "_____________________________________" << std::endl;
    Bureaucrat bureaucratMin("Min", 150);
    try {
        bureaucratMin.incrementGrade();
        std::cout << "Bureaucrat: " << bureaucratMin.getName();
        std::cout << " grade: " << bureaucratMin.getGrade() << std::endl;
        bureaucratMin.decrementGrade();
        std::cout << "Bureaucrat: " << bureaucratMin.getName();
        std::cout << " grade: " << bureaucratMin.getGrade() << std::endl;
        bureaucratMin.decrementGrade();
        std::cout << "Bureaucrat: " << bureaucratMin.getName();
        std::cout << " grade: " << bureaucratMin.getGrade() << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "Bureaucrat: " << bureaucratMin.getName();
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "Bureaucrat: " << bureaucratMin.getName();
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "_____________________________________" << std::endl;
    
    
    std::cout << Bureaucrat::getHeighestGrade() << std::endl;
    std::cout << Bureaucrat::getLowestGrade() << std::endl;
    std::cout << "_____________________________________" << std::endl;
    
    return 0;
}