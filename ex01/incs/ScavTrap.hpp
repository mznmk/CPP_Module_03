/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:41:56 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 11:15:31 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

// ================================ library ================================= //

# include "ClapTrap.hpp"

// ================================= class ================================== //

class ScavTrap : public ClapTrap
{
    private:
        // [ method ]
        void        _initParameter(const std::string name);
        void        _copyParameter(const ScavTrap &scav);
        bool        _setPrintNoLife();
        bool        _setPrintNoEnergy();

    public:
        // [ constructor / destructor ]
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap &scav);
        ~ScavTrap();

        // [ operator ]
        ScavTrap    &operator=(const ScavTrap &scav);

        // [ method ]
        void        attack(const std::string &target);
        void        guardGate();
};

#endif
