#include <cstring>
#include <iostream>
#include "DS_String.h"
using namespace std;

//constructors

DS_String::DS_String() {
    char_array_ptr = new char [0];
    str_len = 0;
    //initializing private data members
}

DS_String::DS_String(const char some_char[]) {
    str_len = 0;
    while(some_char[str_len] != '\0')
        str_len++;
    char_array_ptr = new char[str_len];
    for(int i = 0; i < str_len; i++) {
        char_array_ptr[i] = some_char[i];
    }
}

DS_String::DS_String(const DS_String& some_string) {
    str_len = some_string.len();
    char_array_ptr = new char [str_len];
    for(int i = 0; i < str_len; i++) {
        char_array_ptr[i] = some_string.char_array_ptr[i];
    }
    //cout << "S4" << "\n";
}

DS_String::~DS_String() {
    delete[] char_array_ptr;
}

//getline override

void Getline(std::istream& i, DS_String& some_string) {
    char some_char;
    i.get(some_char);
    while(some_char != '\n') {
        some_string += some_char;
        i.get(some_char);
    }
}

void Getline(std::istream& i, DS_String& some_string, char marker) {
    char some_char;
    i.get(some_char);
    some_string = "";
    while(some_char != '\n' && some_char != marker) {
        some_string += some_char;
        i.get(some_char);
    }
}


//operator overloading

DS_String& DS_String::operator+=(const char some_char) {
    char* temp = new char[str_len + 1];
    for(int i = 0; i < str_len; i++) {
        temp[i] = char_array_ptr[i];
    } temp[str_len++] = some_char;

    delete [] char_array_ptr;
    char_array_ptr = temp;

    return *this;
}

DS_String& DS_String::operator+=(const DS_String& some_string) {
    int tmplen = str_len;
    str_len += some_string.len();
    char* temp = new char[str_len];
    for(int i = 0; i < tmplen; i++) {
        temp[i] = char_array_ptr[i];
    }
    for(int i = 0; i < some_string.len(); i++) {
        temp[i + tmplen] = some_string.char_array_ptr[i];
    }
    delete [] char_array_ptr;
    char_array_ptr = temp;

    return *this;
}

DS_String& DS_String::operator=(const char some_char[]) {
    str_len = strlen(some_char);
    delete [] char_array_ptr;
    char_array_ptr = new char[str_len];
    for(int i = 0; i < str_len; i++) {
        char_array_ptr[i] = some_char[i];
    }

    return *this;
}


DS_String& DS_String::operator=(const DS_String& some_string) {
    delete[] char_array_ptr;
    str_len = some_string.len();
    char_array_ptr = new char[str_len];
    for(int i = 0; i < str_len; i++) {
        char_array_ptr[i] = some_string.char_array_ptr[i];
    }

    return *this;
}

bool operator==(DS_String& some_string, DS_String& some_string2) {
    int len1 = some_string.len();
    int len2 = some_string2.len();
    if(len1 != len2)
        return false;
    else {
        int i = 0;
        while(i < len1) {
            if(some_string.char_array_ptr[i] != some_string2.char_array_ptr[i])
                return false;
            i++;
        }//end while
    }

    return true;
}

bool operator<(const DS_String& some_string, const DS_String& some_string2) {
    int len1 = some_string.len();
    int len2 = some_string2.len();
    if(len1 < len2) {
        for(int i = 0; i < len1; i++) {
            if(some_string.char_array_ptr[i] < some_string2.char_array_ptr[i])
                return true;
            else if(some_string.char_array_ptr[i] > some_string2.char_array_ptr[i])
                return false;
        }//end for
    } else {
        for(int i = 0; i < len2; i++) {
            if(some_string.char_array_ptr[i] < some_string2.char_array_ptr[i])
                return true;
            else if(some_string.char_array_ptr[i] > some_string2.char_array_ptr[i])
                return false;
        }
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& o, DS_String& some_string) {
    for(int i = 0; i < some_string.len(); i++) {
        o << some_string.char_array_ptr[i];
    }

    return o;
}

std::istream& operator>>(std::istream& i, DS_String& some_string) {
    char* temp = new char[1000];
    i >> temp;
    some_string = DS_String(temp);
    delete [] temp;

    return i;
}

char& DS_String::operator[](int some_int) {
    return char_array_ptr[some_int];
}

//other member functions.

char* DS_String::c_string()
{
    char* arr = new char[str_len + 1];
    for (int i = 0; i < str_len; i++)
    {
        arr[i] = char_array_ptr[i];
    }
    arr[str_len] = '\0';

    return arr;
}

DS_String& DS_String::to_lower() {
    for(int i = 0; i < str_len; i++) {
        char_array_ptr[i] = tolower(char_array_ptr[i]);
    }

    return *this;
}

int DS_String::len() const {
    return str_len;
}

char* DS_String::get_array() {
    return char_array_ptr;
}
