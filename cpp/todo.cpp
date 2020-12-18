#include <iostream>
#include<algorithm>
#include<cstring>
#include <string>
using namespace std;

#define debug(c, n) cout << c << n;

void help() {
	cout << "Usage :-\n";
	cout << "./todo add \"todo item\"\t# Add a new todo\n";
	cout << "./todo ls\t# Show remaining todos\n";
	cout << "./todo del NUMBER\t# Delete a todo\n";
	cout << "./todo done NUMBER\t# Complete a todo\n";
	cout << "./todo help\t# Show usage\n";
	cout << "./todo report\t# Statistics\n";
	cout << "\n";
}

int main(int argc, char const *argv[])
{
	if(argc == 0 || !strcmp(argv[1], "help")) {
		help();
	}
	cout << "HELLO WORLD\n";
	return 0;
}
