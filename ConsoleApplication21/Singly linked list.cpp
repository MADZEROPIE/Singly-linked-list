//СОЗДАНИЕ КЛАССА ОДНОСВЯЗНОГО СПИСКА

#include "pch.h"
#include <iostream>

template <typename T>
class List
{
public:
	List();
	~List();
	int GetSize() {
		return Size;
	};
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	void pop_back();
	void removeAt(int index);
	void insert(T data, int index);
	T& operator [](const int n);
private:
	template <typename T1>
	class Node
	{
	public:
		Node *pNext;
		T1 data;
		Node(T1 data, Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	private:

	};
	int Size;
	Node<T> *head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	clear();

}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
		head = new Node<T>(data);
	else {
		Node<T> *current=this->head;
		while (current->pNext != nullptr)
			current = current->pNext;
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *current = this->head;
	head = head->pNext;
	delete current;
	Size--;

}

template<typename T>
void List<T>::clear()
{
	while (head!=nullptr)
		pop_front();
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (!index)
		pop_front();
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index-1; i++)
			previous = previous->pNext;
		Node<T> *current = previous->pNext;
		previous->pNext = current->pNext;
		delete current;
		Size--;
	}

}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (!index)
		push_front(data);
	else {
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		previous->pNext= new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
T & List<T>::operator[](const int n)
{
	Node<T> *current = this->head;
	for (int i = 0; i < n; i++)
		current = current->pNext;
	return current->data;
}


int main()
{

	List<int> lst;
	lst.push_front(40);
	lst.push_back(7);
	lst.push_back(348);
	lst.push_back(457);
	lst.pop_front();
	lst.insert(48, 2);
	lst.removeAt(lst.GetSize() - 2);
	//lst.clear();
	int x = lst.GetSize();
	std::cout << x << std::endl;
	for(int i=0;i<x;i++)
		std::cout << lst[i] << std::endl;
	//_getwch();
	return 0;
}