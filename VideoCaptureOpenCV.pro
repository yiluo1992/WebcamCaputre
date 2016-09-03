TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


INCLUDEPATH += /usr/local/include

LIBS += /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_cudev.so /usr/local/lib/libopencv_cudaarithm.so
LIBS += /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgcodecs.so
LIBS += /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_calib3d.so
