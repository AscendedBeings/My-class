#include "MyMath.h"



MySet::MySet()
{
	Max_account = Set_extend_Patch;
	account = 0;
	set_date = new long double[Set_extend_Patch];
}

MySet::MySet(const MySet& parameter)
{
	Max_account = parameter.Max_account;
	set_date = new long double[Max_account];
	account = parameter.account;
	for (int i = 0; i < parameter.account; i++)
	{
		set_date[i] = parameter.set_date[i];
	}
}

MySet::~MySet()
{
	Max_account = 0;
	account = 0;
	delete [] set_date;
}


void MySet::extend()
{
	long double* temp;
	temp = new long double[account + 1];
	for (int i = 0; i < account; i++)
	{
		temp[i] = set_date[i];
	}
	delete set_date;
	set_date = new long double[Max_account + Set_extend_Patch];
	for (int i = 0; i < account; i++)
	{
		set_date[i] = temp[i];
	}
	Max_account = Max_account + Set_extend_Patch;
}

void MySet::display_all_element()
{
	if (account == 0)
	{
		cout << "set is empty!" << endl;
	}
	else
	{
		cout << "set has " << account << " elements." << endl;
		for (int i = 0; i < account; i++)
		{
			cout << set_date[i];
			cout << "     ";
			if ((i + 1) % 5 == 0)
			{
				cout << endl;		
			}
		}
	}
	cout << endl;
}

int MySet::element_account()
{
	return account;
}

long double MySet::search_element_index(const int index)
{
	if (index > account)
	{
		return -1;
	}
	else
	{
		return set_date[index - 1];
	}
}

