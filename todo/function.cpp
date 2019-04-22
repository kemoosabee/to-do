#include"APIs.h"
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<ctime>
#include<chrono>
#include<algorithm>

using namespace std;

//to register current time into log .
string getTime()
{
	time_t now = time(0);
	string dt = ctime(&now);
	replace(dt.begin(), dt.end(), ' ', '_');
	return dt;
}

//finished, to input task into the todo list
void createTask(char* fname, string task) {

	ofstream fout(fname, ios::app);
	replace(task.begin(), task.end(), ' ', '_');
	int test = 10;

	fout << countTask(fname)+1 << "   ";
	fout << task << "   " << "UNDONE" << "   ";
	fout << getTime();

	fout.close();
	
}

//finished, to provide the counter and number for task
int countTask(char* fname) {
	int counter = 0;
	string item;
	ifstream fin(fname);
	while (getline(fin, item))
	{
		counter++;
	}
	return counter;
}

//unfinish
void updateStatus(char* fname,int num) {
	ifstream fin(fname);
	 
}

//finished, to retrieve certain task from todo list, 
//by given the counter of the task
void retrieve(char* fname, int num) {

	ifstream fin(fname);
	string task, dt, status;
	int counter;
	while (!fin.eof()) {
		fin >> counter >> task >> status >> dt;
		if (counter == num) {
			replace(task.begin(), task.end(), '_', ' ');
			replace(dt.begin(), dt.end(), '_', ' ');
			cout << counter << "   " << task << "  " << status <<
				"   " << dt << endl;
		
		}
		
	}
	fin.close();
}


//unfix bug,the last line of the file tend to print twice
//filter (done/undone) or all
void get(char* fname, string ans) {
	ifstream fin(fname);
	int counter;
	string search;
	string task, dt, status;
	if (ans == "ALL")
	{
		while (!fin.eof()) {

			fin >> counter >> task >> status >> dt;
			replace(task.begin(), task.end(), '_', ' ');
			replace(dt.begin(), dt.end(), '_', ' ');
			cout << counter << "  " << task <<
				"   " << status << "   " << dt << endl;
		}

	}
	else if (ans == "DONE") {
		while (!fin.eof()) {
			fin >> counter >> task >> status >> dt;
			if (status == "DONE")
			{
				replace(task.begin(), task.end(), '_', ' ');
				replace(dt.begin(), dt.end(), '_', ' ');
				cout << counter << "  " << task <<
					"   " << status << "   " << dt << endl;
			}
		}
	}
	else if (ans == "UNDONE") {
		while (!fin.eof()) {
			fin >> counter >> task >> status >> dt;
			if (status == "UNDONE")
			{
				replace(task.begin(), task.end(), '_', ' ');
				replace(dt.begin(), dt.end(), '_', ' ');
				cout << counter << "  " << task <<
					"   " << status << "   " << dt << endl;
			}
		}
	}
	else cout << "Please enter only ALL/ DONE/ UNDONE" << endl;

}

//unfinished
//to delete specific line of code
void delete_todo(char* fname,int num) {
	string task,status,dt;
	int counter;
	ifstream fin(fname);
	while (!fin.eof()) {
		fin >> counter >> task >> status >> dt;
		if (num == counter) {
			fin.clear();
		}
	}
}

//unfinished
//to clear the todo list
void delete_all(char* fname) {
	ofstream fout(fname);

}