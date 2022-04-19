/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:33:53 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 08:40:07 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

// =========================== [ private ] method =========================== //

// ----------------------------- set parameter ------------------------------ //

void        ClapTrap::_initParameter(const std::string name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    _canAction = true;
}

void        ClapTrap::_copyParameter(const ClapTrap &clap)
{
    _name = clap._name;
    _hitPoints = clap._hitPoints;
    _energyPoints = clap._energyPoints;
    _attackDamage = clap._attackDamage;
    _canAction = clap._canAction;
}

// ----------------------------- print message ------------------------------ //

bool        ClapTrap::_printNoLifeMessage()
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> is already dead ...";
        std::cout << std::endl;
        _canAction = false;
        return true;
    }
    return false;
}

bool        ClapTrap::_printNoEnergyMessage()
{
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> has no energy points ...";
        std::cout << std::endl;
        _canAction = false;
        return true;
    }
    return false;
}

// ================== [ public ] constructor / destructor =================== //

// -------------------------- default contsructor --------------------------- //

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    _initParameter("");
}

// ------------------------- conberting contsructor ------------------------- //

ClapTrap::ClapTrap(const std::string name)
{
    std::cout << "Conberting constructor called" << std::endl;
    _initParameter(name);
}

// ---------------------------- copy contsructor ---------------------------- //

ClapTrap::ClapTrap(const ClapTrap &clap)
{
    std::cout << "Copy constructor called" << std::endl;
    _copyParameter(clap);
}

// ------------------------------- destructor ------------------------------- //

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

// ========================== [ public ] operator =========================== //

// ------------------------ copy assignment operator ------------------------ //

ClapTrap    &ClapTrap::operator=(const ClapTrap &clap)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &clap) {
        _copyParameter(clap);
    }
    return *this;
}

// =========================== [ public ] method ============================ //

/*!
** @brief   command attack
** @param   target  attack target
*/
void        ClapTrap::attack(const std::string &target)
{
    // already dead ?
    if (_printNoLifeMessage())
        return;
    // have energy point ?
    if (_printNoEnergyMessage())
        return;
    // attack
    _energyPoints -= 1;
    std::cout << "ClapTrap <" << _name << "> ";
    std::cout << "attacks <" << target << ">, ";
    std::cout << "causing <" << _attackDamage << "> points of damage!";
    std::cout << std::endl;
}

/*!
** @brief   command take damage
** @param   amount  amount of damage
*/
void        ClapTrap::takeDamage(unsigned int amount)
{
    // already dead ?
    if (_printNoLifeMessage())
        return;
    // take damage
    _hitPoints -= amount;
    std::cout << "ClapTrap <" << _name << "> ";
    std::cout << "take <" << amount << "> points of damage!";
    std::cout << std::endl;
    // dead now ?
    _printNoLifeMessage();
}

/*!
** @brief   command be repaired
** @param   amount  amount of repaired
*/
void        ClapTrap::beRepaired(unsigned int amount)
{
    // already dead ?
    if (_printNoLifeMessage())
        return;
    // have energy point ?
    if (_printNoEnergyMessage())
        return;
    // be repaired
    _energyPoints -= 1;
    _hitPoints += amount;
    std::cout << "ClapTrap <" << _name << "> ";
    std::cout << "is repaired <" << amount << "> Hit Points!";
    std::cout << std::endl;
}

/*!
** @brief   print Robot status
*/
void        ClapTrap::printStatus()
{
    std::cout << "---------- status ----------" << std::endl;
    std::cout << "Name        : " << _name << std::endl;
    std::cout << "HitPoints   : " << _hitPoints << std::endl;
    std::cout << "EnergyPoints: " << _energyPoints << std::endl;
    std::cout << "AttackDamage: " << _attackDamage << std::endl;
    std::cout << "----------------------------" << std::endl;
}

// ======================= [ public ] setter / getter ======================= //

// ---------------------------------- setter -------------------------------- //

void        ClapTrap::setName(const std::string &name)
{
    _name = name;
}

// ---------------------------------- setter -------------------------------- //

std::string ClapTrap::getName()
{
    return _name;
}

int         ClapTrap::getHitPoints()
{
    return _hitPoints;
}

int         ClapTrap::getEnergyPoints()
{
    return _energyPoints;
}

int         ClapTrap::getAttackDamage()
{
    return _attackDamage;
}

bool        ClapTrap::getCanAction()
{
    return _canAction;
}
