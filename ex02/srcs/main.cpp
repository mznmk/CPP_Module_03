/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/20 12:22:48 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"
#include "../incs/FragTrap.hpp"
#include <stdlib.h>

# define ESC_RESET      "\033[0m"
# define CLR_CYAN       "\033[38;5;06m"
# define CLR_PINK       "\033[38;5;213m"

// -------------------------------------------------------------------------- //

/*!
** @brief   print usage
*/
void    printUsage()
{
    std::cout << "USAGE: ./trap Name1 Name2 Turn";
    std::cout << std::endl;
}

// -------------------------------------------------------------------------- //

void    attack(ClapTrap &from, ClapTrap &to)
{
    // "from" attack "to"
    from.attack(to.getName());
    // "to" take damege
    if (from.getCanAction())
        to.takeDamage(from.getAttackDamage());
}

void    repair(ClapTrap &clap)
{
    // "clap" repair damage
    clap.beRepaired(clap.getAttackDamage() * 4);
}

/*!
** @brief   execute player's action
*/
void    action(ClapTrap &from, ClapTrap &to, int turn, std::string color)
{
    std::cout << color;

    // print turn status
    std::cout << "[ turn " << turn << ": " << from.getName() << " ]" << std::endl;

    // execute random action
    int act = rand() % 5;
    if (0 <= act && act <= 0)
        repair(from);
    else
        attack(from, to);

    std::cout << ESC_RESET;
}

// -------------------------------------------------------------------------- //

/*!
** @brief   class ClapTrap test
** @param   argc    argument count
** @param   aragv   argument value
** @return  status
*/
int     main(int argc, char **argv)
{
    // check arguments
    if (argc != 4) {
        printUsage();
        return 1;
    }

    // create claptrap
    ScavTrap    *a = new ScavTrap(argv[1]);
    FragTrap    *b = new FragTrap(argv[2]);
    
    // print status
    a->printStatus();
    b->printStatus();

    // simulate
    int turn = atoi(argv[3]);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < turn; i++) {
        // player1's turn
        action(*a, *b, i+1, CLR_PINK);
        // player2's turn
        action(*b, *a, i+1, CLR_CYAN);

        // print status
        a->printStatus();
        b->printStatus();

        // both player1 and player2 have Hit Points ?
        if (a->getHitPoints() == 0 || b->getHitPoints() == 0)
            break;
    }

    // enter gate keeper mode
    a->guardGate();

    // high fives guy
    b->highFivesGuys();

    // delete claptrap
    delete a;
    delete b;

    // [ return ]
    return 0;
}
