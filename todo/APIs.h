#ifndef API_H
#define API_H

#include<string>

using namespace std;

int countTask(char* fname);
void createTask(char* fname, string task);
void updateStatus(char* fname,string num);
void retrieve(char* fname, string num);
void get_task(char* fname, string status);
void delete_todo(char* fname,string num);
void delete_all(char* fname);
void update_dlt(char* fname);
void update_counter(char* fname);
void update_refresh(char* fname);
void update_dou(char* fname);
void delete_log(char* fname, string dlt_task);
void update_log(char* fname, string updt_task);
void dlt_all_log();
void create_log(string create_task);
void show_log();
string getTime();

#endif