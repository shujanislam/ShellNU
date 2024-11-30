#include<iostream>          // for some basic stuff
#include<unistd.h>          // for system stuff
#include<map>               // for map 
#include<stdlib.h>
#include<fstream>           // for reading file
#include<string>            // for some basic functions like substr()
#include<sstream>           // to read file contents

// Global variables
std::string var, eq; // get the user of the terminal from shellnu.config file
std::ifstream configFile;
std::string line; // retrive the lines of the file

std::string username(){
    std::string user;
    configFile.open("shellnu.config");
    if(!configFile){
        user = "user";
    }
    else{
        while(getline(configFile, line)){
            std::stringstream ss(line);
            ss >> var;
            if(var == "user"){
                ss >> eq >> user;
            }
        }
        configFile.close();

    }

    return user;
}

void profile(){ // Function to check the profile of the user
    std::string profile;
    configFile.open("shellnu.config");
    if(!configFile){

    }
    else{
        while(getline(configFile, line)){
            std::stringstream ss(line);

            ss >> var;

            if(var == "profile"){
                ss >> eq >> profile;

                if(profile == "admin"){
                    // Add admin properties
                }
                else{}
            }
        }
        configFile.close();
    }
}

void commandLog(std::string command) {
    std::string log;
    
    // Check if the file is opened or open it if not already opened
    if (!configFile.is_open()) {
        configFile.open("shellnu.config");  // Open file only once
        if (!configFile) {
        }
    } else {
        // Reset the file pointer to the start of the file
        configFile.clear();  // Clear any EOF flag
        configFile.seekg(0);  // Rewind to the start of the file
    }

    // Read the file contents and check for command_log
    while (getline(configFile, line)) {
        std::stringstream ss(line);
        ss >> var;

        if (var == "command_log") {
            ss >> eq >> log;
            if (log == "true") {
                std::ofstream outFile("log.txt", std::ios::app);  // Append to file instead of overwriting
                outFile << command << std::endl;
            }
        }
    }
}