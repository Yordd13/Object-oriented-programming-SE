#include <iostream>
#include "MachineProcess.h"
#include "Constants.h"

using constants::DEFAULT_PID;
using constants::DEFAULT_MEMORY;

void MachineProcess::free()
{
    delete[] name;
    name = nullptr;
    pid = DEFAULT_PID;
    memory = DEFAULT_MEMORY;
}

void MachineProcess::copyFrom(const MachineProcess& other)
{
    pid = other.getPid();
    memory = other.getMemory();

    setName(other.name);
}

void MachineProcess::setPid(int pid)
{
    this->pid = (pid < 0) ? DEFAULT_PID : pid;
}

void MachineProcess::setName(const char* name)
{

    delete[] this->name;

    if (name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    else {
        this->name = nullptr;
    }
}

MachineProcess::MachineProcess(int pid, const char* name, int memory) : name(nullptr)
{
    setPid(pid);
    setName(name);
    setMemory(memory);

    countOfCurrProcesses++;
}

MachineProcess::MachineProcess(const MachineProcess& other) : name(nullptr)
{
    copyFrom(other);

    countOfCurrProcesses++;
}

MachineProcess& MachineProcess::operator=(const MachineProcess& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MachineProcess::~MachineProcess()
{
    free();
    countOfCurrProcesses--;
}

const char* MachineProcess::getName() const
{
    return name;
}

int MachineProcess::getMemory() const
{
    return memory;
}

int MachineProcess::getPid() const
{
    return pid;
}

void MachineProcess::setMemory(int memory)
{
    this->memory = (memory < 0) ? DEFAULT_MEMORY : memory;
}

void MachineProcess::print() const
{
    std::cout << "Pid: " << pid << 
                " Name: " << name << 
                " Memory: " << memory << std::endl;
}

int MachineProcess::getProcessesCount()
{
    return countOfCurrProcesses;
}

bool MachineProcess::hasMoreMemoryThan(const MachineProcess& other) const
{
    return memory > other.getMemory();
}

int MachineProcess::countOfCurrProcesses = 0;