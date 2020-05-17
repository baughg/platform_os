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
			std::vector<std::string> &dir_list) = 0;

		virtual int delete_file(const std::string &file_name) = 0;
	};
}
