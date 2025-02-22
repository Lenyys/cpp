/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:52:12 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/22 11:52:13 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <string>
#include "AForm.hpp"

class Intern
{
private:
    
public:
    Intern();
    Intern(const Intern & other);
    ~Intern();

    Intern& operator=(const Intern &other);

    AForm * makeForm(const std::string &form_name, const std::string &target);
    
    class NotFormNameError: public std::exception {
        public:
            virtual const char * what() const throw();
    };
};


#endif
