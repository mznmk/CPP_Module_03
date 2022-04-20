/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:42:10 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 10:44:36 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

// =========================== [ private ] method =========================== //

// ----------------------------- set parameter ------------------------------ //

void        FragTrap::_initParameter(const std::string name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _canAction = true;
}

void        FragTrap::_copyParameter(const FragTrap &frag)
{
    _name = frag._name;
    _hitPoints = frag._hitPoints;
    _energyPoints = frag._energyPoints;
    _attackDamage = frag._attackDamage;
    _canAction = frag._canAction;
}

// ================== [ public ] constructor / destructor =================== //

// -------------------------- default contsructor --------------------------- //

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "[FragTrap] Default constructor called" << std::endl;
    _initParameter("");
}

// ------------------------- conberting contsructor ------------------------- //

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "[FragTrap] Conberting constructor called" << std::endl;
    _initParameter(name);
}

// ---------------------------- copy contsructor ---------------------------- //

FragTrap::FragTrap(const FragTrap &frag)
{
    std::cout << "[FragTrap] Copy constructor called" << std::endl;
    _copyParameter(frag);
}

// ------------------------------- destructor ------------------------------- //

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] Destructor called" << std::endl;
}

// ========================== [ public ] operator =========================== //

// ------------------------ copy assignment operator ------------------------ //

FragTrap    &FragTrap::operator=(const FragTrap &frag)
{
   std::cout << "[FragTrap] Copy assignment operator called" << std::endl;
   if (this != &frag) {
       _copyParameter(frag);
   }
   return *this;
}

// =========================== [ public ] method ============================ //

/*!
** @brief   command high fives guy
*/
void        FragTrap::highFivesGuys()
{
    std::cout << "FragTrap <" << _name << "> ";
    std::cout << "would love to high fives!" << std::endl;
}
