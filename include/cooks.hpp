/*
** EPITECH PROJECT, 2020
** cooks
** File description:
** cooks
*/

#ifndef _COOKS_HPP_
#define _COOKS_HPP

#include <iostream>
#include "ingredients.hpp"
#include <sstream>
#include <unistd.h>

class cooks
{
private:
    std::string _order;
    int _multiplier;
    std::string _pizza;
    std::string _name;
    std::string _type;
    int _size;
    struct ingredients &_ingredients;
public:
    cooks(int cookTime, std::string _order, struct ingredients &_ingredients, std::string name, std::string type);
    ~cooks();
    void do_run();
    void pizza();
    void margarita();
    void regina();
    void americana();
    void fantasia();
};

#endif
