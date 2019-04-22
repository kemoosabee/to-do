#include"APIs.h"
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<ctime>
#include<chrono>
#include<algorithm>

using namespace std;


//unfinish,buggy
//to update the task's counter after doing modification
void update_counter(char* fname) {
	ifstream fin(fname);
	ofstream fout("temp_ctr");
	string read;
	int counter = 1;
	while (getline(fin, read)) {
		//std::string key = std::to_string(counter) + "  ";
		read.replace(read.begin(), read.end(), "1  ", "TEST");

	}
}

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
	//replace(task.begin(), task.end(), ' ', '_');

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
void updateStatus(char* fname,string num) {
	ifstream fin(fname);
	string read;
	
	 
}

//finished, to retrieve certain task from todo list, 
//by given the counter of the task
void retrieve(char* fname, string num) {

	ifstream fin(fname);
	string read;
	string key = num + "  ";
	int counter;
	while (getline(fin,read)){
		if (read.find(key, 0) != string::npos) {
			replace(read.begin(), read.end(), '_', ' ');
			cout << read << endl;
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
	if (ans == "ALL")
	{
		while (getline(fin,search)) {
			replace(search.begin(), search.end(), '_', ' ');
			cout << search << endl;
		}

	}
	else if (ans == "UNDONE") {
		while (getline(fin,search)) {
			if (search.find("UNDONE",0)!=string::npos){
				replace(search.begin(), search.end(), '_', ' ');
				cout << search << endl;

			}
		}
	}
	else if (ans == "DONE") {
		while (getline(fin, search)) {
			if (search.find(" DONE",0) != string::npos){
				replace(search.begin(), search.end(), '_', ' ');
				cout << search << endl;

			}
		}
	}
	else cout << "Please enter only ALL/ DONE/ UNDONE" << endl;
	fin.close();

}

//unfinished
//to delete specific line of todo list
void delete_todo(char* fname,string num) {
	string read;
	string key = num + "  ";
	ifstream fin(fname);
	ofstream fout("temp_dlt");
	while (getline(fin,read)) {
		if (read.find(key,0) == string::npos) {
			fout << read << endl;
		}
	}
}

//update the todo list after deleting it
void update_dlt(char* fname) {
	string task;
	int counter;
	ifstream fin("temp_dlt");
	ofstream fout(fname);
	while (getline(fin, task)) {
		fout << task << endl;
	}
}

//unfinished
//to clear the todo list
void delete_all(char* fname) {
	ofstream fout(fname);
}