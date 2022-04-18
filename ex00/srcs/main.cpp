/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:22:16 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/19 00:33:08 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"
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
    std::cout << "USAGE: ./trap Name1 AttackDamage1 Name2 AttackDamage2";
    std::cout << std::endl;
}

void    attack(ClapTrap &from, ClapTrap &to)
{
    if (from.getHitPoints() == 0)
        return;
    if (from.getEnergyPoints() == 0)
        return;
    // "from" attack "to"
    from.attack(to.getName());
    // "to" take damege
    to.takeDamage(from.getAttackDamage());
}

void    repair(ClapTrap &clap)
{
    // "clap" repair damage
    clap.beRepaired(clap.getAttackDamage());
}

void    action(ClapTrap &from, ClapTrap &to, std::string color)
{
    std::cout << color;
    std::cout << "[ turn: " << from.getName() << " ]" << std::endl;

    int act = rand() % 5;
    if (0 <= act && act <= 2)
        attack(from, to);
    else
        repair(from);

    std::cout << ESC_RESET;
}

int     main(int argc, char **argv)
{
    // check arguments
    if (argc != 5) {
        printUsage();
        return 1;
    }

    // create claptrap
    ClapTrap    a(argv[1]);
    ClapTrap    b;
    b.setName(argv[3]);

    // set attack damage
    a.setAttackDamage(atoi(argv[2]));
    b.setAttackDamage(atoi(argv[4]));
    
    // print status
    a.printStatus();
    b.printStatus();

    // simulate (5 turn)
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        // player1
        action(a, b, CLR_PINK);
        // player2
        action(b, a, CLR_CYAN);
        // player1 or player2 is dead ?
        if (a.getHitPoints() == 0 || b.getHitPoints() == 0)
            break;
    }

    // print status
    a.printStatus();
    b.printStatus();

    // [ return ]
    return 0;
}