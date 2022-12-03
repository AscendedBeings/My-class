#pragma once
#include <iostream>
#include <iomanip>

using namespace std;


#define EPISON 1e-10					//double and long double check zero���������ȵ�0ֵ�ж�
#define Set_extend_Patch 30				//extend the set����������ʱ��������
#define	Set_output_precision 10			//set output precision�������������


class MySet				//class for Set��������
{
private:
	int Max_account;					//The most number for saving element����ǰ�ɴ洢����༯��Ԫ�ظ���
	int account;						//current saved number of element����ǰ�Ѵ洢����Ԫ�ظ���
	long double *set_date = NULL;		//save data���洢����Ԫ��
	void extend();						//extend max number for saving data�����Ӽ��Ͽɴ洢�����
public:
	MySet();
	MySet(const MySet& parameter);
	~MySet();
	void display_all_element();								//output set;�������
	int element_account();									//return the number of set�����ؼ���Ԫ�ظ���
	long double search_element_index(const int index);		//search element by index�����ݼ����±귵��Ԫ��ֵ
	int search_element_value(const long double value);		//search element by value������Ԫ��ֵ����Ԫ��λ�ã��ɹ�����λ����ţ�ʧ�ܷ���-1
	int add_element(const long double value);				//add element�����Ԫ��
	int delete_element_value(const long double value);		//delete element according value������Ԫ��ֵɾ������Ԫ��
	int delete_element_index(const int index);				//delete element according index������Ԫ�����ɾ������Ԫ��

	MySet& operator=(const MySet& parameter);
	MySet operator+(const MySet& parameter);
	MySet operator-(const MySet& parameter);
	MySet operator*(const MySet& parameter);
	bool operator==(const MySet& parameter);
	friend bool is_sub_set(const MySet& parameter1, const MySet& parameter2);		
};

bool is_sub_set(const MySet& parameter1, const MySet& parameter2);		//check first parameter is subset of second parameter��������1�Ƿ����2�Ӽ�



enum operator_way	//using for choose operator way, rows OR columns�������ж��л��в���
{
	op_lows,	//operator row�������в���
	op_raws		//operator columns�������в���
};

class MyMatrix		//class for Matrix��������
{
private:
	int lows;			//number of row����������
	int raws;			//number of columns����������
	long double **matrix_data;												//save data���������Ԫ��ֵ
	bool isomorphic_matrix(const MyMatrix& parameter);						//is isomorphic matrix or not���ж��Ƿ�Ϊͬ�;���
	void exchange(long double& x, long double& y);							//exchange two parameter value����������ֵ
	void elementary_transformation_exchange(const operator_way sign, const int target1, const int target2);										
	//elementary transformation:exchange two rows or columns�����ȱ任���������л�����
	void elementary_transformation_times(const operator_way sign, const int target, const double times_parameter);								
	//elementary transformation:number times row or column�����ȱ任��ĳ�л�ĳ�г���ĳ��
	void elementary_transformation_times(const operator_way sign, const int target, const long double times_parameter);							
	//elementary transformation:number times row or column�����ȱ任��ĳ�л�ĳ�г���ĳ��
	void elementary_transformation_combine(const operator_way sign, const int target1, const int target2, const double times_parameter);	
	//elementary transformation:number times first row add to second row, OR for columns�����ȱ任������1�г���ĳ���ӵ�����2�У�������б任
	void elementary_transformation_combine(const operator_way sign, const int target1, const int target2, const long double times_parameter);
	//elementary transformation:number times first row add to second row, OR for columns�����ȱ任������1�г���ĳ���ӵ�����2�У�������б任
	long double adjust_date(const long double parameter);
	//adjust negative zero����������

public:
	MyMatrix();
	MyMatrix(const MyMatrix& parameter);
	MyMatrix(const int lows_parameter, const int raws_parameter, const long double value_parameter = 1);
	~MyMatrix();
	void display_all_element(const bool adjust_date_parameter = true);
	//ouput function,if parameter is true, adjust negative zero����ӡ�������������Ϊ�棬�����������
	void creat_form_array(const int lows_parameter, const int raws_parameter, long double** data_parameter);
	//creat matrix from array������ֵ��������
	void down_trianglation();
	//change the square to lower triangular matrix��תΪ�����Ǿ���
	void up_trianglation();
	//change the square to upper triangular matrix��תΪ�����Ǿ���
	void diagonalization();
	//change the square to diagonalize matrix��תΪ�ԽǾ���
	void identitilization();
	//change the square to unitary matrix��תΪ��λ����
	MyMatrix transpose();
	//matrix transpose������ת��
	bool is_square_matrix();
	//check the matrix is square matrix or not������Ƿ��Ƿ���

	MyMatrix& operator=(const MyMatrix& parameter);
	MyMatrix operator+(const MyMatrix& parameter);
	MyMatrix operator-(const MyMatrix& parameter);
	MyMatrix operator*(const MyMatrix& parameter);
	MyMatrix operator*(const long double parameter);
	bool operator==(const MyMatrix& parameter);

	friend MyMatrix algebraic_remainder(const int i, const int j, const MyMatrix parameter);
	friend long double matrix_det(const MyMatrix parameter);
	friend MyMatrix adjugate_matrix(const MyMatrix parameter);
	friend MyMatrix inverse_matrix(const MyMatrix parameter);
	friend int rank_matrix(const MyMatrix parameter);
	friend MyMatrix operator*(const long double parameter1, const MyMatrix parameter2);
};

MyMatrix algebraic_remainder(const int i, const int j, const MyMatrix parameter);
//return algebraic remainder�����ش�������ʽ
long double matrix_det(const MyMatrix parameter);
//return determinant value of square matrix�����ط��������ʽ��ֵ
MyMatrix adjugate_matrix(const MyMatrix parameter);
//retrun adjugate matrix of square matrix�����ط���İ������
MyMatrix inverse_matrix(const MyMatrix parameter);
//return inverse matrix of square matrix�����ط���������
int rank_matrix(const MyMatrix parameter);
//return the rank of matrix�����ؾ������
MyMatrix operator*(const long double parameter1, const MyMatrix parameter2);