#include <iostream>
#include "WindowsPlatform.h"

int main(int argc, char** argv) {
	GB::WindowsPlatform os{};

	os.run_application("C:\\development\\vector_draw\\x64\\Debug\\vector_draw.exe", "");
	return 0;
}