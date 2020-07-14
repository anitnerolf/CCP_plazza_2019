/*
** EPITECH PROJECT, 2020
** cooks
** File description:
** cooks
*/

#include "../include/cooks.hpp"

cooks::cooks(int multiplier, std::string order, struct ingredients &_ingredients, std::string name, std::string type) 
    : _multiplier(multiplier), _order(order), _ingredients(_ingredients), _name(name), _type(type)
{
}

cooks::~cooks()
{
}

void cooks::margarita()
{
    _ingredients.doe -= 1;
    _ingredients.tomato -= 1;
    _ingredients.gruyere -= 1;
    sleep(1*_multiplier);
    std::cout << _name << " is ready" << std::endl;
}

void cooks::regina()
{
    _ingredients.doe -= 1;
    _ingredients.tomato -= 1;
    _ingredients.gruyere -= 1;
    _ingredients.ham -= 1;
    _ingredients.mushrooms -= 1;
    sleep(2*_multiplier);
    std::cout << _name << " is ready" << std::endl;
}

void cooks::americana()
{
    _ingredients.doe -= 1;
    _ingredients.tomato -= 1;
    _ingredients.gruyere -= 1;
    _ingredients.steak -= 1;
    sleep(2*_multiplier);
    std::cout << _name << " is ready" << std::endl;
}

void cooks::fantasia()
{
    _ingredients.doe -= 1;
    _ingredients.tomato -= 1;
    _ingredients.eggplant -= 1;
    _ingredients.goatCheese -= 1;
    _ingredients.chiefLove -= 1;
    sleep(4*_multiplier);
    std::cout << _name << " is ready" << std::endl;
}

void cooks::do_run()
{
    if (_name.compare("margarita") == 0)
        margarita();
    if (_name.compare("regina") == 0)
        regina();
    if (_name.compare("americana") == 0)
        americana();
    if (_name.compare("fantasia") == 0)
        fantasia();
    exit(0);
}

void cooks::pizza()
{
    // int c;
    // std::string _sizeP;

    // for (int i = 0; _order[i] != ' '; i++) {
    //     _pizza.push_back(_order[i]);
    // }

    // for (c = 0; _order[c] != ' ' ; c++);
    // c += 1;
    // for (int i = c; _order[i] != ' ' ; i++) 
    // {
    //     _sizeP.push_back(_order[i]);
    // }
    
    // if (_sizeP.compare("M") == 0)
    //     _size = 2;
    // if (_sizeP.compare("S") == 0)
    //     _size = 1;
    //  if (_sizeP.compare("L") == 0)
    //     _size = 4;
    //  if (_sizeP.compare("XL") == 0)
    //     _size = 8;
    //  if (_sizeP.compare("XXL") == 0)
    //     _size = 16;
}

