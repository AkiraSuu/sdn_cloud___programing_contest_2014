/* 
 * artkglut_marker.hpp
 */

#ifndef __ARTKGLUT_MARKER_HPP__
#define __ARTKGLUT_MARKER_HPP__

#include <GL/glut.h>
#include <string>
using namespace std;

class ARTKGLUT_Marker
{
public:
	ARTKGLUT_Marker(string path, double width);
	virtual ~ARTKGLUT_Marker();
	virtual int draw() = 0;
	virtual int process(bool b) = 0;
	
	int get_id();
	void set_id(int id);
	bool get_detected();
	void set_detected(bool b);
	string get_path();
	double get_width();
	double _trans[3][4];
	double _center[2] = {0.0, 0.0};
	
protected:
	int _id;
	string _path;
	double _width = 80;

	bool _detected = false;
};

#endif

