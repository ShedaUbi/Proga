#include "MatrixList.h"
#include <iostream>

MatrixList::MatrixList() : _head() {}

MatrixList::~MatrixList()
{
	while (_head)
		remove();
}

void MatrixList::add(const Matrix& t, unsigned int n)
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

void MatrixList::remove(unsigned int n)
{
	if (_head)
	{
		if(n == 0)
		{ 
			ListNode* new_head = _head->_next;

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

Matrix MatrixList::find(int size_x, int size_y)
{
	ListNode* iter;
	bool d;

	for (iter = _head, d = false; !(iter == _head && d); iter = iter->_next, d = true)
		if (iter->_val.get_w() == size_x && iter->_val.get_h() == size_y)
			return iter->_val;

	return Matrix();
}

void MatrixList::print_all()
{
	ListNode* iter;
	bool d;

	for(iter = _head, d = false; !(iter == _head && d); iter = iter->_next, d = true)
		std::cout << iter->print() << std::endl;
}

MatrixList::ListNode* MatrixList::get_head()
{
	return _head;
}

typename MatrixList::ListIterator MatrixList::begin()
{
	return ListIterator(_head);
}

typename MatrixList::ListIterator MatrixList::end()
{
	ListNode* nd = _head;
	for (; nd != NULL && nd->_next != _head; nd = nd->_next);

	return ListIterator(nd);
}

unsigned int MatrixList::get_size()
{
	if (_head == NULL)
		return 0;

	unsigned int size = 1;

	for (ListIterator iter = begin(); iter != end(); ++iter)
		size++;

	return size;
}


MatrixList::ListNode::ListNode() : _next() {};
MatrixList::ListNode::ListNode(const Matrix& t) : _val(t), _next() {};

char* MatrixList::ListNode::print()
{
	return this->_val.to_string();
}


MatrixList::ListIterator::ListIterator(ListNode* node) : _node(node) {};

bool MatrixList::ListIterator::operator==(const ListIterator& other) const
{
	return (this == &other) ? true : (_node == other._node);
}

bool MatrixList::ListIterator::operator!=(const ListIterator& other) const
{
	return !operator==(other);
}

Matrix MatrixList::ListIterator::operator*()
{
	return _node ? _node->_val : Matrix();
}

void MatrixList::ListIterator::operator++()
{
	if (_node)
		_node = _node->_next;
}
