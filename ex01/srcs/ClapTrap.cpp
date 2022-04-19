/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:33:53 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/19 12:32:38 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

// =========================== [ private ] method =========================== //

void        ClapTrap::initParameter(const std::string name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    _canAction = true;
}

// ================== [ public ] constructor / destructor =================== //

// -------------------------- default contsructor --------------------------- //

ClapTrap::ClapTrap()
{
    std::cout << "[ClapTrap] Default constructor called" << std::endl;
    initParameter("");
}

// ------------------------- conberting contsructor ------------------------- //

ClapTrap::ClapTrap(const std::string name): _name(name)
{
    std::cout << "[ClapTrap] Conberting constructor called" << std::endl;
    initParameter(name);
}

// ---------------------------- copy contsructor ---------------------------- //

ClapTrap::ClapTrap(const ClapTrap &clap)
{
    std::cout << "[ClapTrap] Copy constructor called" << std::endl;
    _name = clap._name;
    _hitPoints = clap._hitPoints;
    _energyPoints = clap._energyPoints;
    _attackDamage = clap._attackDamage;
    _canAction = clap._canAction;
}

// ------------------------------- destructor ------------------------------- //

ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] Destructor called" << std::endl;
}

// ========================== [ public ] operator =========================== //

// ------------------------ copy assignment operator ------------------------ //

ClapTrap    &ClapTrap::operator=(const ClapTrap &clap)
{
    std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;
    if (this != &clap) {
        _name = clap._name;
        _hitPoints = clap._hitPoints;
        _energyPoints = clap._energyPoints;
        _attackDamage = clap._attackDamage;
        _canAction = clap._canAction;
    }
    return *this;
}

// =========================== [ public ] method ============================ //

void        ClapTrap::attack(const std::string &target)
{
    // already dead ?
    if (_hitPoints == 0) {
        std::cout << "ClapTrap <" << _name << "> is already dead ...";
        std::cout << std::endl;
        _canAction = false;
         return;
    }
    // have energy point ?
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> has no energy points ...";
        std::cout << std::endl;
        _canAction = false;
        return;
    }
    // attack
    _energyPoints -= 1;
    std::cout << "ClapTrap <" << _name << "> ";
    std::cout << "attacks <" << target << ">, ";
    std::cout << "causing <" << _attackDamage << "> points of damage!";
    std::cout << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount)
{
    // already dead ?
    if (_hitPoints == 0) {
        std::cout << "ClapTrap <" << _name << "> is already dead ...";
        std::cout << std::endl;
        return;
    }
    // take damage
    _hitPoints -= amount;
    std::cout << "ClapTrap <" << _name << "> ";
    std::cout << "take <" << amount << "> points of damage!";
    std::cout << std::endl;
    // dead now
    if (_hitPoints <= 0) {
        _hitPoints = 0;
        std::cout << "ClapTrap <" << _name << "> died ...";
        std::cout << std::endl;
    }
}

void        ClapTrap::beRepaired(unsigned int amount)
{
    // already dead ?
    if (_hitPoints == 0) {
        std::cout << "ClapTrap <" << _name << "> is already dead ...";
        std::cout << std::endl;
        _canAction = false;
        return;
    }
    // have energy point ?
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> has no energy points ...";
        std::cout << std::endl;
        _canAction = false;
        return;
    }
    // be repaired
    _energyPoints -= 1;
    _hitPoints += amount;
    std::cout << "ClapTrap <" << _name << "> ";
    std::cout << "is repaired <" << amount << "> Hit Points !";
    std::cout << std::endl;
}

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

void        ClapTrap::setName(const std::string &name)
{
    _name = name;
}

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
