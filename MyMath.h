#pragma once
#include <iostream>
#include <iomanip>

using namespace std;


#define EPISON 1e-10					//double and long double check zero；浮点数等的0值判断
#define Set_extend_Patch 30				//extend the set；集合扩张时单次增加
#define	Set_output_precision 10			//set output precision；输出精度设置


class MySet				//class for Set；集合类
{
private:
	int Max_account;					//The most number for saving element；当前可存储的最多集合元素个数
	int account;						//current saved number of element；当前已存储集合元素个数
	long double *set_date = NULL;		//save data；存储集合元素
	void extend();						//extend max number for saving data；增加集合可存储最大数
public:
	MySet();
	MySet(const MySet& parameter);
	~MySet();
	void display_all_element();								//output set;输出集合
	int element_account();									//return the number of set；返回集合元素个数
	long double search_element_index(const int index);		//search element by index；根据集合下标返回元素值
	int search_element_value(const long double value);		//search element by value；根据元素值查找元素位置，成功返回位置序号，失败返回-1
	int add_element(const long double value);				//add element；添加元素
	int delete_element_value(const long double value);		//delete element according value；根据元素值删除集合元素
	int delete_element_index(const int index);				//delete element according index；根据元素序号删除集合元素

	MySet& operator=(const MySet& parameter);
	MySet operator+(const MySet& parameter);
	MySet operator-(const MySet& parameter);
	MySet operator*(const MySet& parameter);
	bool operator==(const MySet& parameter);
	friend bool is_sub_set(const MySet& parameter1, const MySet& parameter2);		
};

bool is_sub_set(const MySet& parameter1, const MySet& parameter2);		//check first parameter is subset of second parameter；检查参数1是否参数2子集



enum operator_way	//using for choose operator way, rows OR columns；用于判断列或行操作
{
	op_lows,	//operator row；矩阵行操作
	op_raws		//operator columns；矩阵列操作
};

class MyMatrix		//class for Matrix；矩阵类
{
private:
	int lows;			//number of row；矩阵行数
	int raws;			//number of columns；矩阵列数
	long double **matrix_data;												//save data；保存矩阵元素值
	bool isomorphic_matrix(const MyMatrix& parameter);						//is isomorphic matrix or not；判断是否为同型矩阵
	void exchange(long double& x, long double& y);							//exchange two parameter value；交换参数值
	void elementary_transformation_exchange(const operator_way sign, const int target1, const int target2);										
	//elementary transformation:exchange two rows or columns；初等变换，交换两行或两列
	void elementary_transformation_times(const operator_way sign, const int target, const double times_parameter);								
	//elementary transformation:number times row or column；初等变换，某行或某列乘以某数
	void elementary_transformation_times(const operator_way sign, const int target, const long double times_parameter);							
	//elementary transformation:number times row or column；初等变换，某行或某列乘以某数
	void elementary_transformation_combine(const operator_way sign, const int target1, const int target2, const double times_parameter);	
	//elementary transformation:number times first row add to second row, OR for columns；初等变换，参数1行乘以某数加到参数2行，或进行列变换
	void elementary_transformation_combine(const operator_way sign, const int target1, const int target2, const long double times_parameter);
	//elementary transformation:number times first row add to second row, OR for columns；初等变换，参数1行乘以某数加到参数2行，或进行列变换
	long double adjust_date(const long double parameter);
	//adjust negative zero；修正负零

public:
	MyMatrix();
	MyMatrix(const MyMatrix& parameter);
	MyMatrix(const int lows_parameter, const int raws_parameter, const long double value_parameter = 1);
	~MyMatrix();
	void display_all_element(const bool adjust_date_parameter = true);
	//ouput function,if parameter is true, adjust negative zero；打印函数，如果参数为真，修正负零输出
	void creat_form_array(const int lows_parameter, const int raws_parameter, long double** data_parameter);
	//creat matrix from array；从数值创建矩阵
	void down_trianglation();
	//change the square to lower triangular matrix；转为下三角矩阵
	void up_trianglation();
	//change the square to upper triangular matrix；转为上三角矩阵
	void diagonalization();
	//change the square to diagonalize matrix；转为对角矩阵
	void identitilization();
	//change the square to unitary matrix；转为单位矩阵
	MyMatrix transpose();
	//matrix transpose；矩阵转置
	bool is_square_matrix();
	//check the matrix is square matrix or not；检查是否是方阵

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
//return algebraic remainder；返回代数余子式
long double matrix_det(const MyMatrix parameter);
//return determinant value of square matrix；返回方阵的行列式的值
MyMatrix adjugate_matrix(const MyMatrix parameter);
//retrun adjugate matrix of square matrix；返回方阵的伴随矩阵
MyMatrix inverse_matrix(const MyMatrix parameter);
//return inverse matrix of square matrix；返回方阵的逆矩阵
int rank_matrix(const MyMatrix parameter);
//return the rank of matrix；返回矩阵的秩
MyMatrix operator*(const long double parameter1, const MyMatrix parameter2);