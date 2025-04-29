Comando para compilar no terminal do Ubuntu:
g++ main.cpp -o BeatHero $(pkg-config --cflags --libs opencv4 sdl2 SDL2_mixer)