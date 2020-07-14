/*
** EPITECH PROJECT, 2020
** ipc
** File description:
** hpp
*/

#ifndef IPC_HPP_
#define IPC_HPP_

class	IPC
{
public:
    IPC();
    ~IPC();
    void	shared_memory(void);
    bool	shared_mem;
    pthread_mutexattr_t mutex_attributes;
    pthread_mutex_t	*mutex;
    int open;
    char *memory;
    int	*saveMemory;
};

#endif /* IPC_HPP */
