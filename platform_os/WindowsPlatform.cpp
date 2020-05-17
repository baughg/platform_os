#include "WindowsPlatform.h"
#include <array>
#include <tchar.h>
#include <stdio.h>

using namespace GB;

std::unique_ptr<wchar_t[]> WindowsPlatform::get_wide_char_string(const char *c)
{
	const size_t cSize{ strlen(c) + 1 };
	std::unique_ptr<wchar_t[]> wc{ std::make_unique<wchar_t[]>(cSize) };
	size_t chars_converted{};
	mbstowcs_s(&chars_converted, wc.get(), cSize, c, cSize);
	return wc;
}

bool WindowsPlatform::run_application(
	const std::string &appName, const std::string &cmdLineArgs) {
	TCHAR* AppName{};
	TCHAR* CmdLine{};
	std::unique_ptr<wchar_t[]> appNamePtr{};
	std::unique_ptr<wchar_t[]> cmdLinePtr{};

	if (appName.length()) {
		appNamePtr = get_wide_char_string(appName.c_str());
		AppName = reinterpret_cast<TCHAR*>(appNamePtr.get());		
	}

	if (cmdLineArgs.length()) {
		cmdLinePtr = get_wide_char_string(cmdLineArgs.c_str());
		CmdLine = reinterpret_cast<TCHAR*>(cmdLinePtr.get());
	}
	
	PROCESS_INFORMATION processInformation{};
	STARTUPINFO startupInfo{};
	startupInfo.cb = sizeof(startupInfo);
	startupInfo.wShowWindow = SW_HIDE;
	//startupInfo.wShowWindow = SW_SHOWNORMAL;

	BOOL result{};
	//Needed since CreateProcessW may change the contents of CmdLine
	std::array<TCHAR, MAX_PATH << 1 > tempCmdLine{};
	 
	if (CmdLine)
	{
		_tcscpy_s(tempCmdLine.data(), MAX_PATH << 1, CmdLine);
		result = ::CreateProcess(
			AppName, tempCmdLine.data(), NULL, NULL, FALSE, CREATE_NO_WINDOW, 
			NULL, NULL, &startupInfo, &processInformation);
	}
	else
	{
		result = ::CreateProcess(
			AppName, CmdLine, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, 
			NULL, NULL, &startupInfo, &processInformation);
	}
	
	if (result == 0)
	{
		auto last_err{ GetLastError() };
		return false;
	}

	WaitForSingleObject(processInformation.hProcess, INFINITE);
	CloseHandle(processInformation.hProcess);
	CloseHandle(processInformation.hThread);
	return true;
}

uint32_t WindowsPlatform::directory_content(
	const std::string &dir,
	std::vector<std::string> &file_list,
	std::vector<std::string> &dir_list) {
	return 0;
}

int WindowsPlatform::delete_file(const std::string &file_name) {
	std::unique_ptr<wchar_t[]> file_name_ptr{ get_wide_char_string(file_name.c_str()) };		
	return static_cast<int>(::DeleteFile(file_name_ptr.get()));
}
