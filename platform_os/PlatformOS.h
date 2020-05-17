#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace GB {
	class PlatformOS
	{
	public:		
		virtual bool run_application(const std::string &appName, const std::string &cmdLineArgs) = 0;
		
		virtual uint32_t directory_content(
			const std::string &dir,
			std::vector<std::string> &file_list,
			std::vector<std::string> &dir_list) {
			return 0;
		};

		virtual int delete_file(const std::string &file_name) = 0;

		void subdirectory_content(
			const std::string &_dir, 
			std::vector<std::string> &file_list, bool alloc = true);

		std::string get_random_string(const uint32_t &sz);

		virtual std::string get_slash() = 0;
		virtual std::string get_shell_extension() = 0;
	};
}

