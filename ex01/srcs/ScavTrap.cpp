/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:42:10 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 11:15:27 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

// =========================== [ private ] method =========================== //

// ----------------------------- set parameter ------------------------------ //

void        ScavTrap::_initParameter(const std::string name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _canAction = true;
}

void        ScavTrap::_copyParameter(const ScavTrap &scav)
{
    _name = scav._name;
    _hitPoints = scav._hitPoints;
    _energyPoints = scav._energyPoints;
    _attackDamage = scav._attackDamage;
    _canAction = scav._canAction;
}

// ----------------------------- print message ------------------------------ //

bool        ScavTrap::_setPrintNoLife()
{
    if (_hitPoints <= 0) {
        // change state
        _hitPoints = 0;
        _canAction = false;
        // print state
        std::cout << "ScavTrap <" << _name << "> is dead ...";
        std::cout << std::endl;
        return true;
    }
    return false;
}

bool        ScavTrap::_setPrintNoEnergy()
{
    if (_energyPoints <= 0) {
        // change state
        _energyPoints = 0;
        _canAction = false;
        // print message
        std::cout << "ScavTrap <" << _name << "> has no energy points ...";
        std::cout << std::endl;
        return true;
    }
    return false;
}

// ================== [ public ] constructor / destructor =================== //

// -------------------------- default contsructor --------------------------- //

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "[ScavTrap] Default constructor called" << std::endl;
    _initParameter("");
}

// ------------------------- conberting contsructor ------------------------- //

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "[ScavTrap] Conberting constructor called" << std::endl;
    _initParameter(name);
}

// ---------------------------- copy contsructor ---------------------------- //

ScavTrap::ScavTrap(const ScavTrap &scav)
{
    std::cout << "[ScavTrap] Copy constructor called" << std::endl;
    _copyParameter(scav);
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
       _copyParameter(scav);
   }
   return *this;
}

// =========================== [ public ] method ============================ //

/*!
** @brief   command attack
** @param   target  attack target
*/
void        ScavTrap::attack(const std::string &target)
{
    // already dead ?
    if (_setPrintNoLife())
        return;
    // have energy point ?
    if (_setPrintNoEnergy())
        return;
    // attack
    _energyPoints -= 1;
    std::cout << "ScavTrap <" << _name << "> ";
    std::cout << "attacks <" << target << ">, ";
    std::cout << "causing <" << _attackDamage << "> points of damage!";
    std::cout << std::endl;
}

/*!
** @brief   command gate keeper
*/
void        ScavTrap::guardGate()
{
    std::cout << "ScavTrap <" << _name << "> ";
    std::cout << "enter in Gate Keeper mode !" << std::endl;
}
