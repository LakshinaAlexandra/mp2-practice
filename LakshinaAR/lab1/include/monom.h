#pragma once

//#define EPS 1e-15

class monom
{
public:
	double coeff;				                                    //����������� ����� �������
	unsigned int abc;	                                            //���������� �������
	monom(double c = 0, unsigned int a = 0);                        //�����������
	monom& operator=(const monom& m);                              //�������� ������������
	bool operator< (const monom& m);		 
	bool operator> (const monom& m);		
	bool operator==(const monom& m);
	bool operator!=(const monom& m);
};