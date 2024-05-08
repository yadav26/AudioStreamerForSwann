
#include "bits/stdc++.h"
// AudioTransmitter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WaveRecorder.h"

extern int StartConnection(std::string);

std::atomic_bool States(false);

int main()
{
    int port = 8765;
    std::string wsserverip = "wss://3.25.140.218:8765";

    std::thread th([&]() {
        //here it should establish wss client connection
        StartConnection(wsserverip);
        }
    );


    std::thread thAudio([&]() {
            //below we will get the audio buffer recorded into file if 
            //system is disconnected state
            WaveRecorder wrc;
            wrc.start();
        }
    );
    thAudio.join();
    th.join();

    //Fix: termination crash - anshul 
    return 0;
}

