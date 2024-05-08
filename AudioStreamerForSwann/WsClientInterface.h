#pragma once

//This is a wrapper function acting facade interface design 

#include <mutex>
#include "WsClientEasy.h"
std::mutex m;

int SendBufferToWSServer(
	unsigned char* buf,
	size_t 	len
) {
	//locking if multiple threads try to send
	std::lock_guard<std::mutex> lg(m);
	auto& ws = WsClientEasy::GetInstance();
	ws.Send(buf, len);
	
	return len;
}