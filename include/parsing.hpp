/*
** EPITECH PROJECT, 2020
** parsing
** File description:
** parsing
*/

#ifndef _PARSING_HPP_
#define _PARSING_HPP_

#include <iostream>

class Parsing
{
private:
    std::string _verb;
    bool pizzaName(std::string name);
    bool pizzaMass(std::string mass);
    bool pizzaNumber(std::string name);
public:
    Parsing(std::string verb);
    ~Parsing();
    int pars();
    std::vector<std::vector<std::string>> getDoubleArray();
    int checkPizzaTypeSize(std::vector<std::string> SemiColonArray);
    std::vector<std::string> array;
    std::vector<std::vector<std::string>> doubleArray;
    std::vector<std::string> get_space_array(std::string str);
    std::vector<std::string> getSemiColonArray(std::string str);
    std::vector<std::vector<std::string>> get_array(std::vector<std::string> str);
};



#endif
