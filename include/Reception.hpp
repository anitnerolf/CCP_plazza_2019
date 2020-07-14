/*
** EPITECH PROJECT, 2020
** reception
** File description:
** reception
*/

#ifndef _RECEPTION_HPP_
#define _RECEPTION_HPP_

#include <iostream>
#include <vector>
#include <map>
#include "kitchen.hpp"
#include "Pizza.hpp"
#include "ipc.hpp"

class Reception
{
private:
    int _multiplier;
    int _cookers;
    int _refresh;
    std::string _order;
    std::vector<kitchen> _kitchens;
public:
    Reception(char **av);
    ~Reception();
    void run();
    bool checkOrders();
    void processOrders(IPC ipc);
    void keepRecord();
    void pizza_size();
    void pizza_name();
    std::pair<int, int> CommandPair;
    void	create_child_process(IPC ipc);
    void	change_ipc(IPC ipc);
    std::pair<std::string, std::string> deliveryName;
    std::vector<std::string> array;
    void	saveTypeAndSize(auto k);
    void	set_ipc(IPC ipc);
    std::vector<std::vector<std::string>> doubleArray;
    std::vector<std::string> get_space_array(std::string str);
    std::vector<std::string> getSemiColonArray(std::string str);
    std::vector<std::vector<std::string>> get_array(std::vector<std::string> str);
    std::map<const char *, PizzaSize> sizeOfPizza= {
        {"S", S},
        {"M", M},
        {"L", L},
        {"XL", XL},
        {"XXL", XXL}
    };
    std::map<const char *, PizzaType> typeOfPizza = {
        {"Regina", Regina},
        {"Margarita", Margarita},
        {"Americana", Americana},
        {"Fantasia", Fantasia}
    };
};


#endif
