/* 
 * artkglut_marker.cpp
 */

#include <string>
using namespace std;

#include "artkglut_marker.hpp"

ARTKGLUT_Marker::ARTKGLUT_Marker(string path, double width)
{
	_path = path;
	_width = width;
}

ARTKGLUT_Marker::~ARTKGLUT_Marker()
{

}

bool
ARTKGLUT_Marker::get_detected()
{
	return _detected;
}
	
int
ARTKGLUT_Marker::get_id()
{
	return _id;
}

void
ARTKGLUT_Marker::set_id(int id)
{
	_id = id;
}
	
string
ARTKGLUT_Marker::get_path()
{
	return _path;
}
	
double
ARTKGLUT_Marker::get_width()
{
	return _width;
}
	
void
ARTKGLUT_Marker::set_detected(bool b)
{
	_detected = b;
}

