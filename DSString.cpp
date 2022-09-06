//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {

    data = nullptr;
}

DSString::DSString(const char * d) {
    if(d == nullptr){
        data = nullptr;
    }else {
        //implement strcopy to copy in c-string into variable
        data = new char[strlen(d) + 1];
        strcpy(data, d);
        data[strlen(d)] = '\0';
    }
}

DSString::DSString(const DSString & d) {
    if(d.data == nullptr){//error here
       // delete[]data;
        data = nullptr;
    }else {
        //implement strcpy to copy a string into DSString

        data = new char[strlen(d.data) + 1];
        strcpy(data, d.data);
        data[strlen(d.data)] = '\0';

    }
}

DSString::~DSString() {

        delete[] data;

}


DSString& DSString::operator= (const DSString &d) {
    //check to make sure data is not the same
    if(this != &d ){
        //assignment operator allows me to update the string
        delete[]data;
        data = new char[strlen(d.data) + 1];
        data[strlen(d.data)] = '\0';
        strcpy(data,d.data);
    }

    return *this;


}

DSString& DSString::operator= (const char*d) {
    //assignment operator allows me to update the character string
    delete[] data;
    data = new char[strlen(d) + 1];
    strcpy(data,d);
    data[strlen(d)] = '\0';
    return *this;


}

DSString DSString:: operator+ (const DSString& d){
    DSString myString;
    char* theBuffer = new char[strlen(this->data) + strlen(d.data) +1];
    strcpy(theBuffer, this->data);
    strcat(theBuffer,d.data);
    myString.data = theBuffer;
    return myString;

}

int DSString::getLength() {
    return strlen(data);

}

DSString DSString::substring(int start, int numChars){
    DSString myString;
    char* temp = new char[numChars + 1];
    //copying substring into temp
    //add start with data so that it is returning specified number of chars
    strncpy(temp, data + start, numChars);
    temp[numChars] = '\0';
    myString = temp;
    return myString;
}

std::ostream& operator<< (std::ostream& out, const DSString& d){
    out<<d.data;
    return out;
}

bool DSString::operator== (const char*ptr) const {
    //compares data being passed in with the private member to check if they are the same
    return (strcmp(data,ptr) == 0);

}

bool DSString::operator== (const DSString& d) const{
    //compares d being passed in with the private member to check if they are the same
    return (strcmp(this->data,d.data) == 0);

}

bool DSString::operator> (const char* ptr){

    return (strcmp(data,ptr) > 0);

}

bool DSString::operator> (const DSString&d) const{

    return (strcmp(this->data,d.data) > 0);

}

//less than operator for DSString
bool DSString::operator< (const DSString&d) const{

    return (strcmp(this->data,d.data) < 0);

}

//less than operator for char*
bool DSString::operator< (const char* ptr){

    return (strcmp(data,ptr) < 0);

}


char&  DSString::operator[] (const int num){
    //return single char at certain index
    return data[num];
}

char* DSString:: c_str(){

    return data;

}

DSString DSString::toLower(){
    int i = 0;
    for(i; i < strlen(data); i ++) {
        data[i] = tolower(data[i]);
    }
    return *this;
}

int DSString ::toInt() {
   int x = atoi(data);
   return x;
}






