#pragma once


#include <iostream>
#include <windows.h>

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Lier la bibliothèque winmm.lib

#define ErrorPlayingAudioFile 34 // retourn 34 si on arrive pas a lir le song


// Ajouter a la documentation 
//-------------------------------------------------
struct SOUND_SYSTEM_WINDOWS_PLAYSOUND {   
    int SND_ALIAS_SYSTEMASTERISK_ = 1;
    int SND_ALIAS_SYSTEMDEFAULT_ = 2;
    int SND_ALIAS_SYSTEMEXCLAMATION_ = 3;
    int SND_ALIAS_SYSTEMEXIT_ = 4;
    int SND_ALIAS_SYSTEMHAND_ = 5;
    int SND_ALIAS_SYSTEMQUESTION_ = 6;
    int SND_ALIAS_SYSTEMSTART_ = 7;
    int SND_ALIAS_SYSTEMWELCOME_ = 8;
};
// --------------------------------------------------


namespace Tina{


    class Tsound{
    public:

        static int Tsound_Play_Back_infinit(const std::string& MusicNameWAV){
            const char* filePath = MusicNameWAV.c_str(); //musique en .wav
            if (!PlaySoundA(filePath, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)){
                std::cerr << "error l'ors de la lecture de l'audio" << std::endl;
                return ErrorPlayingAudioFile;
            }

            while (true){
            }
            PlaySoundA(NULL, NULL, 0);
        }



        // a ajouter a la doc --------------------
        static bool Tsound_Play_Music(LPCTSTR MusicName_WAV){
            if(PlaySound(MusicName_WAV, NULL, SND_FILENAME)){
                return true;
            }else{
                return false;
            }
        }

        static int Tsound_Play_Song_System(const SOUND_SYSTEM_WINDOWS_PLAYSOUND& sound){
            if(sound.SND_ALIAS_SYSTEMASTERISK_ == 1){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMASTERISK, NULL, SND_ALIAS_ID);
            }else if (sound.SND_ALIAS_SYSTEMDEFAULT_ == 2){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMDEFAULT, NULL, SND_ALIAS_ID);
            }else if(sound.SND_ALIAS_SYSTEMEXCLAMATION_ == 3){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMEXCLAMATION, NULL, SND_ALIAS_ID);
            }else if(sound.SND_ALIAS_SYSTEMEXIT_ == 4){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMEXIT, NULL, SND_ALIAS_ID);
            }else if(sound.SND_ALIAS_SYSTEMHAND_ == 5){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMHAND, NULL, SND_ALIAS_ID);
            }else if(sound.SND_ALIAS_SYSTEMQUESTION_ == 6){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMQUESTION, NULL, SND_ALIAS_ID);
            }else if(sound.SND_ALIAS_SYSTEMSTART_ == 7){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMSTART, NULL, SND_ALIAS_ID);
            }else if(sound.SND_ALIAS_SYSTEMWELCOME_ == 8){
                PlaySound((LPCTSTR)SND_ALIAS_SYSTEMWELCOME, NULL, SND_ALIAS_ID);
            }else{
                return -1; // error
            }
            return 0;
        }

        // -------------------------------------------


    };


}


/*
compilation : 
g++ -o test.exe test.cpp -lwinmm
*/