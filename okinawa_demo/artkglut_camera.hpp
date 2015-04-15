/* 
 * artkglut_camera.hpp
 */

#ifndef __ARTKGLUT_CAMERA_HPP__
#define __ARTKGLUT_CAMERA_HPP__

#include <AR/ar.h>

#define ARTKGLUT_VIDEO_CONF		"v4l2src device=/dev/video0 use-fixed-fps=false ! ffmpegcolorspace ! capsfilter caps=video/x-raw-rgb,width=640,height=480 ! identity name=artoolkit ! fakesink"
#define ARTKGLUT_CAMERA_PARAM	"data/camera_para.dat"

class ARTKGLUT_Camera
{
public:
	ARTKGLUT_Camera();
	~ARTKGLUT_Camera();
	
	int setup(ARParam *cparam);
	int capture_start();
	int capture_stop();
};

#endif

