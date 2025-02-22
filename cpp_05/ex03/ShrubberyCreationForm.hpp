/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:54:31 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 09:54:34 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
    std::string _target;

public:
    static const int _required_sign_grade = 145;
    static const int _required_execute_grade = 137;

    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm & other);
    
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm & other);
    const std::string & getTarget() const;
    void ExecuteForm() const;
     
};

#endif