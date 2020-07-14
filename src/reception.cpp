/*
** EPITECH PROJECT, 2020
** reception
** File description:
** sources
*/

#include "../include/Reception.hpp"
#include "../include/parsing.hpp"
#include "../include/ipc.hpp"
#include "../include/Pizza.hpp"
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <sys/mman.h>

Reception::Reception(char **av)
{
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0 || atoi(av[3]) <= 0)
        exit(EXIT_FAILURE);
    _multiplier = atoi(av[1]);
    _cookers = atoi(av[2]);
    _refresh = atoi(av[3]);
}

Reception::~Reception()
{
}

bool Reception::checkOrders()
{
    // ARGUMENT PARSING, CHECKING PICA, MASS, AND NUMBER
    Parsing parsOrder(_order);

    if (parsOrder.pars() != 84)
        return true;
    std::cout << "Wrong syntax, the order will not be considered" << std::endl;
    return false;
}

std::vector<std::string> Reception::get_space_array(std::string str)
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

std::vector<std::vector<std::string>>   Reception::get_array(std::vector<std::string> str)
{
    std::vector<std::vector<std::string>> array;
    for (auto &command : str) {
        std::vector<std::string> array_word = get_space_array(command);
        array.push_back(array_word);
    }
    return (array);
}

std::vector<std::string> Reception::getSemiColonArray(std::string str)
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

void	Reception::saveTypeAndSize(auto k)
{
    this->deliveryName.first = k[0].c_str();
    this->deliveryName.second = k[1].c_str();
    int size = this->sizeOfPizza.find(k[0].c_str())->second;
    int type = this->typeOfPizza.find(k[1].c_str())->second;
    this->CommandPair.first = type;
    this->CommandPair.second = size;
}

void	Reception::change_ipc(IPC ipc)
{
    ipc.saveMemory[0] = this->CommandPair.first;
    ipc.saveMemory[1] = this->CommandPair.second;
}

void	Reception::create_child_process(IPC ipc)
{
    pid_t pid = 0;

    pid = fork();
    if (pid == 0) {
        kitchen k(_multiplier, _cookers, _refresh, doubleArray, this->deliveryName.first, this->deliveryName.second);
        _kitchens.push_back(k);
//        std::cout<< _kitchens.size() << " kitchens are open\n";
        k.run(this->deliveryName.first);
//        delete(k);
        //keep a record for evry orders
//        keepRecord();
        exit(0);
    }
}

void	Reception::set_ipc(IPC ipc)
{
    int numberOfPizza = 0;
    int i = 0;

    for (auto k : this->doubleArray) {
      numberOfPizza = k[2][1] - 48;
      i = 0;
      while (i < numberOfPizza) {
            this->saveTypeAndSize(k);
            this->change_ipc(ipc);
            this->create_child_process(ipc);
            i++;
        }
    }
}

void Reception::processOrders(IPC ipc)
{
    if (_order.compare("status") == 0) {
        std::cout<< _kitchens.size() << " kitchens are open\n";
        return;
    } if (_order.compare("exit") == 0)
          exit (0);
    else {
        std::cout << "Your order is being processed..." << std::endl;
        this->array = getSemiColonArray(_order);
        this->doubleArray = this->get_array(this->array);
        this->set_ipc(ipc);
    }
    // Check if you have kitchen open

    // if not open a kitchen

}

void Reception::keepRecord()
{
    std::fstream file;
    time_t now = time(0);

    tm *ltm = localtime(&now);
    file.open("records.txt", std::fstream::app);
    file << (ltm->tm_mday) << "/" << (ltm->tm_mon) + 1 << "/" << (ltm->tm_year) + 1900;
    file << " - " << (ltm->tm_hour) << ":" << (ltm->tm_min) << ":" << (ltm->tm_sec);
    file << "  " << _order << std::endl;
    file.close();
}

void Reception::run()
{
    IPC ipc;

    ipc.shared_memory();
    while (std::getline(std::cin, _order))
    {
        if (checkOrders()) {
            processOrders(ipc);
        }
    }
    if (munmap(ipc.memory, 2048) == -1) {
        perror("munmap");
    }
    if (shm_unlink("/shm") == -1) {
        perror("unlink");
    }
}
