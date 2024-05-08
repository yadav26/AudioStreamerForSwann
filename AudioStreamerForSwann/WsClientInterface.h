#pragma once

//This is a wrapper function 
//Expected to write buffer to libwesocket connection established.
//however its not yet done. need time to research.
#include <mutex>
std::mutex m;

int SendBufferToWSServer(
	unsigned char* buf,
	size_t 	len
) {
	std::lock_guard<std::mutex> lg(m);
	//m = lws_write(wsi, ((unsigned char*)pmsg->payload) + LWS_PRE, pmsg->len, LWS_WRITE_TEXT);
	return len;
}