#pragma once

#include <memory>
#include "easywsclient.hpp"
using namespace easywsclient;

class WsClientEasy {

    std::string connstr;
    std::unique_ptr<WebSocket> ws;

    WsClientEasy() ;
    WsClientEasy(const WsClientEasy&) = default;
    WsClientEasy(std::string conn);

public:
    ~WsClientEasy();
    static WsClientEasy& GetInstance();

    int Send(unsigned char* buffer, int len);
};