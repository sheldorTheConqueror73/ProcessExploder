#include "GUI.h"
using namespace std;
void GUI::display_processes(list<ProcessInfo>& processes)
{
	cout<<setw(30) << "NAME" << setw(10)<<"PID"<< setw(5) <<"  THREADS" << setw(50)<<"PATH\n";
	for (auto i = processes.begin(); i != processes.end(); i++)
	{
		cout << setw(30) <<i->name << setw(10) << i->PID << setw(5) <<i->threads << setw(50) <<i->path <<"\n";
	}
}
