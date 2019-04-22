#include<iostream>
#include<fstream>
#include<chrono>
#include<string>
#include<ctime>
#include"APIs.h"

using namespace std;

//create a empty database 
void createdb(char* fname)
{
	ofstream fout(fname);
	//to prevent overwrting todo list without knowing it
	if (fout) {
		cout << "You enter an existing name, do you sure you want to overwrite it?" << endl;
		cout << "Please enter Y/N" << endl;
		char yn;
		cin >> yn;
		if (yn == 'N' || yn == 'n')
			return ;
	}

}
//open an existing todo list
void openDb(char* fname)
{
	ifstream fin(fname);

	while (!fin) {
		cout << "You entered a non existing file name, please try again." << endl;
		cout << "If you wish to terminate this program please enter END" << endl;

		cin >> fname;
		if (fname == "END") //doesnt work, this is to terminate the cycle
			return;
		fin.open(fname);
	}
}

int main()
{
	char name_db[100];
	string api;
	char ans;
	cout << "Do you wish to create a new todo list or edit the old todo list?" << endl;
	cout << "N for creating a new todo list"<< endl;
	cout << "O for editing or reading the old todo list" << endl;
	cin >> ans;

	//createdb(name_db);
	if (ans == 'N') {
		cout << "Name your to-do list" << endl;
		cin >> name_db;
		createdb(name_db);
	}
	else if (ans == 'O')
	{
		cout << "Please enter the todo list you wish to edit /open" << endl;
		cin >> name_db;
		openDb(name_db);

	}
	else cout << "Plase enter only New / Old" << endl;

	while (api != "END")
	{
		cout << "What do you wish to do";
		cout << "(CREATE/ RETRIEVE/ DELETE/ GET/ COUNT)" << endl;
		cout << "To terminate the program enter END" << endl;
		cin >> api;

		if (api == "CREATE")
		{
			cout << "Please enter your task" << endl;
			string task;
			cin.ignore();
			getline(cin,task);
			createTask(name_db, task);

		}

		else if (api == "RETRIEVE") {
			cout << "Which task do you wish to retrieve" << endl;
				
			int num_task = 0;
			cin >> num_task;
			retrieve(name_db, num_task);
			// a function to retrieve task.
		}

		else if (api == "DELETE")
		{
			string dlt_task;
			cout << "Which task do you wish to delete?" << endl
				<< "For clearing the to-do list, please enter ALL" << endl;
			cin >> dlt_task;
			//a function to delete task, or all task
		}
		else if (api == "GET")
		{
			cout << "What kind of tasks do you wish to get(ALL,DONE,UNDONE)"
				<< endl;
			string ans;

			cin >> ans;
			get(name_db, ans);

		}

		else if (api == "COUNT")
		{
			cout << countTask(name_db);
			cout << endl;
		}

		else cout << "You enter the wrong command, please try again" << endl;
	}


	return 0;
}