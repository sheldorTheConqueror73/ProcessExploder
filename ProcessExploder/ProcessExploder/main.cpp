#pragma once
#include <iostream>
#include "GUI.h"
#include "ProcessInfo.h"
#include "ProcessOperations.h"

using namespace std;

int main()
{
	bool flag;
	cout << "starting main\n";
	list<ProcessInfo*> processes;
	cout << "getting processes\n";
	flag=get_processes(processes);
	if(!flag)
		cout << "ERROR1\n";
	cout << processes.size() <<" processes discovered\n";
	cout << "starting GUI\n";
	GUI::display_processes(processes);
	return 0;
}