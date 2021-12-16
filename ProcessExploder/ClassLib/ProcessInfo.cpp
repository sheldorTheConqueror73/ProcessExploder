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
	this->path = _wcsdup(entry.szExeFile);
	this->name = _wcsdup(name);
}