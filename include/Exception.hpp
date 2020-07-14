/*
** EPITECH PROJECT, 2020
** exception
** File description:
** plazza
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>

class Exception : public std::exception
{
public:
    Exception(std::string const &message, std::string const &component = "Unknown");
    virtual ~Exception();
    const std::string &getComponent()const;
    const char *what() const noexcept;
protected:
    std::string _message;
    std::string _component;
};

#endif /* EXCEPTION_HPP_ */
