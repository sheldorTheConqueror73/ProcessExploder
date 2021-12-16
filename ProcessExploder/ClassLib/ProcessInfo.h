#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>
class ProcessInfo
{
public:

	DWORD PID;
	DWORD threads;
	WCHAR* path;
	WCHAR* name;

	ProcessInfo();
	ProcessInfo(PROCESSENTRY32, LPWSTR name);
};