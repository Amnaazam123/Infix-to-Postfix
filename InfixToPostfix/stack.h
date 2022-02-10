//BSEF19M009 - Amna Azam-Assignment1
#pragma once
#include<string>
template<class T>
class stack
{
private:
    T* myStack;
    int peak;
    int size;
public:
    stack(int);
    ~stack();
    void push(T);
    T pop();
    T top();
    int resize(int);
    bool isEmpty();
};



