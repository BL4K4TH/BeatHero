#include <opencv2/opencv.hpp>
#include "interface.hpp"
#include "deteccao.hpp"

int main() {
    cv::VideoCapture camera(0);
    cv::Mat frame;
    cDetector detector;

    cBotao start(cv::Rect(6, 6, 503, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao continuar(cv::Rect(6, 6, 503, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao configurar(cv::Rect(509, 6, 503, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao sair(cv::Rect(918, 500, 100, 100), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));

    cBotao fase1(cv::Rect(6, 6, 333, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao fase2(cv::Rect(345, 6, 333, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao fase3(cv::Rect(684, 6, 334, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));

    cBotao hmin(cv::Rect(6, 6, 333, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao hmax(cv::Rect(176, 6, 333, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao smin(cv::Rect(346, 6, 334, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao smax(cv::Rect(516, 6, 333, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao vmin(cv::Rect(686, 6, 333, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    cBotao vmax(cv::Rect(855, 6, 334, 127), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));

    cBotao pause(cv::Rect(918, 662, 100, 100), cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));

    while(true) {
        camera >> frame;

        cv::flip(frame, frame, 1);
        cv::resize(frame, frame, cv::Size(1024, 768));

        start.plotarBotao(frame, detector);
        configurar.plotarBotao(frame, detector);
        sair.plotarBotao(frame, detector);

        cv::imshow("BeatHero", frame);

        if(start.getEstado()) {
            while(true) {
                camera >> frame;

                cv::flip(frame, frame, 1);
                cv::resize(frame, frame, cv::Size(1024, 768));

                fase1.plotarBotao(frame, detector);
                fase2.plotarBotao(frame, detector);
                fase3.plotarBotao(frame, detector);
                sair.plotarBotao(frame, detector);

                sair.plotarBotao(frame, detector);

                cv::imshow("BeatHero", frame);

                if(sair.getEstado() || cv::waitKey(1) == 27) {
                    break;
                }
            }
        } else if(configurar.getEstado()) {
            while(true) {
                camera >> frame;

                cv::flip(frame, frame, 1);
                cv::resize(frame, frame, cv::Size(1024, 768));

                hmin.plotarBotao(frame, detector);
                hmax.plotarBotao(frame, detector);
                smin.plotarBotao(frame, detector);
                smax.plotarBotao(frame, detector);
                vmin.plotarBotao(frame, detector);
                vmax.plotarBotao(frame, detector);

                sair.plotarBotao(frame, detector);

                cv::imshow("BeatHero", detector.tratarFrame(frame));

                if(sair.getEstado() || cv::waitKey(1) == 27) {
                    break;
                }
            }
        } else if(sair.getEstado() || cv::waitKey(1) == 27) {
            break;
        }
    }
}