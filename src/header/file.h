
#include<stdio.h>           // basic input/output
#include<stdlib.h>      
#include<string.h>          // for stuff like substr()
#include "adminTerm.hpp"    // for admin terminal stuff

// class which stores admin credentials
class Admin {
    public:
        char username[50];
        char password[20];
};

// registering an admin
void registerUser(char username[50], char password[20]){
    FILE* file = fopen("data.txt", "w");
    fprintf(file, "%s %s", username, password);
    fclose(file);
}

// logging in the admin
void loginUser(char username[50], char password[20]){;
    FILE* file = fopen("data.txt", "r");
    char username_file[50], password_file[20];
    
    if(file == NULL){
        printf("\nUser not registered yet! Please try registering!!\n");
    }
    else{
        fscanf(file, "%s %s", username_file, password_file);

        if(strcmp(username, username_file) == 0 && strcmp(password, password_file) == 0){
            adminTerm(username);
        }
        else{
            printf("Login Failed!!");
        }
    }
}

