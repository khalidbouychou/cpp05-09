/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:10:05 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/11 09:46:19 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

// int main() {
//     int num1 = 5, num2 = 10;
//     std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
//     swap(num1, num2);
//     std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

//     int result1 = min(num1, num2);
//     std::cout << "Minimum: " << result1 << std::endl;

//     int result2 = max(num1, num2);
//     std::cout << "Maximum: " << result2 << std::endl;

//     return 0;
// }