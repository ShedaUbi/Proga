#pragma once
#include "TriMatrix.h"
#include "IdentityMatrix.h"

template <typename T>
class MatrixList 
{
private:
	class ListNode;

public:
	class ListIterator 
	{
	public:
		ListIterator(ListNode* node);

		bool operator==(const ListIterator& other) const;
		bool operator!=(const ListIterator& other) const;
		T operator*();
		void operator++();

	private:
		ListNode* _node;
	};


	MatrixList();
	~MatrixList();

	void add(const T &t, unsigned int n = 0);
	void remove(unsigned int n = 0);

	T find(int size_x, int size_y);
	void print_all();

	T get_head();

	ListIterator begin();
	ListIterator end();

	unsigned int get_size();

private:
	class ListNode 
	{
	public:
		ListNode();
		ListNode(const T& t);

		char* print()
		{
			char* buffer = new char[64];
			sprintf(buffer, "%s", this->_val);

			return buffer;
		}

		T _val;
		ListNode* _next;
	};

	ListNode* _head;
};


template<typename T>
MatrixList<T>::ListNode::ListNode() : _next() {};

template<typename T>
MatrixList<T>::ListNode::ListNode(const T& t) : _val(t), _next() {};

template<>
char* MatrixList<Matrix>::ListNode::print()
{
	return this->_val.to_string();
};


template<typename T>
MatrixList<T>::ListIterator::ListIterator(ListNode* node) : _node(node) {};

template<typename T>
bool MatrixList<T>::ListIterator::operator==(const ListIterator& other) const
{
	return (this == &other) ? true : (_node == other._node);
}

template<typename T>
bool MatrixList<T>::ListIterator::operator!=(const ListIterator& other) const
{
	return !operator==(other);
}

template<typename T>
T MatrixList<T>::ListIterator::operator*()
{
	return _node ? _node->_val : T();
}

template<typename T>
void MatrixList<T>::ListIterator::operator++()
{
	if (_node)
		_node = _node->_next;
}
