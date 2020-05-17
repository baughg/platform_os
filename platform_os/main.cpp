#include <iostream>
#include <fstream>
#include "WindowsPlatform.h"

int main(int argc, char** argv) {
	GB::WindowsPlatform os{};
	std::cout << "git log running..." << std::endl;
	std::string batch_filename{ os.get_random_string(20) };
	batch_filename.append(os.get_shell_extension());
	std::ofstream batch_file{ batch_filename.c_str() };
	std::string git_log_filename{ os.get_random_string(20) };	
	batch_file << "git.exe log >";
	batch_file << git_log_filename << std::endl;
	batch_file << "git.exe checkout 440906005e9c3ca11cfe216591b279bac04486ef" << std::endl;
	batch_file << "git.exe ls-files >git_files.txt" << std::endl;
	batch_file.close();
	os.run_application("", batch_filename);
	std::vector<std::string> file_list{};

	os.subdirectory_content(".\\", file_list);

	std::cout << file_list.size() << std::endl;
	/*os.run_application("C:\\development\\vector_draw\\x64\\Debug\\vector_draw.exe", "");
	os.delete_file("draw.pdf");
	std::vector<std::string> file_list{};

	os.subdirectory_content("C:\\development\\vector_draw\\", file_list);*/
	return 0;
}