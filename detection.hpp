#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <opencv2/opencv.hpp>

using namespace cv;

class cDetector {
    private:
        Mat frame;
    public:
        void setFrame(Mat f){frame = f;}
        Mat getFrame(){return frame;}

        void tratarFrame() {
            cvtColor(frame, frame, COLOR_BGR2HSV);

            Scalar lower(0,30,60) , upper(20, 150, 255);

            inRange(frame, lower, upper, frame);

            erode(frame, frame, Mat(), Point(-1,-1), 2);
            dilate(frame, frame, Mat(), Point(-1,-1), 2);
        }
};

#endif