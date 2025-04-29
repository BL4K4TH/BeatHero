#ifndef DETECCAO_HPP
#define DETECCAO_HPP

#include <opencv2/opencv.hpp>
#include <vector>

class cDetector {
    private:
        int hmin = 0;  int hmax = 10;
        int smin = 30; int smax = 150;
        int vmin = 60; int vmax = 255;
    public:
        cv::Mat tratarFrame(cv::Mat f) {
            //váriaveis temporárias do método
            cv::Mat fHsv, fRange, fErode, fDilate;
            std::vector<std::vector<cv::Point>> contornos;

            //tratamento da imagem para detectar a  pele
            cv::cvtColor(f, fHsv, cv::COLOR_BGR2HSV);
            cv::Scalar lower(0, 30, 60), upper(10, 150, 255);
            cv::inRange(fHsv, lower, upper, fRange);
            cv::erode(fRange, fErode, cv::Mat(), cv::Point(-1,-1), 2);
            cv::dilate(fErode, fDilate, cv::Mat(), cv::Point(-1,-1), 2);

            //retorna a imagem tratada
            return fDilate;
        }
        
        std::vector<std::vector<cv::Point>> acharContornos (cv::Mat f) {
            //váriavel temporárias da função
            std::vector<std::vector<cv::Point>> contornos;

            //função para achar os contornos do frame
            cv::findContours(f, contornos, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

            //retorna os contornos
            return contornos;
        }
};

#endif