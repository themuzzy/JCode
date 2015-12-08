// Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

// Runtime Variables
string command;
string line;
int line_number = 0;
bool editing_file = false;
bool program_running = true;

// Start Editing
void start_editing(){
  ofstream project("project.js");
  editing_file = true;
  line_number = 0;
  while(editing_file == true){
    line_number += 1;
    cout << line_number << " : ";
    getline(cin, line);
    if(line == "!SAVE"){
      project.close();
      editing_file = false;
    } else {
      project << line << "\n";
    }
  }
}

// Command Operator
void command_operator(){
  cout << "Command: ";
  getline(cin, command);
  if(command == "create"){
    start_editing();
  }
  if(command == "backup"){
    system("cp project.js project.backup");
  }
  if(command == "exit"){
    program_running = false;
  }
}

// Main Function
int main(){
  // Call the command operator
  while(program_running == true){
    command_operator();
  }
}
