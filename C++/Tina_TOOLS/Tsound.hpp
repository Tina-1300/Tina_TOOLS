#ifndef Tsound_
#define Tsound_

#include <iostream>
#include <windows.h>

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Lier la bibliothèque winmm.lib

#define ErrorPlayingAudioFile 34 // retourn 34 si on arrive pas a lir le song 

class Tsound{
public:

    static int Tsound_Play_Back_infinit(const std::string& MusicNameWAV){
        const char* filePath = MusicNameWAV.c_str(); //musique en .wav
        if (!PlaySoundA(filePath, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)){
            std::cerr << "error l'ors de la lecture de l'audio" << std::endl;
            return ErrorPlayingAudioFile;
        }

        while (true){
           // Sleep(1000); 
        }
        PlaySoundA(NULL, NULL, 0);
    }

};

#endif
/*
compilation : 
g++ -o test.exe test.cpp -lwinmm
*/