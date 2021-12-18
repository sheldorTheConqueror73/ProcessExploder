#include "GUI.h"
using namespace std;
void GUI::display_processes(list<ProcessInfo*>& processes)
{
	cout<< "NAME" << setw(27) << "PID"<< setw(10) <<"THREADS" <<setw(5)<<"   PATH\n";
	for (auto i = processes.begin(); i != processes.end(); i++)
	{

		wcout  <<((*i)->name) << setw(30) << (*i)->PID << setw(10) << (*i)->threads << setw(10) <<((*i)->path) <<"\n";
	}
}
