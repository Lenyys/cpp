/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:29:00 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 08:29:02 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    const int _required_sign_grade;
    const int _required_execute_grade;
    bool _is_signed;
protected:
    virtual void ExecuteForm() const = 0;

public:
    AForm();
    AForm(const std::string &name, const int _required_sign_grade, const int _required_execute_grade);
    AForm(const AForm & other);
    virtual ~AForm();

    AForm& operator=(const AForm &other);
    void beSigned(const Bureaucrat &bureaucrat);

    const std::string getName() const;
    int getRequiredSignGrade() const;
    int getRequiredExecuteGrade() const;
    bool getIsSigned() const;

    void execute(const Bureaucrat & executor) const; 


    class GradeTooLowException: public std::exception {
        public:
            virtual const char * what() const throw();
    };

    class GradeTooHighException: public std::exception {
        public:
            virtual const char * what() const throw();
    };

    class FormNotSignedException: public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream & operator<<(std::ostream & os, const AForm & obj);
#endif
