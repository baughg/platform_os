#include <iostream>
#include <fstream>
#include "WindowsPlatform.h"

int main(int argc, char** argv) {
	GB::WindowsPlatform os{};
	std::cout << "git log running..." << std::endl;
	std::ofstream batch_file{ "runproc.bat" };
	batch_file << "git.exe log >random_log.txt";
	batch_file.close();
	os.run_application("", "runproc.bat");
	std::vector<std::string> file_list{};

	os.subdirectory_content(".\\", file_list);

	std::cout << file_list.size() << std::endl;
	/*os.run_application("C:\\development\\vector_draw\\x64\\Debug\\vector_draw.exe", "");
	os.delete_file("draw.pdf");
	std::vector<std::string> file_list{};

	os.subdirectory_content("C:\\development\\vector_draw\\", file_list);*/
	return 0;
}