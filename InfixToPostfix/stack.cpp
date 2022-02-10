//BSEF19M009 - Amna Azam-Assignment1
#include "stack.h"
#include<iostream>
#include<string>
using namespace std;

// Constructor to initialize the stack
template<class T>
stack<T>::stack(int s)
{
	myStack = new T[s];
	size = s;
	peak = -1;
}

//destructor to delete dynamic memory
template<class T>
stack<T>::~stack()
{
	delete[] myStack;
}

//resize your stack
template<class T>
int stack<T>::resize(int s)
{
	size = s;
	T* temp;
	temp = new T[peak + 1];
	for (int j = 0; j < peak + 1; j++)              //copying the values
		temp[j] = myStack[j];

	if (peak == size - 1)                //if stack is full?
		size = size * 2;
	else if (peak <= size / 4)           //if 3/4th part of stack is empty?
		size = size / 2;

	delete[] myStack;

	myStack = new T[size];                //new array

	for (int i = 0; i < peak + 1; i++)           //putting values in new stack
		myStack[i] = temp[i];

	delete[] temp;
	return size;
}

//pushing the element in stack
template<class T>
void stack<T>::push(T x)
{
	if (size - 1 == peak)                   //full stack?
		size = resize(size);
	myStack[++peak] = x;                            //push the element and increase top one element up                  
}

//pop value from stack
template<class T>
T stack<T>::pop()
{
	if (peak <= size / 4 && peak > 2 && size / 4 > 2)
		size = resize(size);
	return myStack[peak--];                      //pop the element and decrease top down

}

//return top value of the stack
template<class T>
T stack<T>::top()
{
	if (!isEmpty())
		return myStack[peak];
}


//is stack empty?
template<class T>
bool stack<T>::isEmpty() {
	return peak == -1;               //stack is empty
}
