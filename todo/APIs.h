#ifndef API_H
#define API_H

#include<string>

using namespace std;

void createTask(char* fname, string task);
void updateStatus(char* fname,string num);
void retrieve(char* fname, string num);
void get(char* fname, string status);
int countTask(char* fname);
void delete_todo(char* fname,string num);
void delete_all(char* fname);
void update_dlt(char* fname);
void update_counter(char* fname);
void update_refresh(char* fname);
void update_dou(char* fname);
void delete_log(char* fname, string dlt_task);
void update_log(char* fname, string updt_task);
string getTime();

#endif