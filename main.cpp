#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat frame;
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "Erro ao abrir a câmera.\n";
        return 0;
    }

    while(cap.read(frame)) {
        imshow("Camera", frame);
        if(waitKey(1) == 27) {
            break;
        }
    }
    
    return 1;
}