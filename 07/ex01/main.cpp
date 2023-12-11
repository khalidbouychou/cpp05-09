/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:28 by khbouych          #+#    #+#             */
/*   Updated: 2023/12/11 23:46:12 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

class Test
{
  private:
    int n;
  public:
    Test( void ) : n( 1337 ) { return; }
    int getn( void ) const { return this->n; }
};

std::ostream & operator<<( std::ostream & o, Test const & rhs )
{
  o << rhs.getn();
  return o;
}

template< typename T >
void display( T& data )
{
  std::cout << data << std::endl;
  return;
}

int main() {
  std::string stab[6] = { "Hello", "World", "!" , "How", "Are", "You" };
  Test Ttab[2];

  iter( Ttab, 2, display<Test> );
  iter( stab, 6, display<std::string> );

  return 0;
}
