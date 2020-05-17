#pragma once
#include "PlatformOS.h"
#include <memory>
#include<vector>
#include<Windows.h>
#include<iostream>
#include <direct.h>
#include <io.h>

namespace GB {
	class WindowsPlatform :
		public PlatformOS
	{
	public:
		bool run_application(const std::string &appName, const std::string &cmdLineArgs) override;

		uint32_t directory_content(
			const std::string &dir,
			std::vector<std::string> &file_list,
			std::vector<std::string> &dir_list) override;

		int delete_file(const std::string &file_name) override;
	private:
		std::unique_ptr<wchar_t[]> get_wide_char_string(const char *c);
	};
}

