#pragma once

class WaveRecorder {

	static inline bool bstop = false;
public:
	WaveRecorder() = default;

	void start();
	void stop();
};