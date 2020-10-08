#include "MyString.hpp"

MyString::MyString()
{
    capacity = 80;
    str = new char[capacity]{};
}

MyString::MyString(int _capacity)
{
    capacity = _capacity > 0 ? _capacity : 80;
    str = new char[capacity]{};
}

MyString::MyString(const char *_str)
{
    str = strdup(_str);
    capacity = strlen(str) + 1;
}

MyString::MyString(const MyString &obj)
{
    capacity = obj.capacity;
    
    str = new char[capacity];
    strcpy(str, obj.str);
}

MyString::MyString(MyString &&obj)noexcept
{
    str = obj.str;
    capacity = obj.capacity;
    
    obj.capacity = 0;
    obj.str = nullptr;
}

void MyString::PrintInfo()const
{
    cout<<str<<endl;
}

int MyString::GetSize()const
{
    return strlen(str);
}

int MyString::GetCapacity()const
{
    return capacity;
}

void MyString::Input()
{
    char buf[1000];
    cout<<"Enter string-> "<<endl;
    cin.getline(buf, 1000);
    
    int length = strlen(buf);
    
    if(capacity>=length)
    {
        strcpy(str, buf);
        return;
    }
    else
    {
        delete [] str;
        capacity = length+1;
        str = new char[capacity];
        strcpy(str, buf);
    }
    
}

MyString::~MyString()
{
    if(capacity)
        delete [] str;
}
