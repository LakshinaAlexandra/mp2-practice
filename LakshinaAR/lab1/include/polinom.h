#pragma once

#include "monom.h"
#include "list.h"
#include <iostream>
#include <string>


using namespace std;


class polynom
{
private:
	list<monom> list_pol;		                                                                                     //������ - �������
public:
	polynom(const string pol = "" );	                                                                      //������ ������
	polynom(const polynom& pol);                           							                                 //����������� �����������+
	polynom& operator=(const polynom &pol);                                                                          //������������
	polynom operator+(const polynom& pol) const;			                                                         //�������� ���������
	polynom operator*(const double a) const;				                                                         //��������� �� ��������� �����
	polynom operator-(const polynom& pol) const { return *this + (-1)*pol; }		                                 //�������� ���������
	polynom operator*(const polynom& pol) const;			                                                         //��������� ��������� 	
    friend polynom operator*(const double a,const polynom& pol) { return pol*a; }	                                 //��������� �� ��������� ������
    polynom operator-() const { return (-1)*(*this); }                                                               //������� �����
    friend ostream& operator<<(ostream &ostr, const polynom &pol);	                                                 //������� � �����

	
	bool operator==(const polynom& pml) const { return list_pol == pml.list_pol; }		
	bool operator!=(const polynom& pml) const { return list_pol != pml.list_pol; }

	polynom(list<monom> &inlist) : list_pol(inlist) {}								                //����������� �� ������
};
