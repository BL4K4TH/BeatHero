#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <opencv2/opencv.hpp>
#include "deteccao.hpp"

class cBotao {
    private:
        cv::Rect hitbox;
        cv::Scalar corOff;
        cv::Scalar corOn;
        bool estado;
    public:
        cBotao(cv::Rect h, cv::Scalar cf, cv::Scalar cn) {
            hitbox = h;
            corOff = cf;
            corOn = cn;
            estado = false;
        }

        bool getEstado() {
            return estado;
        }

        cv::Mat plotarBotao(cv::Mat f, cDetector d) {
            //váriaveis temporárias da função
            std::vector<std::vector<cv::Point>> contornos;
            cv::Scalar cor;

            //recebe os contornos do indíviduo atráves do cDetector
            contornos = d.acharContornos(d.tratarFrame(f));

            //lógica da colisão (modifica o estado do butão)
            estado = false;
            for (const auto& contorno : contornos) {
                cv::Rect bodybox = boundingRect(contorno);
                if ((hitbox & bodybox).area() > 0) {
                    estado = true;
                    break;
                }
            }

            //desenha o botão de acordo com seu estado (off/on)
            cor = estado ? corOn : corOff;
            rectangle(f, hitbox, cor, 3);
            return f;
        }
};

#endif