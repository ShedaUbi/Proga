#define _CRT_SECURE_NO_WARNINGS
#include "MatrixList.h"
#include <iostream>

template<typename T>
MatrixList<T>::MatrixList() : _head() {}

template<typename T>
MatrixList<T>::~MatrixList()
{
	while (_head)
		remove();
}

template<typename T>
void MatrixList<T>::add(const T& t, unsigned int n)
{
	ListNode* node = new ListNode(t);

	if (n == 0)
	{
		ListNode* cur_node = _head;

		while (cur_node != NULL && cur_node->_next != _head)
		{
			cur_node = cur_node->_next;
		}

		if (cur_node != NULL)
		{
			cur_node->_next = node;
			node->_next = _head;
			std::cout << "Add new node" << std::endl;
		}
		else
		{
			std::cout << "Init new node" << std::endl;
			node->_next = node;
		}
		
		_head = node;
	}
	else
	{
		int temp_pos = 0;
		ListNode* cur_node = _head;

		while (temp_pos < n - 1 && cur_node->_next)
		{
			cur_node = cur_node->_next;
			temp_pos++;
		}

		node->_next = cur_node->_next;
		cur_node->_next = node;
	}
}

template<typename T>
void MatrixList<T>::remove(unsigned int n)
{
	if (_head)
	{
		if(n == 0)
		{ 
			ListNode* new_head = _head->next;

			delete _head;
			_head = new_head;

		}
		else
		{
			int temp_pos = 0;
			ListNode* cur_node = _head;

			while (temp_pos < n - 1 && cur_node->_next)
			{
				cur_node = cur_node->_next;
				temp_pos++;
			}

			if (!cur_node->_next)
				return;

			cur_node->_next = cur_node->_next->_next;
			delete cur_node->_next;
		}
	}
}

template<typename T>
T MatrixList<T>::find(int size_x, int size_y)
{
	ListNode* iter;
	bool d;

	for (iter = _head, d = false; !(iter == _head && d); iter = iter->_next, d = true)
		if (iter->_val.get_w() == size_x && iter->_val.get_h() == size_y)
			return iter->_val;

	return T();
}

template<typename T>
void MatrixList<T>::print_all()
{
	ListNode* iter;
	bool d;

	for(iter = _head, d = false; !(iter == _head && d); iter = iter->_next, d = true)
		//std::cout << iter->_val.to_string() << std::endl;
		std::cout << iter->print() << std::endl;
}

template<typename T>
T MatrixList<T>::get_head()
{
	return _head;
}

template<typename T>
typename MatrixList<T>::ListIterator MatrixList<T>::begin()
{
	return ListIterator(_head);
}

template<typename T>
typename MatrixList<T>::ListIterator MatrixList<T>::end()
{
	ListNode* nd = _head;
	for (; nd != NULL && nd->_next != _head; nd = nd->_next);

	return ListIterator(nd);
}

template<typename T>
unsigned int MatrixList<T>::get_size()
{
	if (_head == NULL)
		return 0;

	unsigned int size = 1;

	for (ListIterator iter = begin(); iter != end(); ++iter)
		size++;

	return size;
}
