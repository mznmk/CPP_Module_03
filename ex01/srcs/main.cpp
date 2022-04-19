/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/19 16:53:57 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"
#include <stdlib.h>

# define ESC_RESET      "\033[0m"
# define FNT_BOLD       "\033[1m"
# define FNT_FINE       "\033[2m"
# define FNT_ITALIC     "\033[3m"
# define FNT_ULINE      "\033[4m"
# define CLR_BLACK      "\033[38;5;00m"
# define CLR_RED        "\033[38;5;01m"
# define CLR_GREEN      "\033[38;5;02m"
# define CLR_YELLOW     "\033[38;5;03m"
# define CLR_BLUE       "\033[38;5;04m"
# define CLR_MAGENTA    "\033[38;5;05m"
# define CLR_CYAN       "\033[38;5;06m"
# define CLR_WHITE      "\033[38;5;07m"
# define CLR_PINK       "\033[38;5;213m"

void    printUsage()
{
    std::cout << "USAGE: ./trap Name1 Name2 Turn";
    std::cout << std::endl;
}

void    attack(ScavTrap &from, ScavTrap &to)
{
    // "from" attack "to"
    from.attack(to.getName());
    // "to" take damege
    if (from.getCanAction())
        to.takeDamage(from.getAttackDamage());
}

void    repair(ScavTrap &clap)
{
    // "clap" repair damage
    clap.beRepaired(clap.getAttackDamage() * 3);
}

void    action(ScavTrap &from, ScavTrap &to, std::string color)
{
    std::cout << color;
    std::cout << "[ turn: " << from.getName() << " ]" << std::endl;

    int act = rand() % 5;
    if (0 <= act && act <= 0)
        repair(from);
    else
        attack(from, to);

    std::cout << ESC_RESET;
}

int     main(int argc, char **argv)
{
    // check arguments
    if (argc != 4) {
        printUsage();
        return 1;
    }

    // create claptrap
    ScavTrap    a(argv[1]);
    ScavTrap    b;
    b.setName(argv[2]);
    
    // print status
    a.printStatus();
    b.printStatus();

    // simulate (5 turn)
    int turn = atoi(argv[3]);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < turn; i++) {
        // player1
        action(a, b, CLR_PINK);
        // player2
        action(b, a, CLR_CYAN);

        // print status
        a.printStatus();
        b.printStatus();

        // player1 or player2 is dead ?
        if (a.getHitPoints() == 0 || b.getHitPoints() == 0)
            break;
    }

    // enter gate keeper mode
    a.guardGate();
    b.guardGate();

    // [ return ]
    return 0;
}