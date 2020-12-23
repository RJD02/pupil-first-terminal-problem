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
		return 0;
	}
	fstream todo_txt;
	todo_txt.open("todo.txt", ios::in|ios::out);
	if(todo_txt == NULL) {
		cout << "Error opening the file" << "\n";
		exit(1);
	}
	if(!strcmp(argv[1], "add")) {
		string event;
		strcpy(event, argv[2]);
		add(todo_txt, event);
		return 0;
	}
	if(!strcmp(argv[1], "ls")) {
		display(todo_txt);
		return 0;
	}
	if(!strcmp(argv[1], "del")) {
		string event;
		strcpy(event, argv[2]);
		del(todo_txt, event);
		return 0;
	}
	if(!strcmp(argv[1], ))
}
