/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:41:56 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/19 12:18:29 by mmizuno          ###   ########.fr       */
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
        void        initParameter(const std::string name);

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
