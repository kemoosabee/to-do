# to-do

This program is written in Visual Studio.
To those who wish to run this program in visual studio, 
please follow the instruction below to change your preprocessor definition.
go to project\project properties\configuration properties\C/C++\preprocessor
and add  ;_CRT_SECURE_NO_WARNINGS   after your preprocessor definition.

The final result should look like 
MBCS;%(PreprocessorDefinitions);_CRT_SECURE_NO_WARNINGS


All the feature in the todo list:

GET           -to print out the tasks, by applying a filter user provide(ALL/DONE/UNDONE).
CREATE        -to create a new task.
RETRIEVE      -to print out certain task by providing the task number.
DELETE        -to delete certain task by providing the task numner, by entering ALL, the user get to clear the todo list
UPDATE        -to update the task status from undone to done.
COUNT         -tell user how many task is on the todo list
LOG           -to print out when the file was created/updated/deleted.
