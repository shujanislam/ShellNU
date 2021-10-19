
#include<iostream>          // for some basic stuff
#include<unistd.h>          // for system stuff
#include<map>               // for map 
#include<stdlib.h>
#include<string>            // for some basic functions like substr()
#include "header/file.h"    // header file that contains login/register functions

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
    {"whoami", "returns the user of the machine"}
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
            std::cout << "\n\033[1;33muser\033[0m@\033[1;31mlinux\033[0m:~";
        }
        else if(os == "windows"){
            std::cout << "\n\033[1;33muser\033[0m@\033[1;31mwindows\033[0m:~";
        }
        else{
            std::cout << "\n\033[1;33muser\033[0m@\033[1;31muser\033[0m:~";
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
            std::cout<<"Version: 0.0.1\nCopyright@2021";
        }
        // to retrieve all the help commands
        else if(command == "help"){
            for(auto itr = Help.begin(); itr != Help.end(); itr++){
                std::cout<<(*itr).first<<" : "<<(*itr).second<<"\n\n";
            }
        }
        // to clear the screen
        else if(command == "clear" || command == "cls"){
            if(os == "linux"){
                system("clear");
            }
            else if(os == "windows"){
                system("cls");
            }
            else{
                system("clear");
            }
        }
        // to echo a string in the console
        else if(command.rfind("echo ") == 0){
            std::string echo_str = command.substr(command.find_first_of(" \t")+1);
            std::cout<<echo_str;
        }
        // to create a file
        else if(command.rfind("touch ") == 0){
            std::string file_name=command.substr(command.find_first_of(" \t")+1);
            std::ofstream createFile(file_name);
            createFile.close();
            std::cout<<file_name<<" created successfully!";
        }
        // to come back of the directory
        else if(command == ".." || command == "cd .."){
            chdir("..");
        }
        // to change directory
        else if(command.rfind("cd ") == 0){
            std::string dir=command.substr(command.find_first_of(" \t")+1);
            char directory[256];
            strcpy(directory, dir.c_str());
            chdir(directory);
        }
        // to list all the files in the directory
        else if(command == "ls" || command == "dir"){
            if(os == "linux"){
                system("ls");
            }
            else if(os == "windows"){
                system("dir");
            }
            else{
                system("ls");
            }
        }
        // to delete a file or a folder
        else if(command.rfind("rm ") == 0){
            std::string filename = command.substr(command.find_first_of(" \t") + 1);
            char buf[60];
            strcpy(buf,filename.c_str());
            if(std::remove(buf)){
                std::cout << filename << " wasn't deleted!";
            }
            else{   
                std::cout<<filename<<" was deleted successfully!";
            }
        }
        // returns the current working directory
        else if(command == "pwd"){
            if(os == "linux"){
                system("pwd");
            }
            else if(os == "windows"){
                system("cd");
            }
            else{
                system("pwd");
            }
        }
        // to rename a file
        else if(command.rfind("rename ") == 0){
            std::string filename = command.substr(command.find_first_of(" \t")+1);
            char from[50];
            strcpy(from, filename.c_str());
            char to[50];
            std::string newFile;
            std::cout<<"Enter newfile name: ";
            std::getline(std::cin, newFile);
            strcpy(to, newFile.c_str());

            if(std::rename(from, to)){
                std::cout<<"File renaming was unsuccessful!";
            }
            else{
                std::cout<<"File renamed successfully!";
            }
        }
        // returns the user of the machine
        else if(command == "whoami"){
            system("whoami");
        }
    }

}
