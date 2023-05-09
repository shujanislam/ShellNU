
#include<iostream>          // for some basic stuff
#include<unistd.h>          // for system stuff
#include<map>               // for map 
#include<stdlib.h>
#include<string>            // for some basic functions like substr()
#include "header/file.h"    // header file that contains login/register functions
#include "header/func.hpp"    // header file that contains all the shell functions

// checking if the Operating System is Windows or Linux

#if defined(_WIN32) || defined(_WIN64)
    const char* os = "windows";
#else
    #if defined __linux
        const char* os = "linux";
#else
    const char* os = "unknown";
#endif
#endif

// to get the current directory
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}

// Map that contains all the help commands
std::map<std::string, std::string> Help = {
    {"v", "to check the version of the terminal"},
    {"xt", "to exit the terminal"}, 
    {"register", "to register your account"}, 
    {"login", "to login as an admin"},
    {"ls", "to look up all the files in the current directory"},
    {"cd <destination>", "to change the directory"},
    {"cd .. or ..", "to go back of the directory"},
    {"touch <name>", "to create a new file"},
    {"rm <name>", "to delete a file or a folder"},
    {"pwd", "returns the current working directory"},
    {"clear", "to clear the screen"},
    {"echo <string>", "to display a string in the shell"},
    {"rename <filename>", "to rename a filename"},
    {"whoami", "returns the user of the machine"},
    {"cat <filename>", "returns the content of a file"},
    {"lscpu", "returns the cpu specifications"},
    {"credits", "returns the creator of the ShellNU program"},
    {"c <filename>", "compiles and runs a c program"},
    {"cpp <filename>", "compiles and runs a c++ program"},
    {"py <filename>", "compiles and runs a python program"},
    {"nano <filename>", "to edit a file using nano text editor"},
    {"ffplay <filename>", "to play a video file using ffplay"}
};

void command_function();    // function which will contain all the commands

// the main function
int main(){
    
    // taking command input starts here
    command_function();

    return 0;

}

// the linux function starts here
void command_function(){
    std::string command;

    // clearing the screen
    if(os == "linux"){
        system("clear");
    }
    else if(os == "windows"){
        system("cls");
    }
    else{
        system("clear");
    }

    // while loop to take command inputs until the user enters xt command to exit
    while(command != "xt"){
        if(os == "linux"){
            std::cout << "\n\033[1;33muser\033[0m@\033[1;31mlinux\033[0m:~"<<get_current_dir()<<"\033[1;34m$\033[0m ";
        }
        else if(os == "windows"){
            std::cout << "\n\033[1;33muser\033[0m@\033[1;31mwindows\033[0m:~"<<get_current_dir()<<"\033[1;34m$\033[0m ";
        }
        else{
            std::cout << "\n\033[1;33muser\033[0m@\033[1;31muser\033[0m:~"<<get_current_dir()<<"\033[1;34m$\033[0m ";
        }

        std::getline(std::cin, command);
    
        // to register an admin
        if(command == "register"){
            Admin admin_register;
            std::cout<<"Enter your username: ";
            std::cin>>admin_register.username;
            std::cout<<"Enter your password: ";
            std::cin>>admin_register.password;

            registerUser(admin_register.username, admin_register.password);
        }  
        // to login using admin credentials
        else if(command == "login"){
            Admin admin_login;
            std::cout<<"Enter your username: ";
            std::cin>>admin_login.username;
            std::cout<<"Enter your password: ";
            std::cin>>admin_login.password;

            loginUser(admin_login.username, admin_login.password);
        }
        // to check the version of ShellNU
        else if(command == "v"){
            shellVersion();
        }
        // to retrieve all the help commands
        else if(command == "help"){
            for(auto itr = Help.begin(); itr != Help.end(); itr++){
                std::cout<<(*itr).first<<" : "<<(*itr).second<<"\n\n";
            }
        }
        // to clear the screen
        else if(command == "clear" || command == "cls"){
            clearScreen(os);
        }
        // to echo a string in the console
        else if(command.rfind("echo ") == 0){
            std::string echo_str = command.substr(command.find_first_of(" \t")+1);
            std::cout<<echo_str;
        }
        // echo to write in a file
        else if(command.rfind("write ") == 0){
            std::string echo_str = command.substr(command.find_first_of(" \t")+1);
            echoFile(echo_str);
        }
        // to create a file
        else if(command.rfind("touch ") == 0){
            std::string file_name=command.substr(command.find_first_of(" \t")+1);
            createFile(file_name);
        }
        // to come back of the directory
        else if(command == ".." || command == "cd .."){
            chdir("..");
        }
        // to change directory
        else if(command.rfind("cd ") == 0){
            std::string dir = command.substr(command.find_first_of(" \t")+1);
            changeDir(dir);
        }
        // to list all the files in the directory
        else if(command == "ls" || command == "dir"){
            listFiles(os);
        }
        // to delete a file or a folder
        else if(command.rfind("rm ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t") + 1);
            delFileFolder(file_name);
        }
        // returns the current working directory
        else if(command == "pwd"){
            pwd(os);
        }
        // to rename a file
        else if(command.rfind("rename ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t")+1);
            renameFile(file_name);
        }
        // returns the user of the machine
        else if(command == "whoami"){
            system("whoami");
        }
        // creating a directory
        else if(command.rfind("mkdir ") == 0){
            std::string dir_name = command.substr(command.find_first_of(" \t")+1);
            makeDir(dir_name);

        }
        // returns all the content of a file
        else if(command.rfind("cat ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t")+1);
            catFile(file_name.c_str());
        }

        // function to return the cpu info of the user's pc
        else if(command == "lscpu"){
            cpuInfo(os);
        }
        // returns the coder of the ShellNU program
        else if(command == "credits"){
            credits();
        }
        // function to run and compile c, c++ and python files
        else if(command.rfind("c ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t")+1);
            cFileCompile(file_name.c_str());
        }
        else if(command.rfind("cpp ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t")+1);
            cppFileCompile(file_name.c_str());
        }
        else if(command.rfind("py ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t")+1);
            pythonCompile(file_name.c_str());
        }
        // end of the compiling functions

        // nano command to use nano text editor
        else if(command.rfind("nano ") == 0){
            std::string file_name = command.substr(command.find_first_of(" \t") + 1);
            nanoTextEditor(file_name);
        }

        //ffplay command to play a video file
        else if(command.rfind("ffplay ") == 0){
        	std::string file_name = command.substr(command.find_first_of(" \t") + 1);
            ffplay(file_name);
        }

        // nano command to open up nano editor
        else if(command == "nano"){
            system("nano");
        }
    }

}
