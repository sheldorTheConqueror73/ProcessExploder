#pragma once
#include "ProcessOperations.h"

bool get_processes(list<ProcessInfo>& processes)
{
	HANDLE snap;
	PROCESSENTRY32 process;
	processes = {};

	snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE)
	{
		cerr << "Error creating snapshot\n";
		return false;
	}

	process.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(snap, &process))
	{
		cerr << "Error getting first process\n";
		CloseHandle(snap);
		return false;
	}
	LPWSTR name;
	do
	{
		get_process_name(process.th32ProcessID, name);
		processes.push_back(ProcessInfo(process,name));
	} while (Process32Next(snap, &process));

	CloseHandle(snap);
	return true;
}

bool get_process_name(DWORD pid, LPWSTR &name)
{
	HANDLE process;
	DWORD length;
	process = OpenProcess(READ_CONTROL, FALSE, pid);


	if (process == INVALID_HANDLE_VALUE)
	{
		cerr << "Error getting process name, pid:"<<pid<<"\n";
		return false;
	}

	length = GetModuleBaseNameW(process, NULL, name, 30);
	if (!length)
	{
		name =_wcsdup(L"<UNKOWN>");
		CloseHandle(process);
		return false;
	}
	CloseHandle(process);
	return true;
}