int MySet::search_element_value(const long double value)
{
	for (int i = 0; i < account; i++)
	{
		if (set_date[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int MySet::add_element(const long double value)
{
	for (int i = 0; i < account; i++)
	{
		if (set_date[i] == value)
		{
			return -1;
		}
	}
	if (account + 1 == Max_account)
	{
		extend();
	}
	set_date[account] = value;
	account = account + 1;
	return 1;
}

int MySet::delete_element_index(const int index)
{
	if (index > account)
	{
		cout << "out of range!" << endl;
		return -1;
	}
	else if (index == account)
	{
		set_date[index - 1] = UINT_MAX;
		account = account - 1;
		return 1;
	}
	else
	{
		for (int i = index; i < account; i++)
		{
			set_date[i - 1] = set_date[i];
		}
		account = account - 1;
		return 1;
	}
}

int MySet::delete_element_value(const long double value)
{
	int delete_index;
	delete_index = search_element_value(value);
	if (delete_index == -1)
	{
		return -1;
	}
	else
	{
		delete_element_index(delete_index + 1);
		return 1;
	}
}

MySet& MySet::operator=(const MySet& parameter)
{
	if (this != &parameter)
	{
		this->Max_account = parameter.Max_account;
		this->set_date = new long double[Max_account];
		this->account = parameter.account;
		for (int i = 0; i < parameter.account; i++)
		{
			this->set_date[i] = parameter.set_date[i];
		}
	}
	return *this;
}

MySet MySet::operator+(const MySet& parameter)
{
	MySet temp;
	temp = parameter;
	for (int i = 0; i < account; i++)
	{
		temp.add_element(set_date[i]);
	}
	return temp;
}

MySet MySet::operator-(const MySet& parameter)
{
	MySet temp;
	int delete_index = -1;
	long double value;
	temp = *this;
	for (int i = 0; i < parameter.account; i++)
	{
		delete_index = -1;
		value = parameter.set_date[i];
		delete_index = temp.search_element_value(value);
		if (delete_index != -1)
		{
			temp.delete_element_index(delete_index + 1);
		}
	}
	return temp;
}

MySet MySet::operator*(const MySet& parameter)
{
	MySet temp;
	int search_index = -1;
	for (int i = 0; i < parameter.account; i++)
	{		
		search_index = -1;
		search_index = this->search_element_value(parameter.set_date[i]);
		if (search_index != -1)
		{
			temp.add_element(parameter.set_date[i]);
		}
	}
	return temp;
}

bool MySet::operator==(const MySet& parameter)
{
	int qu_count = 0;
	int search_index = -1;
	if (this->account != parameter.account)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < parameter.account; i++)
		{
			search_index = -1;
			search_index = this->search_element_value(parameter.set_date[i]);
			if (search_index == -1)
			{
				return false;
			}
			else
			{
				qu_count++;
			}
		}
		if (qu_count == parameter.account)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
}

bool is_sub_set(const MySet& parameter1, const MySet& parameter2)
{
	int qu_count = 0;
	int search_index = -1;
	long double value;
	if (parameter1.account > parameter2.account)
	{
		return false;
	}
	else
	{
		long double* temp1 = new long double[parameter1.account];
		long double* temp2 = new long double[parameter2.account];
		for (int i = 0; i < parameter1.account; i++)
		{
			temp1[i] = parameter1.set_date[i];
		}
		for (int i = 0; i < parameter2.account; i++)
		{
			temp2[i] = parameter2.set_date[i];
		}
		for (int i = 0; i < parameter1.account; i++)
		{
			search_index = -1;
			for (int j = 0; j < parameter2.account; j++)
			{
				if (temp1[i] == temp2[j])
				{
					qu_count++;
					search_index = 1;
					break;
				}
			}
			if (search_index == -1)
			{
				return false;
			}
		}
		if (qu_count == parameter1.account)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}





MyMatrix::MyMatrix()
{
	lows = 2;
	raws = 2;
	matrix_data = new long double *[lows];
	for (int i = 0; i < lows; i++)
	{
		matrix_data[i] = new long double [raws];
	}
	for (int i = 0; i < lows; i++)
	{
		for (int j = 0; j < raws; j++)
		{
			matrix_data[i][j] = 0;
		}
	}
}

MyMatrix::MyMatrix(const MyMatrix& parameter)
{
	lows = parameter.lows;
	raws = parameter.raws;
	matrix_data = new long double* [lows];
	for (int i = 0; i < lows; i++)
	{
		matrix_data[i] = new long double[raws];
	}
	for (int i = 0; i < lows; i++)
	{
		for (int j = 0; j < raws; j++)
		{
			matrix_data[i][j] = parameter.matrix_data[i][j];
		}
	}
}

MyMatrix::MyMatrix(const int lows_parameter, const int raws_parameter, const long double value_parameter)
{
	lows = lows_parameter;
	raws = raws_parameter;
	matrix_data = new long double* [lows];
	for (int i = 0; i < lows; i++)
	{
		matrix_data[i] = new long double[raws];
	}
	for (int i = 0; i < lows; i++)
	{
		for (int j = 0; j < raws; j++)
		{
			matrix_data[i][j] = value_parameter;
		}
	}
}

MyMatrix::~MyMatrix()
{
	lows = 0;
	raws = 0;
	for (int i = 0; i < lows; i++)
	{
		delete[]matrix_data[i];
	}
	delete[]matrix_data;
}

void MyMatrix::exchange(long double& x, long double& y)
{
	long double temp;
	temp = x;
	x = y;
	y = temp;
}

void MyMatrix::elementary_transformation_exchange(const operator_way sign, const int target1, const int target2)
{
	int index1, index2;
	index1 = target1 - 1;
	index2 = target2 - 1;
	if (sign == op_lows)
	{
		if (index1<0 || index2<0 || index1>lows - 1 || index2>lows - 1)
		{
		}
		else
		{
			for (int i = 0; i < raws; i++)
			{
				exchange(matrix_data[index1][i], matrix_data[index2][i]);
			}
		}		
	}
	else
	{	
		if (index1<0 || index2<0 || index1>raws - 1 || index2>raws - 1)
		{
		}
		else
		{
			for (int i = 0; i < lows; i++)
			{
				exchange(matrix_data[i][index1], matrix_data[i][index2]);
			}
		}		
	}
}


void MyMatrix::elementary_transformation_times(const operator_way sign, const int target, const double times_parameter)
{
	int index;
	index = target - 1;
	if (sign == op_lows)
	{		
		if (index<0 || index>lows - 1)
		{

		}
		else
		{
			for (int i = 0; i < raws; i++)
			{
				matrix_data[index][i] = matrix_data[index][i] * times_parameter;
			}
		}
	}
	else
	{
		if (index<0 || index>raws - 1)
		{

		}
		else
		{
			for (int i = 0; i < lows; i++)
			{
				matrix_data[i][index] = matrix_data[i][index] * times_parameter;
			}
		}	
	}
}

void MyMatrix::elementary_transformation_times(const operator_way sign, const int target, const long double times_parameter)
{
	int index;
	index = target - 1;
	if (sign == op_lows)
	{
		if (index<0 || index>lows - 1)
		{

		}
		else
		{
			for (int i = 0; i < raws; i++)
			{
				matrix_data[index][i] = matrix_data[index][i] * times_parameter;
			}
		}
	}
	else
	{
		if (index<0 || index>raws - 1)
		{

		}
		else
		{
			for (int i = 0; i < lows; i++)
			{
				matrix_data[i][index] = matrix_data[i][index] * times_parameter;
			}
		}
	}
}


void MyMatrix::elementary_transformation_combine(const operator_way sign, const int target1, const int target2, const double times_parameter)
{
	int index1, index2;
	index1 = target1 - 1;
	index2 = target2 - 1;
	if (sign == op_lows)
	{
		if (index1<0 || index2<0 || index1>lows - 1 || index2>lows - 1)
		{
		}
		else
		{
			for (int i = 0; i < raws; i++)
			{
				matrix_data[index2][i] = matrix_data[index2][i] + matrix_data[index1][i] * times_parameter;
			}
		}
	}
	else
	{
		if (index1<0 || index2<0 || index1>raws - 1 || index2>raws - 1)
		{
		}
		else
		{
			for (int i = 0; i < lows; i++)
			{
				matrix_data[i][index2] = matrix_data[i][index2] + matrix_data[i][index1] * times_parameter;
			}
		}
	}
}

void MyMatrix::elementary_transformation_combine(const operator_way sign, const int target1, const int target2, const long double times_parameter)
{
	int index1, index2;
	index1 = target1 - 1;
	index2 = target2 - 1;
	if (sign == op_lows)
	{
		if (index1<0 || index2<0 || index1>lows - 1 || index2>lows - 1)
		{
		}
		else
		{
			for (int i = 0; i < raws; i++)
			{
				matrix_data[index2][i] = matrix_data[index2][i] + matrix_data[index1][i] * times_parameter;
			}
		}
	}
	else
	{
		if (index1<0 || index2<0 || index1>raws - 1 || index2>raws - 1)
		{
		}
		else
		{
			for (int i = 0; i < lows; i++)
			{
				matrix_data[i][index2] = matrix_data[i][index2] + matrix_data[i][index1] * times_parameter;
			}
		}
	}
}

long double MyMatrix::adjust_date(const long double parameter)
{
	long double zero = 0;
	if (parameter < EPISON && parameter > -EPISON)
	{
		return zero;
	}
	else
	{
		return parameter;
	}
}



void MyMatrix::display_all_element(const bool adjust_date_parameter)
{
	if (lows == 0 || raws == 0)
	{
		cout << "matrix is empty!" << endl;
	}
	else
	{
		cout << "set is " << lows << " * " << raws << " matrix." << endl;
		for (int i = 0; i < lows; i++)
		{
			for (int j = 0; j < raws; j++)
			{
				cout.setf(ios::fixed);
				if (adjust_date_parameter)
				{
					cout << std::setprecision(Set_output_precision) << adjust_date(matrix_data[i][j]) << "    ";
				}
				else
				{
					cout << std::setprecision(Set_output_precision) << matrix_data[i][j] << "    ";
				}
			}
			cout << endl;
		}
	}
	cout.unsetf(ios::fixed);
	cout << endl;
}

void MyMatrix::creat_form_array(const int lows_parameter, const int raws_parameter, long double** data_parameter)
{
	lows = lows_parameter;
	raws = raws_parameter;
	matrix_data = new long double* [lows];
	for (int i = 0; i < lows; i++)
	{
		matrix_data[i] = new long double[raws];
	}
	for (int i = 0; i < lows; i++)
	{
		for (int j = 0; j < raws; j++)
		{
			matrix_data[i][j] = data_parameter[i][j];
		}
	}
}

bool MyMatrix::isomorphic_matrix(const MyMatrix& parameter)
{
	if ((this->lows == parameter.lows) && (this->raws == parameter.raws))
	{
		return true;
	}
	else
	{
		return false;
	}
}

MyMatrix MyMatrix::transpose()
{
	MyMatrix temp(raws, lows);
	for (int i = 0; i < temp.lows; i++)
	{
		for (int j = 0; j < temp.raws; j++)
		{
			temp.matrix_data[i][j] = matrix_data[j][i];
		}
	}
	return temp;
}

bool MyMatrix::is_square_matrix()
{
	if (lows == raws)
	{
		return true;
	}
	else
	{
		return false;
	}
}

MyMatrix& MyMatrix::operator=(const MyMatrix& parameter)
{
	this->lows = parameter.lows;
	this->raws = parameter.raws;
	this->matrix_data = new long double* [lows];
	for (int i = 0; i < lows; i++)
	{
		this->matrix_data[i] = new long double[raws];
	}
	for (int i = 0; i < lows; i++)
	{
		for (int j = 0; j < raws; j++)
		{
			this->matrix_data[i][j] = parameter.matrix_data[i][j];
		}
	}
	return *this;
}

MyMatrix MyMatrix::operator+(const MyMatrix& parameter)
{
	MyMatrix temp;
	if ((lows == parameter.lows) && (raws == parameter.raws))
	{
		temp = MyMatrix(lows, raws, 1);
		for (int i = 0; i < lows; i++)
		{
			for (int j = 0; j < raws; j++)
			{
				temp.matrix_data[i][j] = matrix_data[i][j] + parameter.matrix_data[i][j];
			}
		}
	}
	return temp;
}

MyMatrix MyMatrix::operator-(const MyMatrix& parameter)
{
	MyMatrix temp;
	if ((lows == parameter.lows) && (raws == parameter.raws))
	{
		temp = MyMatrix(lows, raws, 1);
		for (int i = 0; i < lows; i++)
		{
			for (int j = 0; j < raws; j++)
			{
				temp.matrix_data[i][j] = matrix_data[i][j] - parameter.matrix_data[i][j];
			}
		}
	}
	return temp;
}

MyMatrix MyMatrix::operator*(const MyMatrix& parameter)
{
	MyMatrix temp;
	long double sum = 0;
	if (raws == parameter.lows)
	{
		temp = MyMatrix(lows, parameter.raws, 1);
		for (int i = 0; i < lows; i++)
		{
			for (int j = 0; j < parameter.raws; j++)
			{
				sum = 0;
				for (int k = 0; k < raws; k++)
				{
					sum += matrix_data[i][k] * parameter.matrix_data[k][j];
				}
				temp.matrix_data[i][j] = sum;
			}
		}
	}
	return temp;
}

MyMatrix MyMatrix::operator*(const long double parameter)
{
	MyMatrix temp(lows, raws);
	for (int i = 0; i < lows; i++)
	{
		for (int j = 0; j < raws; j++)
		{
			temp.matrix_data[i][j] = parameter * matrix_data[i][j];
		}
	}
	return temp;
}

bool MyMatrix::operator==(const MyMatrix& parameter)
{
	if ((lows == parameter.lows) && (raws == parameter.raws))
	{
		for (int i = 0; i < lows; i++)
		{
			for (int j = 0; j < raws; j++)
			{
				if (matrix_data[i][j] != parameter.matrix_data[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void MyMatrix::down_trianglation()
{
	long double rate = 0;
	int swap_1 = 0;
	int swap_2 = 0;
	if (is_square_matrix())
	{
		for (swap_1 = lows - 1; swap_1 > 0; swap_1--)
		{
			for (swap_2 = swap_1 - 1; swap_2 >= 0; swap_2--)
			{
				if (matrix_data[swap_1][swap_1] == 0)
				{
					bool step_sign = false;
					for (int exchange_index = swap_1 - 1; exchange_index >= 0; exchange_index--)
					{
						if (matrix_data[exchange_index][swap_1] == 0)
						{
							continue;
						}
						else
						{
							elementary_transformation_exchange(op_lows, swap_1 + 1, exchange_index + 1);
							step_sign = true;
							break;
						}
					}
					if (step_sign)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				else
				{
					rate = -matrix_data[swap_2][swap_1] / matrix_data[swap_1][swap_1];
					elementary_transformation_combine(op_lows, swap_1 + 1, swap_2 + 1, rate);
				}			
			}
		}
	}
	else
	{
		cout << "The matrix is not square matrix." << endl;
	}
}

void MyMatrix::up_trianglation()
{
	long double rate = 0;
	int swap_1 = 0;
	int swap_2 = 0;
	if (is_square_matrix())
	{
		for (swap_1 = 0; swap_1 < lows; swap_1++)
		{
			for (swap_2 = swap_1 + 1; swap_2 < lows; swap_2++)
			{
				if (matrix_data[swap_1][swap_1] == 0)
				{
					bool step_sign = false;
					for (int exchange_index = swap_1 + 1; exchange_index < lows; exchange_index++)
					{
						if (matrix_data[exchange_index][swap_1] == 0)
						{
							continue;
						}
						else
						{
							elementary_transformation_exchange(op_lows, swap_1 + 1, exchange_index + 1);
							step_sign = true;
							break;
						}
					}
					if (step_sign)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				else
				{
					rate = -matrix_data[swap_2][swap_1] / matrix_data[swap_1][swap_1];
					elementary_transformation_combine(op_lows, swap_1 + 1, swap_2 + 1, rate);
				}
			}
		}
	}
	else
	{
		cout << "The matrix is not square matrix." << endl;
	}
}

void MyMatrix::diagonalization()
{
	if (is_square_matrix())
	{
		up_trianglation();
		down_trianglation();
	}
}

void MyMatrix::identitilization()
{
	if (is_square_matrix())
	{
		for (int i = 0; i < lows; i++)
		{
			matrix_data[i][i] = 1;
		}
	}
	else
	{
		cout << "The matrix is not square matrix." << endl;
	}
}

MyMatrix algebraic_remainder(const int x, const int y, const MyMatrix parameter)
{
	MyMatrix temp(parameter.lows - 1, parameter.raws - 1);
	int sx = x - 1;
	int sy = y - 1;
	for (int ti = 0, i = 0; i < temp.lows; i++, ti++)
	{
		for (int tj = 0, j = 0; j < temp.raws; j++, tj++)
		{
			if (i >= sx && j >= sy)
			{
				temp.matrix_data[ti][tj] = parameter.matrix_data[i + 1][j + 1];
			}
			else if (i >= sx && j < sy)
			{
				temp.matrix_data[ti][tj] = parameter.matrix_data[i + 1][j];
			}
			else if (i < sx && j >= sy)
			{
				temp.matrix_data[ti][tj] = parameter.matrix_data[i][j + 1];
			}
			else
			{
				temp.matrix_data[ti][tj] = parameter.matrix_data[i][j];
			}
		}
	}
	return temp;
}

long double matrix_det(const MyMatrix parameter)
{
	long double result = 0;
	if (parameter.raws != parameter.lows)
	{
		cout << "The matrix is not square matrix." << endl;
	}
	else
	{
		if (parameter.lows == 1)
		{
			return parameter.matrix_data[0][0];
		}
		else if (parameter.lows == 2)
		{
			result = parameter.matrix_data[0][0] * parameter.matrix_data[1][1] - parameter.matrix_data[1][0] * parameter.matrix_data[0][1];
		}
		else
		{
			result = 0;
			for (int i = 0; i < parameter.lows; i++)
			{
				if (i % 2 == 0)
				{
					result = result + parameter.matrix_data[i][0] * matrix_det(algebraic_remainder(i + 1, 1, parameter));
				}
				else
				{
					result = result - parameter.matrix_data[i][0] * matrix_det(algebraic_remainder(i + 1, 1, parameter));
				}
			}
		}
	}
	return result;
}

MyMatrix adjugate_matrix(const MyMatrix parameter)
{
	MyMatrix temp(parameter.lows, parameter.raws);
	if (parameter.raws != parameter.lows)
	{
		cout << "The matrix is not square matrix." << endl;
	}
	else
	{
		for (int i = 0; i < temp.lows; i++)
		{
			for (int j = 0; j < temp.raws; j++)
			{
				temp.matrix_data[i][j] = pow(-1, (i + j + 2)) * matrix_det(algebraic_remainder(j + 1, i + 1, parameter));
			}
		}
	}
	return temp;
}

MyMatrix inverse_matrix(const MyMatrix parameter)
{
	MyMatrix temp;
	long double det_value = 0;
	temp = adjugate_matrix(parameter);
	det_value = matrix_det(parameter);
	for (int i = 0; i < temp.lows; i++)
	{
		for (int j = 0; j < temp.raws; j++)
		{
			temp.matrix_data[i][j] = temp.matrix_data[i][j] / det_value;
		}
	}
	return temp;
}

int rank_matrix(const MyMatrix parameter)
{
	int result = 0;
	long double rate = 0;
	int swap_1 = 0;
	int swap_2 = 0;
	MyMatrix temp = parameter;
	if (temp.lows > temp.raws)
	{
		temp = temp.transpose();
	}
	for (swap_1 = 0; swap_1 < temp.lows; swap_1++)
	{
		for (swap_2 = swap_1 + 1; swap_2 < temp.lows; swap_2++)
		{
			if (temp.matrix_data[swap_1][swap_1] == 0)
			{
				bool step_sign = false;
				for (int exchange_index = swap_1 + 1; exchange_index < temp.lows; exchange_index++)
				{
					if (temp.matrix_data[exchange_index][swap_1] == 0)
					{
						continue;
					}
					else
					{
						temp.elementary_transformation_exchange(op_lows, swap_1 + 1, exchange_index + 1);
						step_sign = true;
						break;
					}
				}
				if (step_sign)
				{
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				rate = -temp.matrix_data[swap_2][swap_1] / temp.matrix_data[swap_1][swap_1];
				temp.elementary_transformation_combine(op_lows, swap_1 + 1, swap_2 + 1, rate);
			}
		}
	}
	for (int i = temp.lows - 1; i >= 0; i--)
	{
		int sum = 0;
		for (int j = 0; j < temp.raws; j++)
		{
			sum += abs(temp.matrix_data[i][j]);
		}
		if (sum != 0)
		{
			break;
		}
		else
		{
			result++;
		}
	}
	result = temp.lows - result;
	return result;
}

MyMatrix operator*(const long double parameter1, const MyMatrix parameter2)
{
	MyMatrix temp = parameter2;
	temp = temp * parameter1;
	return temp;
}