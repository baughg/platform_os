#include "PlatformOS.h"
#include <array>

using namespace GB;


void PlatformOS::subdirectory_content(
	const std::string &_dir,
	std::vector<std::string> &file_list, bool alloc)
{
	file_list.clear();	
	std::vector<std::string> dir_list{};
	std::vector<std::string> dir_list_sec{};
	directory_content(_dir, file_list, dir_list);

	if (alloc) {
		file_list.reserve(1000000);
		dir_list_sec.reserve(10000);
	}
	else {
		dir_list_sec.reserve(10);
	}


	std::array<char, 1024> dir{};

	while (dir_list.size() > 0) {
		for (size_t d = 0; d < dir_list.size(); d++) {
			sprintf(dir.data(), "%s", dir_list[d].c_str());
			directory_content(std::string{ dir.data() }, file_list, dir_list_sec);
		}

		dir_list.clear();
		dir_list = dir_list_sec;
		dir_list_sec.clear();
	}
}

std::string PlatformOS::get_random_string(const uint32_t &sz) {
	std::vector<char> buffer(sz+1);

	for (uint32_t i{ 0 }; i < sz; ++i) {
		buffer[i] = 'a' + static_cast<char>(std::rand() % 26);
	}

	return std::string{ &buffer[0] };
}