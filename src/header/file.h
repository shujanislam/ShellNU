
#include<stdio.h>           // basic input/output
#include<stdlib.h>      
#include<string.h>          // for stuff like substr()

// a function to write in a file
void writeFile(const char* text, const char* file){

    FILE* f1 = fopen(file, "w");
    fprintf(f1, "%s", text);
    fclose(f1);

    printf("Written on the File successfully!");
}

// a function that returns all the content of a file
void catFile(const char* file_name){
    char buffer[100];
    FILE *fp = fopen(file_name, "r");                 // do not use "rb"
    if(fp){
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s\n", buffer);
        }
    }
    else{
        printf("File doesn't exists!");
    }
    fclose(fp);
}

// a function that compiles and runs a c program
void cFileCompile(const char* file_name){
    char command[50] = "gcc ";
    char ext[50] = " -o main";
    strcat(command, file_name);
    strcat(command, ext);
    char prefix[10] = "./";
    strcat(prefix, "main"); // eg - ./main
    // run the compiling command
    system(command);
    // wait for a second
    usleep(1000000);
    // run the ouput file
    system(prefix);
}

// a function that compiles and runs a c++ program
void cppFileCompile(const char* file_name){
    char command[50] = "g++ ";
    char ext[50] = " -o main";
    strcat(command, file_name);
    strcat(command, ext);
    char prefix[10] = "./";
    strcat(prefix, "main"); // eg - ./main
    // run the compiling command
    system(command);
    // wait for a second
    usleep(1000000);
    // run the ouput file
    system(prefix);
}

// a function that compiles and runs a python program
void pythonCompile(const char* file_name){
    char command[50] = "python3 ";
    strcat(command, file_name);
    // run the output file
    system(command);
}

