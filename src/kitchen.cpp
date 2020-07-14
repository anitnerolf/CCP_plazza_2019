/*
** EPITECH PROJECT, 2020
** kitchen
** File description:
** kitchen
*/

#include "../include/kitchen.hpp"
//#include "../include/Cook.hpp"
//#include "../include/MakePizza.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <sstream>

kitchen::kitchen(int multiplier, int cookers, int refresh, std::vector<std::vector<std::string>> doubleArray, std::string name, std::string type)
    : _multiplier(multiplier), _cookers(cookers), _refresh(refresh), _doubleArray(doubleArray), _name(name), _type(type)
{
    _on = 1;
    addCookers(_name, _type);
    initIngredients();
}

kitchen::~kitchen()
{
}

void kitchen::pizzaNumber()
{
    int i;
    std::string nb;

    for (i = 0; _order[i] != 'x'; i++);
    i += 1;
    for (int j = i; _order[j] != '\0'; j++)
    {
        nb.push_back(_order[j]);
    }
    std::stringstream number(nb);
    number >> _pizzaNumber;
}


void kitchen::addCookers(std::string name, std::string type)
{
    for (int i = 0; i < _cookers; i++)
    {
        cooks *k = new cooks(_multiplier, _order, _ingredients, name, type);
        _nbcooks.push_back(k);
    }
}

void kitchen::initIngredients()
{
    for (int *ptr = &_ingredients.doe; ptr <= &_ingredients.chiefLove; ptr++)
    {
        *ptr = 5;
    }
}

void kitchen::refreshIngredients()
{
    for (int *ptr = &_ingredients.doe; ptr <= &_ingredients.chiefLove; ptr++)
    {
        *ptr += 1;
        if (*ptr > 5)
            *ptr = 5;
    }
    sleep(1);
    if (_on == 1)
        refreshIngredients();
}

void kitchen::run(std::string &pizza_name)
{
//
    //do cooking
    int i = 0;
    // cooks *k = new cooks(_multiplier, _order, _ingredients, _name, _type);
    // k->do_run();
    // _nbcooks[0]->do_run();
    while (i < _nbcooks.size()) {
        std::thread thr(&kitchen::refreshIngredients, this);
        _nbcooks[i]->do_run();
        sleep(5);
        _on = 0;
        thr.join();
        exit(EXIT_SUCCESS);
        i++;
    }
}
