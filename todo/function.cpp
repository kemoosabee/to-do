#include"APIs.h"
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<ctime>
#include<chrono>
#include<algorithm>

using namespace std;


//to update the task's counter after doing modification
void update_counter(char* fname) {
	ifstream fin(fname);
	ofstream fout("temp_ctr");
	string read,task,counter,status,dt;
	int count = 1;
	fin >> counter >> task >> status >> dt;
	while (fin) {
		fout << count << "   "
			<< task << "   " << status <<
			"   " << dt << endl;
		fin >> counter >> task >> status >> dt;
		count++;
	}
	update_refresh(fname);
	fin.close();
	fout.close();
}

void update_refresh(char* fname) {
	ifstream fin("temp_ctr");
	ofstream fout(fname);
	string read;
	while (getline(fin, read))
		fout << read << endl;
	fout.close();
	fin.close();
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
	replace(task.begin(), task.end(), ' ', '_');

	fout << countTask(fname)+1 << "   ";
	fout << task << "   " << "UNDONE" << "   ";
	fout << getTime();

	create_log(task);

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
	fin.close();
}


//finished, a method to update the task status and send back into todo list
void update_dou(char* fname) {
	ifstream fin("temp_sts");
	ofstream fout(fname);
	string read;
	while (getline(fin, read)) {
		fout << read << endl;
	}
	fin.close();
	fout.close();
}



//finished, to update the task's status
void updateStatus(char* fname,string num) {
	update_counter(fname);
	ifstream fin(fname);
	ofstream fout("temp_sts");
	string task, counter, status, dt;
	string key = num + "  ";
	fin >> counter >> task >> status >> dt;
	while (fin) {
		
		if (counter == num) {
			fout << counter << "   "
				<< task << "   " << "DONE" <<
				"   " << dt << endl;
		}
		else {
			fout << counter << "   "
				<< task << "   " << status <<
				"   " << dt << endl;
		}

		fin >> counter >> task >> status >> dt;
	}
	fin.close();
	fout.close();
}

//finished, to retrieve certain task from todo list, 
//by given the counter of the task
void retrieve(char* fname, string num) {

	ifstream fin(fname);
	string read;
	string key = num + "  ";
	while (getline(fin,read)){
		if (read.find(key, 0) != string::npos) {
			replace(read.begin(), read.end(), '_', ' ');
			cout << read << endl;
		}
		//else cout << "Please enter a correct value for your task." << endl;
			
	}
	fin.close();
}


//finished, to filter task (done/undone) or all
void get_task(char* fname, string ans) {
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


//finished, to delete specific line of todo list
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
	fin.close();
	fout.close();
}

//update the todo list after deleting it
void update_dlt(char* fname) {
	string task;
	ifstream fin("temp_dlt");
	ofstream fout(fname);
	while (getline(fin, task)) {
		fout << task << endl;
	}
	fin.close();
	fout.close();
}


//finished
//to clear the todo list
void delete_all(char* fname) {
	ofstream fout(fname);
	fout.close();
}

void dlt_all_log() {
	ofstream fout("log", ios::app);
	fout << "All task has been deleted   " << getTime() << endl;
	fout.close();
}


//finished, to register the delete into log file
void delete_log(char* fname, string dlt_task) {
	ifstream fin(fname);
	ofstream fout("log", ios::app);
	string counter, task, status, dt;
	fin >> counter >> task >> status >> dt;
	while (fin) {
		if (counter == dlt_task) {
			replace(task.begin(), task.end(), '_', ' ');
			fout << task << "   "
				<< "deleted on " << getTime() << endl;
		}
		fin >> counter >> task >> status >> dt;
	}
	fin.close();
	fout.close();
}

//finisehd, to regiester the status change log into log file
void update_log(char* fname, string updt_task) {
	ifstream fin(fname);
	ofstream fout("log", ios::app);
	string counter, task, status, dt;
	fin >> counter >> task >> status >> dt;
	while (fin) {
		if (counter == updt_task) {
			replace(task.begin(), task.end(), '_', ' ');
			fout <<  task << "   "
				<< "finished on " << getTime() << endl;
		}
		fin >> counter >> task >> status >> dt;
	}
	fin.close();
	fout.close();;
}

void create_log(string create_task) {
	ofstream fout("log", ios::app);
	replace(create_task.begin(), create_task.end(), '_', ' ');
	fout << create_task << "  "
		<< "created on " << getTime() << endl;

	fout.close();
}

//finished, to print out log
void show_log() {
	ifstream fin("log");
	//
	ofstream fout("temp_log");
	string read;
	while (getline(fin, read)) {
		cout << read << endl;
	}
	fin.close();
	fout.close();
}
