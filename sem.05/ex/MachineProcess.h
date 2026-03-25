#pragma once
#pragma warning(disable : 4996)

class MachineProcess
{
private:

	int pid;
	char* name;
	int memory;

	static int countOfCurrProcesses;

	void free();
	void copyFrom(const MachineProcess& other);
	void setPid(int pid);
	void setName(const char* name);

public:
	
	MachineProcess(int pid, const char* name, int memory);
	MachineProcess(const MachineProcess& other);
	MachineProcess& operator=(const MachineProcess& other);
	~MachineProcess();

	const char* getName() const;
	int getMemory() const;
	int getPid() const;

	void setMemory(int memory);
	void print() const;
	static int getProcessesCount();
	bool hasMoreMemoryThan(const MachineProcess& other) const;
};