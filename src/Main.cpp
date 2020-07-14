/*
** EPITECH PROJECT, 2020
** main
** File description:
** plazza
*/

#include <iostream>
#include "../include/Exception.hpp"
#include "../include/Reception.hpp"

void	start_cmd(char **av)
{
    Reception plazza(av);
    
    plazza.run();
}

int     check_if_number(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 57 || str[i] < 48)
            return 84;
        i++;
    }
    return 0;
}

int	main(int ac, char **av)
{
    try {
        if (ac != 4) {
            throw(Exception("Wrong argument number!", "Argument"));
        } else {
            if (check_if_number(av[1]) == 84 || check_if_number(av[2]) == 84 || check_if_number(av[3]) == 84) {
                throw(Exception("Arguments must be numbers and positive!", "Argument"));
            } else {
                start_cmd(av);
            }
        }
    } catch(Exception &e) {
        std::cout << e.what() << std::endl;
        return (84);
    }
    return (0);
}
