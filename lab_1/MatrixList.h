#pragma once
#include "Matrix.h"

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
		Matrix operator*();
		void operator++();

	private:
		ListNode* _node;
	};


	MatrixList();
	~MatrixList();

	void add(const Matrix &t, unsigned int n = 0);
	void remove(unsigned int n = 0);

	Matrix find(int size_x, int size_y);
	void print_all();

	ListNode* get_head();

	ListIterator begin();
	ListIterator end();

	unsigned int get_size();

private:
	class ListNode 
	{
	public:
		ListNode();
		ListNode(const Matrix& t);

		char* print();

		Matrix _val;
		ListNode* _next;
	};

	ListNode* _head;
};
