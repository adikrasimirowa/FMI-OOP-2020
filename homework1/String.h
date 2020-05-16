#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

class String 
{
    public:
    char *str;
    
    String ();
    String (const char *newStr);
    String (char);
    String (const String &other);
    void initialize (const char *newStr);

    String operator+ (char);
    String operator+ (String);
    bool operator== (String);
    bool operator< (String);
    char& operator[] (size_t);
    String operator= (char);
    bool operator!= (String);

    size_t length () const;
    void print ();
};