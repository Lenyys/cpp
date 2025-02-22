/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:29:00 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 08:29:02 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    const int _required_sign_grade;
    const int _required_execute_grade;
    bool _is_signed;

public:
    Form();
    Form(const std::string &name, const int _required_sign_grade, const int _required_execute_grade);
    Form(const Form & other);
    ~Form();

    Form& operator=(const Form &other);
    void beSigned(const Bureaucrat &bureaucrat);

    const std::string getName() const;
    int getRequiredSignGrade() const;
    int getRequiredExecuteGrade() const;
    bool getIsSigned() const;

    class GradeTooLowException: public std::exception {
        public:
            virtual const char * what() const throw();
    };

    class GradeTooHighException: public std::exception {
        public:
            virtual const char * what() const throw();
    };

};

std::ostream & operator<<(std::ostream & os, const Form & obj);
#endif
