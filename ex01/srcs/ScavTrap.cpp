/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:42:10 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/19 17:25:50 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

// =========================== [ private ] method =========================== //

void        ScavTrap::initParameter(const std::string name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _canAction = true;
}

// ================== [ public ] constructor / destructor =================== //

// -------------------------- default contsructor --------------------------- //

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "[ScavTrap] Default constructor called" << std::endl;
    initParameter("");
}

// ------------------------- conberting contsructor ------------------------- //

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "[ScavTrap] Conberting constructor called" << std::endl;
    initParameter(name);
}

// ---------------------------- copy contsructor ---------------------------- //

ScavTrap::ScavTrap(const ScavTrap &scav)
{
    std::cout << "[ScavTrap] Copy constructor called" << std::endl;
    _name = scav._name;
    _hitPoints = scav._hitPoints;
    _energyPoints = scav._energyPoints;
    _attackDamage = scav._attackDamage;
    _canAction = scav._canAction;

}

// ------------------------------- destructor ------------------------------- //

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap] Destructor called" << std::endl;
}

// ========================== [ public ] operator =========================== //

// ------------------------ copy assignment operator ------------------------ //

ScavTrap    &ScavTrap::operator=(const ScavTrap &scav)
{
   std::cout << "[ScavTrap] Copy assignment operator called" << std::endl;
   if (this != &scav) {
       _name = scav._name;
       _hitPoints = scav._hitPoints;
       _energyPoints = scav._energyPoints;
       _attackDamage = scav._attackDamage;
       _canAction = scav._canAction;
   }
   return *this;
}

// =========================== [ public ] method ============================ //

void        ScavTrap::attack(const std::string &target)
{
    // already dead ?
    if (_hitPoints == 0) {
        std::cout << "ScavTrap <" << _name << "> is already dead ...";
        std::cout << std::endl;
        _canAction = false;
        return;
    }
    // have energy point ?
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap <" << _name << "> has no energy points ...";
        std::cout << std::endl;
        _canAction = false;
        return;
    }
    // attack
    _energyPoints -= 1;
    std::cout << "ScavTrap <" << _name << "> ";
    std::cout << "attacks <" << target << ">, ";
    std::cout << "causing <" << _attackDamage << "> points of damage!";
    std::cout << std::endl;
}

void        ScavTrap::guardGate()
{
    std::cout << "ScavTrap <" << _name << "> ";
    std::cout << "enter in Gate Keeper mode !" << std::endl;
}
