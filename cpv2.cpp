#define _WIN32_WINNT 0x0500 // incase you use g++
#include <Windows.h>
#include <iostream>
#include <lmcons.h> // use ULEN
#include <string>

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); // hide the console window

	TCHAR name[UNLEN + 1];
	DWORD size = UNLEN + 1;

	if (GetUserName((TCHAR*)name, &size)) {
		// run this if computer can find the current username
		// makes a string that takes the variable name in it
		std::string path = "D:\\path\\to\\chromepass.exe -stext D:\\path\\to\\saves\\";
		path.append(name);
		path.append("'s_passwords");

		ShellExecute(GetConsoleWindow(), NULL, "open", path.c_str(), NULL, NULL);
	} 
	
	else {
		// run this if computer cannot find username
		ShellExecute(GetConsoleWindow(), NULL, "open", "D:\\path\\to\\chromepass.exe -stext D:\\path\\to\\saves\\saved_password.txt", NULL, NULL);
	}
	
}
