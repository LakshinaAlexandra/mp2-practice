#pragma once
#include "unit.h"

//����������� ������ � �������
template<class type>
class list
{
private:
	unit<type>* head;									//��������� �� ������
	//void Clean();										//������� ������
public:
	void Clean();
	list();												//����������� �� ���������
	list(const list<type>& a);                  	    //����������� �����������
	~list();											//����������
	list<type>& operator=(const list<type> &a);		    //���������� ��������� ������������
	void Insert(type elem);					        	//������� � ������������� ������
	unit<type>* GetHead() const { return head; }        //�������� ������ ������

	bool operator==(const list<type>& sp) const;								
	bool operator!=(const list<type>& sp) const { return !(*this == sp); }
};


//������� ������
template <class type>
void list<type>::Clean()
{
	unit<type>* actual = head->next;   
	while (actual != head)                   
	{
		unit<type>* temp = actual->next;        
		delete actual;                           
		actual = temp;                                
	}
	head->next = head;                          
}

//����������� �� ���������
template <class type>
list<type>::list()
{
	head = new unit<type>;
	head->next = head;
}


//����������� �����������
template <class type>
list<type>::list(const list<type>& a)
{
	head =  new unit<type>;             //!!!!!!!!!!
	unit<type>* A = a.head;
	unit<type>* B = head;
	if ( A->next == a.head)
	{
		head->next = head;
		return;
	}
	while (A->next != a.head)
	{
		A = A->next;
		B->next = new unit<type>(A->data);
		B = B->next;
	} 
	B->next = head;
}


//����������
template <class type>
list<type>::~list()
{
	Clean();
	delete head;
}

//�������� ������������
template <class type>
list<type>& list<type>::operator=(const list<type>& a)
{
	Clean();
	unit<type>* A = a.head;
	unit<type>* B = head;
	while (A->next != a.head)
	{
		A = A->next;
		B->next = new unit<type>(A->data);
		B = B->next;
	}
	B->next = head;
	return *this;
}

//������� � ������������� ������
template <class type>
void list<type>::Insert(type elem)
{
	unit<type>* actual = head;
	unit<type>* el = new unit<type>(elem);    

	while ((actual->next != head) && (*(actual->next) < *el))
		actual = actual->next;
	unit<type>* actual_2 = actual->next;
	actual->next = el;
	actual->next->next = actual_2;
}

// �������� �����
template<class type>
bool list<type>::operator==(const list<type>& sp) const
{
	bool res = true;
	if (this != &sp)
	{
		unit<type>* a = head->next;
		unit<type>* b = sp.head->next;
		
		while (a->data == b->data && a != head && b != sp.head)
		{
			a = a->next;
			b = b->next;	
		}
		if (a != head || b != sp.head)
			res = false;
	}
	return res;
}