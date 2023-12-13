/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:21:31 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/13 02:29:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int _n;
    std::vector<int> _v;
    Span();
public:

    Span(unsigned int n);
    Span(Span const &src);
    ~Span();

    Span &operator=(Span const &rhs);

    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
    class NoSpanException : public std::exception
    {
        public:
            NoSpanException();
            NoSpanException(NoSpanException const &src);
            ~NoSpanException() throw();

            NoSpanException &operator=(NoSpanException const &rhs);

            virtual const char *what() const throw();
    };
};

// std::ostream &operator<<(std::ostream &o, Span const &rhs);