#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <list>
#include <iostream>
#include <psapi.h>
#include "ProcessInfo.h"
using namespace std;
bool get_processes(list<ProcessInfo>&);
bool get_process_name(DWORD, LPWSTR&);
