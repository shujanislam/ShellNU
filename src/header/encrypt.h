#include <string>
#include <sstream>
#include <iostream>
#include<ctime>
#include <vector>

using namespace std;

// base64 encode function
static std::string base64_encode(const std::string &in) {

    std::string out;

    int val=0, valb=-6;
    for (int jj = 0; jj < in.size(); jj++) {
    	char c = in[jj];
        val = (val<<8) + c;
        valb += 8;
        while (valb>=0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if (valb>-6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    while (out.size()%4) out.push_back('=');
    return out;
}

// password generator function
static const char alphnum[]="0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; 
int strLen=sizeof(alphnum)-1; 
char GenRand()
{ 
    return alphnum[rand()%strLen]; 
}

void pw_generator(int n){
    int c=0,s=0;
    srand(time(0));
    cout<<"Your Password is:";
    N:
    char C;
    string D;
    for(int z=0; z < n; z++) 
    { 
        C=GenRand();
        D+=C;
        if(isdigit(C))
        {
            c++;
        }
        if(C=='!' || C=='@' || C=='$' || C=='%' ||  C=='^' || C=='&'|| C=='*'|| C=='#')
        {
            s++;
        }
    }
    if(n>2 && (s==0 || c==0))
    {
        goto N; 
    }
    cout<<D;  
}