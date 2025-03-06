/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:01:07 by lmaresov          #+#    #+#             */
/*   Updated: 2025/03/01 16:01:08 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <time.h>
#include <cstdlib>

#define MAX_VAL 750
int main() {
    

    std::cout << "testing array of integers" << std::endl;
    try {
        std::cout << "Test: constructor without parametr" << std::endl;
        Array<int> arr1;
        std::cout << "Size arr1: " << arr1.size() << std::endl;
        std::cout << "empty array: " << arr1 << std::endl;

        std::cout << "Test: constructor with parametr " << std::endl;
        Array<int> arr2(5);
        std::cout << "Size arr2: " << arr2.size() << std::endl;
        std::cout << "array2: " << arr2 << std::endl;

        std::cout << "Test: copy constructor " << std::endl;
        Array<int> arr3(arr2);
        std::cout << "Size arr3: " << arr3.size() << std::endl;
        std::cout << "array3: " << arr3 << std::endl;
        std::cout << "----------------------------------" << std::endl;
        arr2[1] = 10;
        arr3[3] = 3;
        std::cout << "array2: " << arr2 << std::endl;
        std::cout << "array3: " << arr3 << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Test: assignement operator " << std::endl;
        Array<int> arr4;
        arr4 = arr2;
        std::cout << "Size arr4: " << arr4.size() << std::endl;
        std::cout << "array2: " << arr2 << std::endl;
        std::cout << "array4: " << arr4 << std::endl;
        std::cout << "----------------------------------" << std::endl;
        arr2[4] = 10;
        arr4[0] = 3;
        std::cout << "array2: " << arr2 << std::endl;
        std::cout << "array4: " << arr4 << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Test: indexing array " << std::endl;
        arr2[2] = 10;
        std::cout << "arr2: " << arr2 << std::endl;
        try {
            std::cout << "arr2[2]= " << arr2[2] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
        std::cout << "Test: exception- wrong index " << std::endl;
        try {
            std::cout << arr2[10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        try {
            std::cout << arr2[-10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "----------------------------------" << std::endl;
    std::cout << "testing array of strings" << std::endl;
    try {
        std::cout << "Test: constructor without parametr" << std::endl;
        Array<std::string> arr1;
        std::cout << "Size arr1: " << arr1.size() << std::endl;
        std::cout << "array1: " << arr1 << std::endl;
        std::cout << "Test: constructor with parametr " << std::endl;
        Array<std::string> arr2(5);
        std::cout << "Size arr2: " << arr2.size() << std::endl;
        std::cout << "array2: " << arr2 << std::endl;
        std::cout << "Test: copy constructor " << std::endl;
        Array<std::string> arr3(arr2);
        std::cout << "Size arr3: " << arr3.size() << std::endl;
        std::cout << "array3: " << arr3 << std::endl;
        std::cout << "Test: assignement operator " << std::endl;
        Array<std::string> arr4;
        arr4 = arr2;
        std::cout << "Size arr4: " << arr4.size() << std::endl;
        std::cout << "array4: " << arr4 << std::endl;
        std::cout << "Test: indexing array " << std::endl;
        arr2[2] = "Hello";
        std::cout << "Array: " << arr2 << std::endl;
        try {
            std::cout << "arr[2]= " << arr2[2] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
        std::cout << "Test: exception- wrong index " << std::endl;
        try {
            std::cout << arr2[10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        try {
            std::cout << arr2[-10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "----------------------------------" << std::endl;
    std::cout << "testing array of doubles" << std::endl;
    try {
        std::cout << "Test: constructor without parametr" << std::endl;
        Array<double> arr1;
        std::cout << "Size arr1: " << arr1.size() << std::endl;

        std::cout << "Test: constructor with parametr " << std::endl;
        Array<double> arr2(5);
        std::cout << "Size arr2: " << arr2.size() << std::endl;

        std::cout << "Test: copy constructor " << std::endl;
        Array<double> arr3(arr2);
        std::cout << "Size arr3: " << arr3.size() << std::endl;
 
        std::cout << "Test: assignement operator " << std::endl;
        Array<double> arr4;
        arr4 = arr2;
        std::cout << "Size arr4: " << arr4.size() << std::endl;

        std::cout << "Test: indexing array " << std::endl;
        for( unsigned int i = 0; i < arr2.size(); i++ )
        {
            arr2[i] = i + 0.1;
        }
        std::cout << "Array: " << arr2 << std::endl;
        try {
            std::cout << "arr[2]= " << arr2[2] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }   
        std::cout << "Test: exception- wrong index " << std::endl;
        try {
            std::cout << arr2[10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        try {
            std::cout << arr2[-10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}