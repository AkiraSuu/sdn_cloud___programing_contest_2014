/* 
 * okinawa_demo.hpp
 */

#ifndef __OKINAWA_DEMO_HPP__
#define __OKINAWA_DEMO_HPP__

#include <memory>
#include <string>
using namespace std;

#include "artkglut_context.hpp"

#define OKINAWA_DEMO_WIDTH		1280
#define OKINAWA_DEMO_HEIGHT		960

class Okinawa_Demo
{
public:
	Okinawa_Demo(int argc, char *argv[]);
	~Okinawa_Demo();
	int start();
	
	void idle() {
		_artkglut_context->idle();
	};
	void reshape(int x, int y) {
		_artkglut_context->reshape(x, y);
	};
	void display() {
		_artkglut_context->display();
	};
	void keyboard(unsigned char key, int x, int y) {
		_artkglut_context->keyboard(key, x, y);
	}

private:
	unique_ptr<ARTKGLUT_Context> _artkglut_context;
};

#endif

