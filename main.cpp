#include <opencv2/opencv.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "detection.hpp"

using namespace cv;
using namespace std;

int main() {
    Mat frame;
    cDetector detector;

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Erro ao abrir a câmera.\n";
        return 0;
    }

    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);

    Mix_Music* musica = Mix_LoadMUS("musica_1.mp3");
    Mix_PlayMusic(musica, -1);

    while(cap.read(frame)) {
        flip(frame, frame, 1);

        detector.setFrame(frame);
        detector.tratarFrame();

        imshow("BeatHero", detector.getFrame());
        if(waitKey(1) == 27) {
            break;
        }
    }

    Mix_FreeMusic(musica);
    Mix_CloseAudio();
    Mix_Quit();
    
    return 1;
}