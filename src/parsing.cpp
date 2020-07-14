/*
** EPITECH PROJECT, 2020
** parsin
** File description:
** parsing
*/

#include <vector>
#include <sstream>
#include <algorithm>
#include "../include/parsing.hpp"

Parsing::Parsing(std::string verb) : _verb(verb)
{
}

Parsing::~Parsing()
{
}

std::vector<std::string> Parsing::get_space_array(std::string str)
{
    std::vector<std::string> array_space;
    std::stringstream s_stream(str);
    while(s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ' ');
        array_space.push_back(substr);
    }
    return array_space;
}

std::vector<std::vector<std::string>>   Parsing::get_array(std::vector<std::string> str)
{
    std::vector<std::vector<std::string>> array;
    for (auto &command : str) {
        std::vector<std::string> array_word = get_space_array(command);
        array.push_back(array_word);
    }
    return (array);
}

std::vector<std::string> Parsing::getSemiColonArray(std::string str)
{
    std::vector<std::string> array;
    std::stringstream s_stream(str);
    while(s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ';');
        if (substr.at(0) == ' ')
            substr.erase(0, 1);
        array.push_back(substr);
    }
    return (array);
}

bool Parsing::pizzaName(std::string type)
{
    if (type.compare("regina") == 0)
        return true;
    if (type.compare("margarita") == 0)
        return true;
    if (type.compare("fantasia") == 0)
        return true;
    if (type.compare("americana") == 0)
        return true;
    return false;
}

bool Parsing::pizzaMass(std::string mass)
{
    if (mass.compare("S") == 0)
        return true;
    if (mass.compare("M") == 0)
        return true;
    if (mass.compare("L") == 0)
        return true;
    if (mass.compare("XL") == 0)
        return true;
    if (mass.compare("XXL") == 0)
        return true;
    return false;
}

bool Parsing::pizzaNumber(std::string number)
{
    if (number.at(0) == 'x' && (number.at(1) >= '1' && number.at(1) <= '9'))
        return true;
    return false;
}

int	Parsing::checkPizzaTypeSize(std::vector<std::string> SemiColonArray)
{
    int number_split = 3;

    for (auto &command : SemiColonArray) {
        std::vector<std::string> array_word = get_space_array(command);
        if (array_word.empty())
            return (84);
        if (array_word.size() % number_split != 0) {
            return (84);
        }
        array_word.at(0).erase(remove_if(array_word.at(0).begin(), array_word.at(0).end(), isspace), array_word.at(0).end());
        array_word.at(1).erase(remove_if(array_word.at(1).begin(), array_word.at(1).end(), isspace), array_word.at(1).end());
        array_word.at(2).erase(remove_if(array_word.at(2).begin(), array_word.at(2).end(), isspace), array_word.at(2).end());
        if (this->pizzaName(array_word.at(0)) == false) {
            std::cout << "wrong name" << std::endl;
            return (84);
        }
        if (this->pizzaMass(array_word.at(1)) == false) {
            std::cout << "wrong mass" << std::endl;
            return (84);
        }
        if (this->pizzaNumber(array_word.at(2)) == false) {
            std::cout << "wrong number" << std::endl;
            return (84);
        }
    }
    return (0);
}

std::vector<std::vector<std::string>> Parsing::getDoubleArray()
{
    return (this->get_array(this->array));
}

int Parsing::pars()
{
    if (_verb.compare("status") == 0)
        return (0);
    if (_verb.compare("exit") == 0)
        return (1);
    this->array = this->getSemiColonArray(_verb);
    if (this->checkPizzaTypeSize(this->array) != 84)
        return (2);
    return (84);
}
