#include<iostream>
#include<fstream>
#include<chrono>
#include<string>
#include<ctime>
#include"APIs.h"

using namespace std;

bool fexist(char* fname)
{
	ifstream fin;
	fin.open(fname);

	bool f_exist = fin.is_open();
	fin.close();
	return f_exist;
}


//create a empty database 
void createdb(char* fname)
{
	ofstream fout(fname);
	//to prevent overwrting todo list without knowing it
	if (fexist(fname)==1) {
		cout << "You enter an existing name, do you sure you want to overwrite it?" << endl;
		cout << "Please enter Y/N" << endl;
		char yn;
		cin >> yn;
		if (yn == 'N' || yn == 'n')
			return ;
	}
	fout.close();

}
//open an existing todo list
void openDb(char* fname)
{
	ifstream fin(fname);

	while (!fin) {
		cout << "You entered a non existing file name, please try again." << endl;
		cout << "If you wish to terminate this program please enter END" << endl;

		cin >> fname;
		if (fname == "END") //doesnt always work, this is to terminate the cycle
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
		system("cls");
		cout << "Name your to-do list" << endl;
		cin >> name_db;
		createdb(name_db);
	}
	else if (ans == 'O')
	{
		system("cls");
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
			system("cls");
			cout << "Please enter your task" << endl;
			string task;
			cin.ignore();
			getline(cin,task);
			createTask(name_db, task);

		}

		else if (api == "RETRIEVE") {
			system("cls");
			cout << "Which task do you wish to retrieve" << endl;
			string num_task;
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
			if (dlt_task == "ALL") {
				delete_all(name_db);
				system("cls");
			}
			else
			{
				delete_log(name_db, dlt_task);
				delete_todo(name_db, dlt_task);
				update_dlt(name_db);
				update_counter(name_db);
				system("cls");
			}
		}
		else if (api == "GET")
		{
			system("cls");
			cout << "What kind of tasks do you wish to get(ALL,DONE,UNDONE)"
				<< endl;
			string ans;
			cin >> ans;
			get_task(name_db, ans);

		}

		else if (api == "COUNT")
		{
			system("cls");
			cout << countTask(name_db);
			cout << endl;
		}

		else if (api == "UPDATE")
		{
			cout << "Which task do you wish to update?" << endl;
			string task;
			cin >> task;
			system("cls");
			updateStatus(name_db, task);
			update_dou(name_db);
			update_log(name_db, task);
			
		}
		else cout << "You enter the wrong command, please try again" << endl;
		
	}


	return 0;
}
