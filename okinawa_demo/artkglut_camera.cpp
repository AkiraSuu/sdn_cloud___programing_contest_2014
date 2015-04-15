/* 
 * artkglut_camera.cpp
 */

#include <stdexcept>
#include <memory>
#include <iostream>
using namespace std;

#include <AR/ar.h>
#include <AR/video.h>

#include "artkglut_camera.hpp"

ARTKGLUT_Camera::ARTKGLUT_Camera()
{
	if (arVideoOpen((char *)ARTKGLUT_VIDEO_CONF) < 0) {
		throw runtime_error("arVideoOpen");
	}
}

ARTKGLUT_Camera::~ARTKGLUT_Camera()
{
	arVideoCapStop();
	arVideoClose();
}

int
ARTKGLUT_Camera::setup(ARParam *c_param)
{
	ARParam wparam;
	int x, y;
	
	if (arVideoInqSize(&x, &y) < 0) {
		cerr << "Failed to get camera image size." << endl;
		return -1;
	}
	cout << "Camera image size: " << x << "x" << y << "." << endl;
	
	if (arParamLoad(ARTKGLUT_CAMERA_PARAM, 1, &wparam) < 0) {
		cerr << "Failed to load camera parameter file: " << ARTKGLUT_CAMERA_PARAM << endl;
		return -1;
	}
	
	arParamChangeSize(&wparam, x, y, c_param);
	cout << "Camera parameters:" << endl;
	
	arParamDisp(c_param);
	arInitCparam(c_param);
	return 0;
}

int
ARTKGLUT_Camera::capture_start()
{
	if (arVideoCapStart() != 0) {
		cerr << "Failed to begin camera data capture." << endl;
		return -1;
	}
	return 0;
}

int
ARTKGLUT_Camera::capture_stop()
{
	arVideoCapStop();
	return 0;
}

