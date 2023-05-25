#include<iostream>      // for some basic stuff
#include<unistd.h>      // for system stuff
#include<algorithm>     // for algorithmic stuff
#include<fstream>       // for file stuff
#include<string>        // for functions like substr()
#include<map>           // for map 

// Map that contains all the help commands
std::map<std::string, std::string> Help = {
    {"shellnu", "to display the introduction of ShellNU"},
    {"nw", "to start a new ShellNU window"},
    {"nt", "to start a new ShellNU tab"},
    {"v", "to check the version of the terminal"},
    {"xt", "to exit the terminal"},
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
    {"vim <filename>", "to edit a file using vim text editor"},
    {"ffplay <filename>", "to play a video file using ffplay"}
};

// function to show the version of the shell
void shellVersion(){
	std::cout<<"ShellNU version: 0.0.3\n";
}

// function to clear the screen
void clearScreen(const char os[10]){
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

//function to list files in the directory
void listFiles(const char os[10]){
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

// function to show the current working directory
void pwd(const char os[10]){
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

// function to return the cpu info
void cpuInfo(const char os[10]){
	if(os == "linux"){
        system("lscpu");
    }
    else if(os == "windows"){
        system("systeminfo");
    }
}

// function to return the coder of ShellNU program
void credits(){
	std::cout<<"--------------{+} Coded By Shujan Islam {+}--------------\n";
    std::cout<<"--------------{+} https://shujanislam.github.io {+}--------------\n";
    std::cout<<"--------{+}  https://github.com/shujanislam/ShellNU {+}--------\n";
}

// function to play a video using ffplay
void ffplay(std::string file_name){
	char ffplay_command[50] = "gnome-terminal -- ffplay ";
    strcat(ffplay_command, file_name.c_str());
    system(ffplay_command);
}

// function to open nano text editor
void nanoTextEditor(std::string file_name){
	char nano_command[50] = "gnome-terminal -- nano ";
    strcat(nano_command, file_name.c_str());
    system(nano_command);
}

// function to open vim text editor
void vimTextEditor(std::string file_name){
    char vim_command[50] = "gnome-terminal -- vim ";
    strcat(vim_command, file_name.c_str());
    system(vim_command);
}

// function to make a directory
void makeDir(std::string dir_name){
	std::string dir_command = "mkdir ";
    char* directory_name = const_cast<char*>(dir_name.c_str());
    char* mkdir_command = const_cast<char*>(dir_command.c_str());
    strcat(mkdir_command, directory_name);
    system(mkdir_command);
    std::cout<<directory_name<<" was successfully created!";
}

// function to create a file
void createFile(std::string file_name){
	std::ofstream createFile(file_name);
    createFile.close();
    std::cout<<file_name<<" created successfully!";
}

// function to delete a file or folder
void delFileFolder(std::string file_name){
	char buf[60];
    strcpy(buf,file_name.c_str());
    if(std::remove(buf)){
        std::cout << file_name << " wasn't deleted!";
    }
    else{   
        std::cout<<file_name<<" was deleted successfully!";
    }
}

// function to change directory
void changeDir(std::string dir){
	char directory[256];
    strcpy(directory, dir.c_str());
    chdir(directory);
}

// function to rename a file
void renameFile(std::string file_name){
	char from[50];
    strcpy(from, file_name.c_str());
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

// function to echo write a file
void echoFile(std::string echo_str){
	std::string text = echo_str.substr(0, echo_str.find(' '));
    std::string file = echo_str.substr(echo_str.find_first_of(" \t")+2);
    writeFile(text.c_str(), file.c_str());
}

// function to display the introduction of ShellNU
void shellNUIntro(){
    shellVersion();
    std::cout<<"ShellNU is a free and open source terminal emulator\n";
    std::cout<<"type help (for help)\n";
    std::cout<<"type xt (to exit)\n";
}

// function to open up a new ShellNU window
void startNewWindow(){
    char startNewWindow[50] = "gnome-terminal -- ./ShellNU ";
    system(startNewWindow);
}

// function to open up a new ShellNU tab
void startNewTab(){
    char startNewTab[50] = "gnome-terminal --tab -- ./ShellNU ";
    system(startNewTab);
}