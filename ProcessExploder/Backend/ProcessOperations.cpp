#pragma once
#include "ProcessOperations.h"

bool get_processes(list<ProcessInfo*>& processes)
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
		processes.push_back(new ProcessInfo(process,name));
	} while (Process32Next(snap, &process));

	CloseHandle(snap);
	return true;
}

bool get_process_name(DWORD pid, LPWSTR &name)
{
	HANDLE process;
	DWORD length=1024;
	CHAR buffer[1024];
	process = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);


	if (process == NULL)
	{
		int num = GetLastError();
		cerr << "Error getting process name, pid:"<<pid<<"\n";
		return false;
	}

	if(! QueryFullProcessImageNameA(process, 0,buffer, &length))
	
	{
		name =_wcsdup(L"<UNKOWN>");
		CloseHandle(process);
		return false;
	}
	CloseHandle(process);
	return true;
}