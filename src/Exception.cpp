/*
** EPITECH PROJECT, 2020
** exception
** File description:
** cpp
*/

#include "../include/Exception.hpp"

Exception::Exception(std::string const &message, std::string const &component)
{
    this->_component = component;
    this->_message = message;
}

Exception::~Exception()
{
}

const std::string &Exception::getComponent() const
{
    return this->_component;
}

const char *Exception::what() const noexcept
{
    return(this->_message.data());
}
