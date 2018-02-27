#pragma once



//����� ������
template<typename type>
class unit
{
public:
	type data;		                                                    //������ � ��������
	unit* next;	                                                        //��������� �� ��������� �������
	unit() { next = nullptr; }										    //����������� �� ���������
	unit(type dz) { data = dz; next = nullptr; }					    //����������� � ����������
	bool operator< (const unit& z) { return (data<z.data); }	 
	bool operator> (const unit& z) { return (data>z.data); }	
};