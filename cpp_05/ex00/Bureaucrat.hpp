/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:33:46 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 06:33:48 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    static const int heighest_grade;
    static const int lowest_grade; 

public: 
    Bureaucrat();
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string & getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    static int getHeighestGrade();
    static int getLowestGrade();

    class GradeTooHighException: public std::exception {
        public:
            virtual const char * what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public:
            virtual const char * what() const throw();
    };
};
std::ostream & operator<<(std::ostream &os, const Bureaucrat & src);

#endif