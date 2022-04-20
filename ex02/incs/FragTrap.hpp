/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 06:41:56 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 10:25:50 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

// ================================ library ================================= //

# include "ClapTrap.hpp"

// ================================= class ================================== //

class FragTrap : public ClapTrap
{
    private:
        // [ method ]
        void        _initParameter(const std::string name);
        void        _copyParameter(const FragTrap &scav);

    public:
        // [ constructor / destructor ]
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap &frag);
        ~FragTrap();

        // [ operator ]
        FragTrap    &operator=(const FragTrap &frag);

        // [ method ]
        void        highFivesGuys(void);
};

#endif
