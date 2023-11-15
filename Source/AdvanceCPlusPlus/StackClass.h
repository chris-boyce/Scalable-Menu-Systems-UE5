// Chris Boyce 1908671 - Advanced C++ Module 

#pragma once

#include "CoreMinimal.h"

/**
 * @brief (IDK WHY THIS MUST BE THE HEADER IF NOT ITS VERY BROKEN) Something to do with linker Errors and Templates
 * @tparam T Is the Type the stack Class Type
 */
template <typename T>
class ADVANCECPLUSPLUS_API StackClass
{
public:
	StackClass(){};
	~StackClass(){};
	void Push(const T& Element); 
	T Pop(); 
	bool IsEmpty() const;
	T Peek() const; 
	

private:
	TArray<T> Stack;
};

//Function Definitions 
template <typename T>
void StackClass<T>::Push(const T& Element)
{
	Stack.Add(Element);
}

template <typename T>
T StackClass<T>::Pop()
{
	if (!IsEmpty())
	{
		T PoppedElement = Stack.Last();
		Stack.Pop();
		return PoppedElement;
	}
	return T();
}

template <typename T>
bool StackClass<T>::IsEmpty() const
{
	return Stack.Num() == 0;
}

template <typename T>
T StackClass<T>::Peek() const
{
	if (!IsEmpty())
	{
		T TopElement = Stack.Last();
		return TopElement;
	}
	
	return nullptr;
}





