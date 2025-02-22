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


// void createForm(std::string name, int req_sign_grade, int req_exec_grade)
// {
//     try
//     {
//         AForm form(name, req_sign_grade, req_exec_grade);
//         return;
//     }
//     catch(AForm::GradeTooHighException & e)
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//     catch(AForm::GradeTooLowException & e)
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
// }

int main (void)
{
    ShrubberyCreationForm shrubbery("shrubery_target");
    RobotomyRequestForm robotomy("robotomy_target");
    PresidentialPardonForm president("president_target");
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 145);
    Bureaucrat normal("Normal", 72);
    std::cout << "_____________________________________" << std::endl;
    std::cout << "executing not signed forms" << std::endl;
    
    try
    {
        intern.executeForm(shrubbery);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        normal.executeForm(shrubbery);
        normal.executeForm(robotomy);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        boss.executeForm(shrubbery);
        boss.executeForm(robotomy);
        boss.executeForm(president);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "_____________________________________" << std::endl;
    std::cout << "signing forms" << std::endl;
    
    try
    {
        intern.signForm(shrubbery);
        intern.signForm(robotomy);

    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        normal.signForm(shrubbery);
        normal.signForm(robotomy);
        normal.signForm(president);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        boss.signForm(shrubbery);
        boss.signForm(robotomy);
        boss.signForm(president);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "_____________________________________" << std::endl;
    std::cout << "executing signed forms" << std::endl;
    try
    {
        intern.executeForm(shrubbery);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        normal.executeForm(shrubbery);
        normal.executeForm(robotomy);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        boss.executeForm(shrubbery);
        boss.executeForm(robotomy);
        boss.executeForm(president);
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    std::cout << "_____________________________________" << std::endl;
    
    // std::cout << "_____________________________________" << std::endl;
    // std::cout << "testing constructors exeptions" << std::endl;
    // createForm("TopForm", 1, 1);
    // createForm("InternForm",150, 150);
    // createForm("NormalForm", 50, 40);
    // createForm("ToLowFormSign", 151, 10);
    // createForm("ToLowFormExec", 10, 151);
    // createForm("ToHighFormSign", 0, 10);
    // createForm("ToHighFormExec", 10, 0);

    // std::cout << "_____________________________________" << std::endl;
    // std::cout << "creating forms" << std::endl;
    // Form def_form;
    // Form topForm("TopForm", 1, 10);
    // Form internForm("InternForm",150, 150);
    // Form normalForm("NormalForm", 50, 40);
    // std::cout << "_____________________________________" << std::endl;
    // std::cout << "sign forms" << std::endl;
    // Bureaucrat boss("Boss", 1);
    // Bureaucrat intern("Intern", 150);
    // Bureaucrat normal("Normal", 40);
    
    // try
    // {
    //     intern.signForm(internForm);
    //     intern.signForm(normalForm);

    // }
    // catch(Form::GradeTooHighException & e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // catch(Form::GradeTooLowException & e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // try
    // {
    //     normal.signForm(internForm);
    //     normal.signForm(normalForm);
    //     normal.signForm(topForm);
    // }
    // catch(Form::GradeTooHighException & e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // catch(Form::GradeTooLowException & e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // try
    // {
    //     boss.signForm(internForm);
    //     boss.signForm(normalForm);
    //     boss.signForm(topForm);
    // }
    // catch(Form::GradeTooHighException & e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // catch(Form::GradeTooLowException & e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // std::cout << "_____________________________________" << std::endl;
    // std::cout << "asignment forms" << std::endl;
    // std::cout << "Form: " << def_form.getName();
    // std::cout << " is sign: " << def_form.getIsSigned() << std::endl;
    // def_form = internForm;
    // std::cout << "Form: " << def_form.getName();
    // std::cout << " is sign: " << def_form.getIsSigned() << std::endl;
    

    return 0;
}