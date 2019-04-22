#ifndef API_H
#define API_H

#include<string>

using namespace std;

void createTask(char* fname, string task);
void updateStatus(char* fname,int num);
void retrieve(char* fname, int num);
void get(char* fname, string status);
int countTask(char* fname);
void delete_todo(char* fname,int num);
void delete_all(char* fname);
string getTime();

#endif