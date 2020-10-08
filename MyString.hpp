#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
    char * str;
    int capacity;
public:
    MyString();
    MyString(int _capacity);
    MyString(const char *_str);
    MyString(const MyString &obj);
    MyString(MyString &&obj)noexcept;
    ~MyString();
    
    void PrintInfo()const;
    void Input();
    
    int GetSize()const;
    int GetCapacity()const;
};
