/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:56:16 by lmaresov          #+#    #+#             */
/*   Updated: 2025/02/21 09:56:18 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include <fstream>

// const int _required_sign_grade = 145;
// const int _required_execute_grade = 137;

ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("ShrubberyCreationForm", ShrubberyCreationForm::_required_sign_grade,
    ShrubberyCreationForm::_required_execute_grade)
{
    this->_target = "unknown target";
    std::cout << "default ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): 
    AForm("ShrubberyCreationForm", ShrubberyCreationForm::_required_sign_grade,
    ShrubberyCreationForm::_required_execute_grade)
{
    this->_target = target;
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other):
    AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    if (this == &other)
        return *this;
    this->_target = other._target;
    return *this;
}

const std::string & ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::ExecuteForm() const {
    std::string file_name = this->_target + "_shubbery";
    std::ofstream out_file(file_name.c_str());
    if (!out_file)
    {
        std::cerr << "Error: while opening file" << file_name << std::endl;
        return;
    }
    out_file << "    *    \n";
    out_file << "   ***   \n";
    out_file << "  *****  \n";
    out_file << " ******* \n";
    out_file << "*********\n";
    out_file << "    |    \n";
    out_file.close();
    std::cout << "Ascii tree is in the file" << file_name << std::endl;  
}