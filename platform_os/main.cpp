#include <iostream>
#include "WindowsPlatform.h"

int main(int argc, char** argv) {
	GB::WindowsPlatform os{};

	os.run_application("C:\\development\\vector_draw\\x64\\Debug\\vector_draw.exe", "");
	os.delete_file("draw.pdf");
	std::vector<std::string> file_list{};

	os.subdirectory_content("C:\\development\\vector_draw\\", file_list);
	return 0;
}