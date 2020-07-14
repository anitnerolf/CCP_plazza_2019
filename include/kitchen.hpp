/*
** EPITECH PROJECT, 2020
** kitchen
** File description:
** kitchen
*/

#ifndef _KITCHEN_HPP_
#define _KITCHEN_HPP_

#include <iostream>
#include <vector>
#include "cooks.hpp"
#include <thread>
#include "ingredients.hpp"

class kitchen
{
private:
    int _multiplier;
    int _cookers;
    int _refresh;
    std::string _order;
    std::string _name;
    std::string _type;
    std::vector<cooks*> _nbcooks;
    int _pizzaNumber;
    int _on;
    struct ingredients _ingredients;
    std::vector<std::vector<std::string>> _doubleArray;
public:
    kitchen(int cooktime, int cookers, int ingredientTime, std::vector<std::vector<std::string>> doubleArray, std::string name, std::string type);
    ~kitchen();
    void run(std::string &pizza);
    void pizzaNumber();
    void addCookers(std::string name, std::string type);
    void cook();
    void initIngredients();
    void refreshIngredients();
};


#endif
