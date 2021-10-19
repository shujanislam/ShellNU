#include<iostream>      // for some basic stuff
#include<unistd.h>      // for system stuff
#include<algorithm>     // for algorithmic stuff
#include<fstream>       // for file stuff
#include<string>        // for functions like substr()


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
        // returns the working directory
        else if(admin_command == "pwd"){
            system("pwd");
        }
        else{
            std::cout<<admin_command;
        }
    }
}
