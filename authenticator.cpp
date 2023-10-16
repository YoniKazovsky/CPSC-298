#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    char in1;
    cout<<"Enter the first character of the message code: ";
    cin>> in1;
    char in2;
    cout<<"Enter the second character of the message code: ";
    cin>> in2;
    char in3;
    cout<<"Enter the third character of the message code: ";
    cin>> in3;
    string auth;
    auth += k_cAuthenticatorCodeCharacter1;
    auth += k_cAuthenticatorCodeCharacter2;
    auth += k_cAuthenticatorCodeCharacter3;
    cout<<"Authenticator code: " << auth << endl;
    string msg;
    msg += in1;
    msg += in2;
    msg += in3;
    cout<<"Message code: " << msg << endl;
    if (k_cAuthenticatorCodeCharacter1 == in1 && k_cAuthenticatorCodeCharacter2 == in2 && k_cAuthenticatorCodeCharacter3 == in3){
        cout<<"Message is authentic"<<endl;
    }
    else{
        cout<<"Message is not authentic"<<endl;
    }
    if (auth == msg){
        cout<<"Concurence: Message is authentic"<<endl;
    }
    else{
        cout<<"Concurence: Message is not authentic"<<endl;
    }
    
    int checksum = 0;
    checksum = (int(in1) + int(in2) + int(in3)) % 7;
    const int k_iValidCodeChecksum = 5;
    if (checksum == k_iValidCodeChecksum){
        cout<<"Message code checksum is valid: 5"<<endl;
    }
    else{
        cout<<"Message code checksum is invalid: "<< checksum << " Expected: 5"<<endl;
    }
    cout<< "ASCII values of message code characters: "<<int(in1)<<", "<<int(in2)<<", "<<int(in3)<<endl;
    cout<< "Sum of ASCII values of message code characters: "<<int(in1) + int(in2) + int(in3)<<endl;
    
    if (k_cAuthenticatorCodeCharacter1 != in1){
        cout<< "First characters dont match - Message: "<<in1<<" Authenticator: "<<k_cAuthenticatorCodeCharacter1<<endl;
    }
    if (k_cAuthenticatorCodeCharacter2 != in2){
        cout<< "Second characters dont match - Message: "<<in2<<" Authenticator: "<<k_cAuthenticatorCodeCharacter2<<endl;
    }
    if (k_cAuthenticatorCodeCharacter3 != in3){
        cout<< "Third characters dont match - Message: "<<in3<<" Authenticator: "<<k_cAuthenticatorCodeCharacter3<<endl;
    }
    char str1[3];
    for (int x = 0; x < sizeof(str1); x++) { 
        str1[x] = msg[x]; 
    } 
    char str2[3];
    for (int x = 0; x < sizeof(str2); x++) { 
        str2[x] = auth[x]; 
    } 
    int result = strcmp(str1, str2);
    if(result == 0)
    {
        cout << "Message and Authenticator codes are lexicographically equal" << endl;
    }
    else if (result < 0)
    {
        cout << "Message code ("<< msg << ") is lexicographically less than Authenticator code ("<<auth<<")"<<endl;
    }
    else{
        cout << "Message code ("<< msg << ") is lexicographically greater than Authenticator code ("<<auth<<")"<<endl;
    }
    return 0;
}
