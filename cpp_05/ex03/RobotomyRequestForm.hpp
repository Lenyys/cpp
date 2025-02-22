/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestsForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:56:39 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 09:56:41 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
    std::string _target;
public:
    static const int _required_sign_grade = 72;
    static const int _required_execute_grade = 45;

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm( const RobotomyRequestForm & other);
    
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm & other);
    const std::string & getTarget() const;
    void ExecuteForm() const;
     
};

#endif