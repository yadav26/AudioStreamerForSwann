
#include "bits/stdc++.h"
// AudioTransmitter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WaveRecorder.h"

extern int StartConnection(std::string);

int main()
{
    int port = 8765;
    std::string wsserverip = "3.25.140.218:8765";

    std::thread th([&]() {
        StartConnection(wsserverip);
        }
    );

    std::thread thAudio([&]() {
            WaveRecorder wrc;
            wrc.start();
        }
    );
    thAudio.join();


    
    th.join();
    return 0;
}

