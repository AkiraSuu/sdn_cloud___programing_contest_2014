/* 
 * vm.hpp
 */

#ifndef __VM_HPP__
#define __VM_HPP__

class VM
{
public:
	VM(string name, double cpu, double mem);
	~VM();
	string get_name();
	double get_cpu_usage();
	double get_mem_usage();
	
private:
	string _name;
	double _cpu;
	double _mem;
};

#endif

