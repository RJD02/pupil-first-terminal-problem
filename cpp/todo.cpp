#include <iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<fstream>
using namespace std;
#include"todo.hpp"
#define debug(c, n) cout << c << n;

int main(int argc, char const *argv[])
{
	if(argc == 1 || !strcmp(argv[1], "help")) {
		help();
	}
	// cout << "HELLO WORLD\n";
	fstream todo_txt;
	todo_txt.open("todo.txt", ios::in);
	if(!todo_txt) {
		cout << "Error";
		exit(1);
	}
	//For "ls" command.
	if(!strcmp(argv[1], "ls")) {
		display(todo_txt);
		return 0;
	}
	//For "add" command.
	// if (!strcmp(argv[1], "add")) {
	// 	string event;
	// 	strcpy(event, argv[2]);
	// 	add(todo_txt_write, event);
	// 	return 0;
	// }
	return 0;
}
