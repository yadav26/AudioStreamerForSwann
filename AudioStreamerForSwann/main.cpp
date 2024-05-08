
#include "bits/stdc++.h"
// AudioTransmitter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WaveRecorder.h"
#include "WsClientEasy.h"

std::atomic_bool States(false);

int main()
{
    auto& ws = WsClientEasy::GetInstance();

    std::thread thAudio([&]() {
            //below we will get the audio buffer recorded into file if 
            //system is disconnected state
            WaveRecorder wrc;
            wrc.start();
        }
    );
    thAudio.join();
    //Fix: termination crash - anshul 
    return 0;
}

