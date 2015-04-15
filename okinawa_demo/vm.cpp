/* 
 * vm.cpp
 */

#include <string>
using namespace std;

#include "vm.hpp"

VM::VM(string name, double cpu, double mem)
{
	_name = name;
	_cpu = cpu;
	_mem = mem;
}

VM::~VM()
{
}

string
VM::get_name()
{
	return _name;
}

double
VM::get_cpu_usage()
{
	return _cpu;
}

double
VM::get_mem_usage()
{
	return _mem;
}

