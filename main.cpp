#include "opencv2/opencv.hpp"

using namespace cv;

/* Keep the webcam from locking up when you interrupt a frame capture */
volatile int quit_signal=0;
#ifdef __unix__
#include <signal.h>
extern "C" void quit_signal_handler(int signum) {
    if (quit_signal!=0) exit(0); // just exit already
    quit_signal=1;
    printf("Will quit at next camera frame (repeat to kill now)\n");
}
#endif

int main(int, char**)
{

#ifdef __unix__
    signal(SIGINT,quit_signal_handler); // listen for ctrl-C
#endif

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
        if(quit_signal) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
