/* 
 * port.hpp
 */

#ifndef __PORT_HPP__
#define __PORT_HPP__

#include <string>
using namespace std;

class Port
{
public:
	Port(int id, string num);
	~Port();
	int _id;
	string _num;
};

#endif

