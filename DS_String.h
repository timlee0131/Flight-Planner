#ifndef DS_STRING_H
#define DS_STRING_H
#include <iostream>
class DS_String {
private:
    char* char_array_ptr;
    int str_len;
public:
    DS_String();
    DS_String(const char[]);
    DS_String(const DS_String&);
    ~DS_String();

    friend void Getline(std::istream&, DS_String&);
    friend void Getline(std::istream&, DS_String&, char);

    //+= operator exhibit some reliability issue.
    //since it works fine at least in getline functions,
    //I will come back to fix them at a later time.
    DS_String& operator += (const char);
    DS_String& operator += (const DS_String&);
    DS_String& operator = (const char[]);
    DS_String& operator = (const DS_String&);
    friend bool operator < (const DS_String&, const DS_String&);

    friend bool operator == (DS_String&, DS_String&);
    friend bool operator != (DS_String&, DS_String&);

    friend std::ostream& operator << (std::ostream&, DS_String&);
    friend std::istream& operator >> (std::istream&, DS_String&);

    char& operator [] (int);

    char* c_string();

    char* get_array();
    DS_String& to_lower();
    int len() const;
    DS_String substring(int, int);
};
#endif // DS_STRING_H
