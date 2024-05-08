
#include "WsClientEasy.h"
#ifdef _WIN32
#pragma comment( lib, "ws2_32" )
#include <WinSock2.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <string>
#include <memory>

extern std::atomic_bool States;

WsClientEasy::WsClientEasy() {
#ifdef _WIN32
    INT rc;
    WSADATA wsaData;

    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc) {
        printf("WSAStartup Failed.\n");
        return;
    }
#endif
    connstr = "ws://3.25.140.218:8765";
    ws.reset(WebSocket::from_url(connstr));

    States = true;
}

WsClientEasy& WsClientEasy::GetInstance() {
    static WsClientEasy ws;
    return ws;
}

WsClientEasy::~WsClientEasy() {
#ifdef _WIN32
    WSACleanup();
#endif
}

int WsClientEasy:: Send(unsigned char* buffer, int len) {

    std::string str((const char*)buffer);
    ws->send(str);
    return 0;
}