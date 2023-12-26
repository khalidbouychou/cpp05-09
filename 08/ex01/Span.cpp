/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:21:36 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/26 13:23:55 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0){}

Span::Span(unsigned int n){
    if ((int)n < 1)
        throw std::out_of_range("n must be > 0");
    this->n = n;
}

Span::Span(Span const &src){*this = src;}

Span::~Span(){}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->n = rhs.n;
        this->v = rhs.v;
    }
    return (*this);
}
//------------------------------------------------------------------------------------------
void Span::addNumber(int n)
{
    if (this->v.size() < this->n)
        this->v.push_back(n);
    else
        throw std::out_of_range("Out of range");
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->v.size() + std::distance(begin, end) > this->n)
        throw std::out_of_range("Out of range");
    this->v.insert(this->v.end(), begin, end);
}
//------------------------------------------------------------------------------------------

int Span::shortestSpan()
{
    if (this->v.size() < 2)
        throw Span::NoSpanException();
    std::sort(this->v.begin(), this->v.end());
    int min = this->v[1] - this->v[0];
    for (unsigned int i = 2; i < this->v.size(); i++)
        if (this->v[i] - this->v[i - 1] < min)
            min = this->v[i] - this->v[i - 1];
    return (min);
}

int Span::longestSpan()
{
    if (this->v.size() < 1)
        throw Span::NoSpanException();
    std::sort(this->v.begin(), this->v.end());
    return (this->v[this->v.size() - 1] - this->v[0]);
}

const char *Span::NoSpanException::what() const throw()
{
    return ("No span to find");
}
