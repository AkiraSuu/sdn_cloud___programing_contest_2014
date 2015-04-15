INC_DIR = ARToolKit/include
LIB_DIR = ARToolKit/lib

CXX = g++
CXXFLAG = --ansi -Wall -std=c++11

LDFLAG = -pthread -lgstreamer-0.10 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lxml2 -lglib-2.0 -L/usr/X11R6/lib -L/usr/local/lib -L$(LIB_DIR)
LIBS = -lARgsub_lite -lARvideo -lAR -lpthread -lglut -lGLU -lGL -lXi -lX11 -lm -pthread -lgstreamer-0.10 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lxml2 -lglib-2.0 `pkg-config --libs ftgl`
CFLAG = -O -pthread -I/usr/include/gstreamer-0.10 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/libxml2 -I/usr/X11R6/include -I$(INC_DIR) `pkg-config --cflags ftgl`


all: okinawa_demo

okinawa_demo: okinawa_demo.o artkglut_context.o artkglut_camera.o artkglut_marker.o marker_1.o vm.o marker_kvm.o port.o marker_controller.o marker_face.o
	$(CXX) -o okinawa_demo okinawa_demo.o artkglut_context.o artkglut_camera.o artkglut_marker.o marker_1.o vm.o marker_kvm.o port.o marker_controller.o marker_face.o $(LDFLAG) $(LIBS)

okinawa_demo.o: okinawa_demo.cpp artkglut_context.hpp artkglut_marker.hpp marker_1.hpp marker_kvm.hpp marker_controller.hpp marker_face.hpp
	$(CXX) -c okinawa_demo.cpp $(CXXFLAG) $(CFLAG)

artkglut_context.o: artkglut_context.cpp artkglut_context.hpp artkglut_camera.hpp artkglut_marker.hpp marker_face.hpp
	$(CXX) -c artkglut_context.cpp $(CXXFLAG) $(CFLAG)

artkglut_camera.o: artkglut_camera.cpp artkglut_camera.hpp
	$(CXX) -c artkglut_camera.cpp $(CXXFLAG) $(CFLAG)

artkglut_marker.o: artkglut_marker.cpp artkglut_marker.hpp
	$(CXX) -c artkglut_marker.cpp $(CXXFLAG) $(CFLAG)
	
marker_1.o: marker_1.cpp marker_1.hpp draw_utils.hpp vm.hpp port.hpp
	$(CXX) -c marker_1.cpp $(CXXFLAG) $(CFLAG)
	
vm.o: vm.cpp vm.hpp
	$(CXX) -c vm.cpp $(CXXFLAG) $(CFLAG)

marker_kvm.o: marker_kvm.cpp marker_kvm.hpp draw_utils.hpp vm.hpp
	$(CXX) -c marker_kvm.cpp $(CXXFLAG) $(CFLAG)

port.o: port.cpp port.hpp
	$(CXX) -c port.cpp $(CXXFLAG) $(CFLAG)

marker_controller.o: marker_controller.cpp marker_controller.hpp draw_utils.hpp vm.hpp
	$(CXX) -c marker_controller.cpp $(CXXFLAG) $(CFLAG)

marker_face.o: marker_face.cpp marker_face.hpp
	$(CXX) -c marker_face.cpp $(CXXFLAG) $(CFLAG)

clean:
	rm -f *.o
	rm -f okinawa_demo

