/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:30:55 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 11:43:51 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

// ================================ library ================================= //

#include <iostream>
#include <string>
#include <ostream>

// ================================= class ================================== //

class ClapTrap
{
    protected:
        // [ variable ]
        std::string     _name;
        int             _hitPoints;
        int             _energyPoints;
        int             _attackDamage;
        bool            _canAction;

        // [ method ]
        void            _initParameter(const std::string name);
        void            _copyParameter(const ClapTrap &clap);
        bool            _setPrintNoLife();
        bool            _setPrintNoEnergy();

    public:
        // [ constructor / destructor ]
        ClapTrap();
        ClapTrap(const std::string name);
        ClapTrap(const ClapTrap &clap);
        virtual ~ClapTrap();

        // [ operator ]
        ClapTrap        &operator=(const ClapTrap &clap);

        // [ method ]
        virtual void    attack(const std::string &target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        void            printStatus();

        // [ setter / getter ]
        void            setName(const std::string &name);
        std::string     getName();
        int             getHitPoints();
        int             getEnergyPoints();
        int             getAttackDamage();
        bool            getCanAction();
};

#endif
