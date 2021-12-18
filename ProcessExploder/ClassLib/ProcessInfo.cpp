#pragma once
#include "ProcessInfo.h"

ProcessInfo::ProcessInfo()
{
	this->PID = -1;
	this->threads = 0;
	this->path = NULL;
	this->name = NULL;
}
ProcessInfo::ProcessInfo(PROCESSENTRY32 entry, LPWSTR name)
{
	this->PID = entry.th32ProcessID ;
	this->threads = entry.cntThreads;
	this->path = new WCHAR[40];
	 wcsncpy_s(this->path,39, entry.szExeFile, 40);
	this->name = name;
}