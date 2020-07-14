/*
** EPITECH PROJECT, 2020
** ipc
** File description:
** ipc
*/

#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include "../include/ipc.hpp"
#include "../include/Exception.hpp"

IPC::IPC()
{
}

IPC::~IPC()
{
}

void	IPC::shared_memory()
{
    try {
        size_t size = sizeof(pthread_mutex_t);
        if ((pthread_mutexattr_init(&this->mutex_attributes)) != 0)
            throw(Exception("Pthread init error!", "Pthread"));
        if ((pthread_mutexattr_setpshared(&this->mutex_attributes, PTHREAD_PROCESS_SHARED)) != 0)
            throw(Exception("Pthread setpshared error!", "Pthread"));
        if ((this->open = shm_open("/shm", O_CREAT | O_RDWR, 0777)) == -1)
            throw(Exception("Failed opening shared memory object!", "shm_open"));
        if ((ftruncate(this->open, 2048*sizeof(int))) != 0)
            throw(Exception("Failed truncating file!", "ftruncated"));
        if ((this->memory = (char *)mmap(0, 2048*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, this->open, 0)) == (void *)-1)
            throw(Exception("mmap failed!", "mmap"));
        this->mutex = (pthread_mutex_t *)this->memory;
        if ((pthread_mutex_init(this->mutex, &this->mutex_attributes)) != 0)
            throw(Exception("Pthread mutex init error!", "Pthread"));
        this->saveMemory = (int *)(this->memory + size);
    } catch (Exception &e) {
        std::cout << e.what() << std::endl;
        exit(84);
    }
}
