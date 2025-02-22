/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:57:06 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 09:57:09 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    std::string _target;
public:
    static const int _required_sign_grade = 25;
    static const int _required_execute_sign = 5;

    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm( const PresidentialPardonForm & other);
    
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm & other);
    const std::string & getTarget() const;
    void ExecuteForm() const;
     
};

#endif