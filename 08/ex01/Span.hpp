/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:21:31 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/26 13:28:05 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int n;
        std::vector<int> v;
    public:
        Span();
        Span(Span const &src);
        Span(unsigned int n);
        ~Span();
        Span &operator=(Span const &obj);


        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        class NoSpanException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};
