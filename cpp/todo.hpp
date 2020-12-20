#ifndef TODO_HPP
#define TODO_HPP

void help() {
	cout << "Usage :-\n";
	cout << "./todo add \"todo item\"  # Add a new todo\n";
	cout << "./todo ls               # Show remaining todos\n";
	cout << "./todo del NUMBER       # Delete a todo\n";
	cout << "./todo done NUMBER      # Complete a todo\n";
	cout << "./todo help             # Show usage\n";
	cout << "./todo report           # Statistics\n";
	cout << "\n";
}

int count(fstream &todo_txt) {
  int count = 0;
  string line;
  while (!todo_txt.eof()) {
    getline(todo_txt, line);
    count++;
  }
  return count - 1;
}

void display(fstream &todo_txt) {
  int lim = count(todo_txt);
  if (lim == 0) {
    cout << "No lines";
    return ;
  }
  string out[50];
  string exp;
  int i = 0;
  todo_txt >> exp;
  cout << exp << "\n";
  cout << todo_txt << "\n";
  while (!todo_txt.eof()) {
    getline(todo_txt, /*out[i]*/ exp);
    cout << exp << "\n";
    i++;
  }
  for(int i = 0; i < lim; i++) {
    std::cout << "[" << i + 1 << "]" << " " << out[lim - 1 - i] << '\n';
  }
}

#endif
