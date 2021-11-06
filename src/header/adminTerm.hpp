#include<iostream>      // for some basic stuff
#include<unistd.h>      // for system stuff
#include<algorithm>     // for algorithmic stuff
#include<fstream>       // for file stuff
#include<string>        // for functions like substr()
#include "encrypt.h"


// Admin function starts from here (Giving more privilege)
void adminTerm(char username[50]){
    std::string admin_command;

    // unless the command is xt, the terminal will run on admin mode
    while(admin_command != "xt"){
        std::cout << "\n\033[1;32m"<<username<<"\033[0m@\033[1;36madmin\033[0m:~";

        std::getline(std::cin, admin_command);

        // go back of the directory
        if(admin_command == ".." || admin_command == "cd .."){
            chdir("..");
        }
        // list all the files
        else if(admin_command == "ls"){
            system("ls");
        }
        // shutdown the PC (only for admin)
        else if(admin_command == "shutdown"){
            system("shutdown -Ph now");
        }
        // returns the admin name
        else if(admin_command == "whoami"){
            std::cout<<username;
        }
        else if(admin_command == "clear"){
            system("clear");
        }
        // to create a file
        else if(admin_command.rfind("touch ") == 0){
            std::string file_name=admin_command.substr(admin_command.find_first_of(" \t")+1);
            std::ofstream createFile(file_name);
            createFile.close();
            std::cout<<file_name<<" created successfully!";
        }
        // to change directory
        else if(admin_command.rfind("cd ") == 0){
            std::string dir=admin_command.substr(admin_command.find_first_of(" \t")+1);
            char directory[256];
            strcpy(directory, dir.c_str());
            chdir(directory);
        }
        // to remove a file or a folder
        else if(admin_command.rfind("rm ") == 0){
            std::string filename = admin_command.substr(admin_command.find_first_of(" \t") + 1);
            char buf[60];
            strcpy(buf,filename.c_str());
            if(std::remove(buf)){
                std::cout << filename << " wasn't deleted!";
            }
            else{   
                std::cout<<filename<<" was deleted successfully!";
            }
        }
        // creating a directory
        else if(admin_command.rfind("mkdir ") == 0){
            std::string dir_name = admin_command.substr(admin_command.find_first_of(" \t")+1);
            std::string dir_command = "mkdir ";
            char* directory_name = const_cast<char*>(dir_name.c_str());
            char* mkdir_command = const_cast<char*>(dir_command.c_str());
            strcat(mkdir_command, directory_name);
            system(mkdir_command);
            std::cout<<directory_name<<" was successfully created!";

        }
        // returns the working directory
        else if(admin_command == "pwd"){
            system("pwd");
        }
        // takes input string and returns a base64 encoded string 
        else if(admin_command == "b64"){
            std::string text;
            std::cout<<"Enter a string [with no spaces]:\n";
            std::cin>>text;
            std::cout<<base64_encode(text);
        }
        // a simple password generator
        else if(admin_command == "pw gen"){
            int num;
            std::cout<<"Enter the length for your password:\n";
            std::cin>>num;
            pw_generator(num);
        }
        else{
            std::cout<<"command not added yet!";
        }
    }
}
