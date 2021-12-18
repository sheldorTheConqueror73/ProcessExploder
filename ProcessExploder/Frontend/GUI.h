#pragma once
#include "ProcessInfo.h"
#include <iostream>
#include <list>
#include <iomanip> 
using namespace std;
class GUI
{
public:
	GUI() {};
	static void clear(){if (system("CLS")) system("clear");}
	static void display_processes(list<ProcessInfo*>&);
};

