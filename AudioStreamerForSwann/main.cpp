
#include "bits/stdc++.h"
// AudioTransmitter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WaveRecorder.h"

extern int StartConnection(std::string);

int main()
{
    int port = 6587;
    std::string wsserverip = "3.25.140.218:8765";

    StartConnection(wsserverip);
    WaveRecorder wrc;
    wrc.start();

    wrc.stop();
    return 0;
}

