/*
File: Matrix_Functions.cpp
Author: Sam Shedwick
Date: 4/19/2025

This file makes a Matrix class that can use Matrix addition, Scalar 
multiplication, Matrix multiplication, and Matrix Transposing. It makes 
3 matricies, A, B, and C, and prints out A, B, C, 3 * Matrix B, C^T, 
(3 * Matrix B) * C^T, and A + ((3 * Matrix B) * C^T). It then tests each 
function to verify they work
*/

#include <iostream>

using namespace std;

class Matrix
{
public:
	friend class Tester;

	// Constructor
	Matrix(int rowLength, int columnLength);

	// Destructor
	~Matrix();

	// Clears the matrix of all integers
	void clear();

	// Inserts an integer at the inputted row and column index
	void insertValue(int rowIndex, int columnIndex, int value);

	// Multiplies all integers in the matrix by an inputted float 
	// value
	void scalarMultiply(int multiplyValue);

	// Multiplies the matrix by the inputted matrix
	void multiply2Matricies(const Matrix& rhsMatrix);

	// Adds all integers in the matrix by the integer at the same 
	// index in the inputted matrix 
	void add2Matricies(const Matrix& aMatrix);

	// Transposes the matrix
	void transposeMatrix();

	// Prints out the all integers in the matrix with formating to 
	// make it look like a matrix
	void printMatrix();
private:
	int** m_matrix; // 2d array matrix
	int m_rowLength; // Number of columns in matrix
	int m_columnLength; // Size of columns in matrix
};

class Tester
{
public:
	// Tests the edge and normal cases of the scalar multiply function
	bool testScalarMultiplyEdgeCaseZeroScalar();
	bool testScalarMultiplyNormalCasePositiveScalar();

	// Tests the error, edge, and normal cases of the multiply two 
	// matricies function
	bool testMultiplyTwoMatriciesErrorCaseIncompatibleMatricies();
	bool testMultiplyTwoMatriciesEdgeCaseBothOneByOne();
	bool testMultiplyTwoMatriciesNormalCaseBothTwoByTwo();

	// Tests the error, edge, and normal cases of the add two 
	// matricies function
	bool testAddTwoMatriciesErrorCaseIncompatibleMatricies();
	bool testAddTwoMatriciesEdgeCaseBothOneByOne();
	bool testAddTwoMatriciesNormalCaseBothTwoByTwo();

	// Tests the edge and normal cases of the transpose matrix 
	// function
	bool testTransposeMatrixEdgeCaseOneByOneMatrix();
	bool testTransposeMatrixNormalCaseTwoByTwo();
private:
};

int main()
{
	// Makes a 2 by 2 matrix and inserts the 4 values into it
	int matrixARowLength = 2;
	int matrixAColumnLength = 2;
	Matrix matrixA = Matrix(matrixARowLength, matrixAColumnLength);
	matrixA.insertValue(0, 0, 6);
	matrixA.insertValue(0, 1, 8);
	matrixA.insertValue(1, 0, 4);
	matrixA.insertValue(1, 1, 3);

	// Makes a 3 by 2 matrix and inserts the values into it
	int matrixBRowLength = 3;
	int matrixBColumnLength = 2;
	Matrix matrixB = Matrix(matrixBRowLength, matrixBColumnLength);
	for (int i = 0; i < matrixBRowLength; i++)
	{
		matrixB.insertValue(i, 0, i + 1);
		matrixB.insertValue(i, 1, i + 4);
	}

	// Makes a 3 by 2 matrix and inserts the values into it
	int matrixCRowLength = 3;
	int matrixCColumnLength = 2;
	Matrix matrixC = Matrix(matrixCRowLength, matrixCColumnLength);
	for (int i = 0; i < matrixCRowLength; i++)
	{
		matrixC.insertValue(i, 0, 2*(i + 1));
		matrixC.insertValue(i, 1, (2*i)+1);
	}

	// Prints out the 3 matricies
	cout << "Matrix A:" << endl;
	matrixA.printMatrix();
	cout << "Matrix B:" << endl;
	matrixB.printMatrix();
	cout << "Matrix C:" << endl;
	matrixC.printMatrix();

	// Multiplies matrix B by 3 and prints it out
	cout << "3 * Matrix B:" << endl;
	matrixB.scalarMultiply(3);
	matrixB.printMatrix();

	// Transposes matrix C and prints it out
	cout << "Matrix C^T:" << endl;
	matrixC.transposeMatrix();
	matrixC.printMatrix();

	// Multiplies (3 * matrix B) and matrix C transpose, and prints 
	// it out
	cout << "(3 * Matrix B) * (Matrix C^T):" << endl;
	matrixB.multiply2Matricies(matrixC);
	matrixB.printMatrix();

	// Adds matrix A and ((3 * matrix B) * matrix C transpose), and
	// prints it out
	cout << "Matrix A + (3 * Matrix B) * (Matrix C^T):" << endl;
	matrixA.add2Matricies(matrixB);
	matrixA.printMatrix();

	cout << endl;


	Tester tester;

	// Testing the scalarMultiply function

	// Testing the edge cases 
	cout << "\nTesting scalarMultiply(...) for edge cases:\n\n";

	// Testing for the edge case of multiplying a matrix by 0 makes 
	// all values in the matrix 0
	cout << "\tEdge case (multiplying a matrix by 0 makes all values "
		"in the matrix 0) of scalarMultiply(...) ";
	if (tester.testScalarMultiplyEdgeCaseZeroScalar())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the normal cases 
	cout << "\nTesting scalarMultiply(...) for normal cases:\n\n";

	// Testing for the edge case of multiplying a matrix by a scalar 
	// value multiplies all values in the matrix by that value
	cout << "\tNormal case (multiplying a matrix by a scalar "
		"value multiplies all values in the matrix by that "
		"value) of scalarMultiply(...) ";
	if (tester.testScalarMultiplyNormalCasePositiveScalar())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the multiplyTwoMatricies function

	// Testing the error cases 
	cout << "\nTesting multiplyTwoMatricies(...) for error cases:\n\n";

	// Testing for the error case of trying to multiply 2 incompatible matricies
	cout << "\tError case (Trying to multiply 2 incompatible "
		"matricies) of multiplyTwoMatricies(...) ";
	if (tester.testMultiplyTwoMatriciesErrorCaseIncompatibleMatricies())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the edge cases 
	cout << "\nTesting multiplyTwoMatricies(...) for edge cases:\n\n";

	// Testing for the edge case of trying to multiply 2 one by one matricies
	cout << "\tEdge case (Trying to multiply 2 one by one matricies) "
		"of multiplyTwoMatricies(...) ";
	if (tester.testMultiplyTwoMatriciesEdgeCaseBothOneByOne())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the normal cases 
	cout << "\nTesting multiplyTwoMatricies(...) for normal cases:\n\n";

	// Testing for the normal case of trying to multiply 2 non one by one matricies
	cout << "\tNormal case (Trying to multiply 2 non one by one matricies) "
		"of multiplyTwoMatricies(...) ";
	if (tester.testMultiplyTwoMatriciesNormalCaseBothTwoByTwo())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the addTwoMatricies function

	// Testing the error cases 
	cout << "\nTesting addTwoMatricies(...) for error cases:\n\n";

	// Testing for the error case of trying to add 2 incompatible matricies
	cout << "\tError case (Trying to add 2 incompatible "
		"matricies) of addTwoMatricies(...) ";
	if (tester.testAddTwoMatriciesErrorCaseIncompatibleMatricies())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the edge cases 
	cout << "\nTesting addTwoMatricies(...) for edge cases:\n\n";

	// Testing for the edge case of trying to add 2 one by one matricies
	cout << "\tEdge case (Trying to add 2 one by one matricies) "
		"of addTwoMatricies(...) ";
	if (tester.testAddTwoMatriciesEdgeCaseBothOneByOne())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the normal cases 
	cout << "\nTesting addTwoMatricies(...) for normal cases:\n\n";

	// Testing for the normal case of trying to add 2 non one by one matricies
	cout << "\tNormal case (Trying to add 2 non one by one matricies) "
		"of addTwoMatricies(...) ";
	if (tester.testAddTwoMatriciesNormalCaseBothTwoByTwo())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the transposeMatrix function

	// Testing the edge cases 
	cout << "\nTesting transposeMatrix() for edge cases:\n\n";

	// Testing for the edge case of trying to transpose a one by one matrix
	cout << "\tEdge case (Transposing a one by one matrix) of transposeMatrix() ";
	if (tester.testTransposeMatrixEdgeCaseOneByOneMatrix())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	// Testing the normal cases 
	cout << "\nTesting transposeMatrix() for normal cases:\n\n";

	// Testing for the edge case of trying to transpose a non one by one matrix
	cout << "\tNormal case (Transposing a non one by one matrix) of transposeMatrix() ";
	if (tester.testTransposeMatrixNormalCaseTwoByTwo())
	{
		cout << "passed!\n" << endl;
	}
	else
	{
		cout << "failed!\n" << endl;
	}

	return 0;
}

Matrix::Matrix(int rowLength, int columnLength)
{
	// Makes the member variables equal to the inputted values
	m_rowLength = rowLength;
	m_columnLength = columnLength;

	// Makes a new 2d matrix with a size of the inputted value
	m_matrix = new int* [rowLength];

	// If the inputted row length and column length are greater than 0, 
	// it sets the 2d array to have the inputted column length, and 
	// have all 0's 
	if (rowLength > 0 && columnLength > 0)
	{
		for (int i = 0; i < rowLength; i++)
		{
			m_matrix[i] = new int[columnLength];
			for (int j = 0; j < columnLength; j++)
			{
				m_matrix[i][j] = 0;
			}
		}
	}
}

Matrix::~Matrix()
{
	// Clears the matrix and sets the other member variables to 0
	clear();
	m_columnLength = 0;
	m_rowLength = 0;
}

void Matrix::clear()
{
	// If the matrix isn't nullptr, it goes through the 2d array and 
	// deletes the column arrays and sets them to nullptr. It then 
	// deletes the 2d array itself and sets it to nullptr
	if (m_matrix != nullptr)
	{
		for (int i = 0; i < m_rowLength; i++)
		{
			delete m_matrix[i];
			m_matrix[i] = nullptr;
		}

		delete m_matrix;
		m_matrix = nullptr;
	}
}

void Matrix::insertValue(int rowIndex, int columnIndex, int value)
{
	// If the inputted row index and column index are greater than 0 
	// and less than the respective length, and the matrix isn't 
	// nullptr, it sets the integer at the row and column index to 
	// the inputted value
	if (rowIndex >= 0 && rowIndex < m_rowLength && columnIndex >= 0 
		&& columnIndex < m_columnLength && m_matrix != nullptr)
	{
		m_matrix[rowIndex][columnIndex] = value;
	}
}

void Matrix::scalarMultiply(int multiplyValue)
{
	// Checks if the matrix isn't nullptr
	if (m_matrix != nullptr)
	{
		// For each row in the matrix, if the column isn't nullptr, it 
		// multiplies the all integers in the column by the inputted 
		// float
		for (int i = 0; i < m_rowLength; i++)
		{
			if (m_matrix[i] != nullptr)
			{
				for (int j = 0; j < m_columnLength; j++)
				{
					m_matrix[i][j] *= multiplyValue;
				}
			}
		}
	}
}

void Matrix::multiply2Matricies(const Matrix& rhsMatrix)
{
	// Checks if the matrix and the inputed matrix aren't nullptr, and 
	// the inputted matrix's column length is equal to the matrix's 
	// row length
	if (m_matrix != nullptr && rhsMatrix.m_matrix != nullptr && rhsMatrix.m_columnLength == m_rowLength)
	{
		// Makes a new matrix to store the new multiplied matrix values
		int** newMatrix = new int*[rhsMatrix.m_rowLength];
		for (int i = 0; i < rhsMatrix.m_rowLength; i++)
		{
			newMatrix[i] = new int[m_columnLength];
		}

		// Integer tracker for the multiplied matrix values
		int newValue = 0;

		// Goes through each column of the inputted row length
		for (int i = 0; i < rhsMatrix.m_rowLength; i++)
		{
			// Goes through each row of the matrix and cross multiplies 
			// the row of the matrix by the current column of the 
			// inputted matrix. It then sets the value in newMatrix at 
			// i,j to the newValue tracker 
			for (int j = 0; j < m_columnLength; j++)
			{
				newValue = 0;
				for (int k = 0; k < m_rowLength; k++)
				{
					newValue += m_matrix[k][j] * rhsMatrix.m_matrix[i][k];
				}
				newMatrix[i][j] = newValue;
			}
		}

		// Clears the matrix, sets the matrix to newMatrix, and makes 
		// newMatrix equal to nullptr
		clear();
		m_matrix = newMatrix;
		newMatrix = nullptr;

		// Makes the row length the row length of the inputted matrix
		m_rowLength = rhsMatrix.m_rowLength;
	}
}

void Matrix::add2Matricies(const Matrix& rhsMatrix)
{
	// If the row and column length of the matrix and the inputed 
	// matrix match, it goes through each integer in the matrix and 
	// adds the integer at the same index in the inputted index to it
	if (m_columnLength == rhsMatrix.m_columnLength && m_rowLength == rhsMatrix.m_rowLength)
	{
		for (int i = 0; i < m_columnLength; i++)
		{
			for (int j = 0; j < m_rowLength; j++)
			{
				m_matrix[i][j] += rhsMatrix.m_matrix[i][j];
			}
		}
	}
}

void Matrix::transposeMatrix()
{
	// Checks if the row and column length are greater than 0
	if (m_rowLength > 0 && m_columnLength > 0)
	{
		// Swaps the row and column lengths
		int temp = m_rowLength;
		m_rowLength = m_columnLength;
		m_columnLength = temp;

		// Makes a new matrix to hold the transposed values
		int** newMatrix = new int* [m_rowLength];

		// For each column in the new matrix, it sets the values to 
		// the value in the opposite index of the matrix
		for (int i = 0; i < m_rowLength; i++)
		{
			newMatrix[i] = new int[m_columnLength];
			for (int j = 0; j < m_columnLength; j++)
			{
				newMatrix[i][j] = m_matrix[j][i];
			}
		}

		// Clears the matrix, sets the matrix to newMatrix, and sets newMatrix to nullptr
		clear();
		m_matrix = newMatrix;
		newMatrix = nullptr;
	}
}

void Matrix::printMatrix()
{
	// For each column, it prints out the entire row, seperating each 
	// index with a tab for good formatting and each row with a new 
	// line
	for (int i = 0; i < m_columnLength; i++)
	{
		cout << "[ ";
		for (int j = 0; j < m_rowLength; j++)
		{
			cout << m_matrix[j][i] << "\t";
		}
		cout << "]" << endl;
	}
}

bool Tester::testScalarMultiplyEdgeCaseZeroScalar()
{
	// Makes a test Matrix and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 2;
	Matrix testMatrix = Matrix(testMatrixRowLength, testMatrixColumnLength);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix.insertValue(i, 0, (i + 1));
		testMatrix.insertValue(i, 1, 3*(i + 1));
	}

	// Multiplies the test Matrix by 0
	testMatrix.scalarMultiply(0);

	// Tracker for if the matrix includes only 0's
	bool allZero = true;

	// Goes through each row and column and checks if all values are 0, 
	// with an expected result of true. Returns the allZero tracker
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		for (int j = 0; j < testMatrixColumnLength; j++)
		{
			if (testMatrix.m_matrix[i][j] != 0)
			{
				allZero = false;
			}
		}
	}
	return allZero;
}

bool Tester::testScalarMultiplyNormalCasePositiveScalar()
{
	// Makes a 2 test Matricies and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 2;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix1.insertValue(i, 0, (i + 1));
		testMatrix1.insertValue(i, 1, 3 * (i + 1));
		testMatrix2.insertValue(i, 0, (i + 1));
		testMatrix2.insertValue(i, 1, 3 * (i + 1));
	}

	// Multiplies the second test Matrix by 2
	testMatrix1.scalarMultiply(2);

	// Tracker for if the values in matrix 2 are all the values at the 
	// same index in matrix 1, but multiplied by 2
	bool multipliedCorrectly = true;

	// Goes through each row and column and checks if all the values at 
	// the same index in matrix 1, but multiplied by 2, with an expected 
	// result of true. Returns the multipliedCorrectly tracker
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		for (int j = 0; j < testMatrixColumnLength; j++)
		{
			if (2 * testMatrix2.m_matrix[i][j] != 
				testMatrix1.m_matrix[i][j])
			{
				multipliedCorrectly = false;
			}
		}
	}
	return multipliedCorrectly;
}

bool Tester::testMultiplyTwoMatriciesErrorCaseIncompatibleMatricies()
{
	// Makes a 2 test Matricies and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 2;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength + 1, testMatrixColumnLength + 1);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix1.insertValue(i, 0, i + 1);
		testMatrix1.insertValue(i, 1, i + 1);
	}

	for (int i = 0; i <= testMatrixRowLength; i++)
	{
		testMatrix2.insertValue(i, 0, i + 2);
		testMatrix2.insertValue(i, 1, i + 2);
		testMatrix2.insertValue(i, 2, i + 2);
	}

	// Attempts to multiply matrix 1 by matrix 2 and returns if the 
	// m_rowLength of matrix 1 was changed to the m_rowLength of 
	// matrix 2, with an expected result of it not being the case.
	testMatrix1.multiply2Matricies(testMatrix2);
	if (testMatrix1.m_rowLength == testMatrix2.m_rowLength)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Tester::testMultiplyTwoMatriciesEdgeCaseBothOneByOne()
{
	// Makes a 2 test Matricies and fills them with a test value
	int testMatrixRowLength = 1;
	int testMatrixColumnLength = 1;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	testMatrix1.insertValue(0, 0, 1);
	testMatrix2.insertValue(0, 0, 2);

	// Multiplies matrix 1 by matrix 2 and returns if the values are 
	// correctly cross multiplied, with an expected result of true
	testMatrix1.multiply2Matricies(testMatrix2);
	if (testMatrix1.m_rowLength == testMatrix2.m_rowLength && 
		testMatrix1.m_matrix[0][0] == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tester::testMultiplyTwoMatriciesNormalCaseBothTwoByTwo()
{
	// Makes a 2 test Matricies and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 2;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix1.insertValue(i, 0, i + 1);
		testMatrix1.insertValue(i, 1, i + 1);
	}
	for (int i = 0; i <= testMatrixRowLength; i++)
	{
		testMatrix2.insertValue(i, 0, i + 2);
		testMatrix2.insertValue(i, 1, i + 2);
	}

	// Multiplies matrix 1 by matrix 2 and returns if the values are 
	// correctly cross multiplied, with an expected result of true
	testMatrix1.multiply2Matricies(testMatrix2);
	if (testMatrix1.m_rowLength == testMatrix2.m_rowLength &&
		testMatrix1.m_matrix[0][0] == 6 &&
		testMatrix1.m_matrix[0][1] == 6 &&
		testMatrix1.m_matrix[1][0] == 9 &&
		testMatrix1.m_matrix[1][1] == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tester::testAddTwoMatriciesErrorCaseIncompatibleMatricies()
{
	// Makes a 2 test Matricies and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 1;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength + 1, testMatrixColumnLength + 1);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix1.insertValue(i, 0, i + 1);
	}
	for (int i = 0; i <= testMatrixRowLength; i++)
	{
		testMatrix2.insertValue(i, 0, i + 2);
		testMatrix2.insertValue(i, 1, i + 2);
	}

	// Attempts to add matrix 2 to matrix 1 and returns if the values 
	// in matrix 1 were altered, with an expected result of it not 
	// being the case
	testMatrix1.multiply2Matricies(testMatrix2);
	if (testMatrix1.m_matrix[0][0] != 6 && testMatrix1.m_matrix[1][0] != 9)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Tester::testAddTwoMatriciesEdgeCaseBothOneByOne()
{
	// Makes a 2 test Matricies and fills them with a test value
	int testMatrixRowLength = 1;
	int testMatrixColumnLength = 1;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	testMatrix1.insertValue(0, 0, 1);
	testMatrix2.insertValue(0, 0, 2);

	// Adds matrix 2 to matrix 1 and returns if the values are 
	// correctly added, with an expected result of true
	testMatrix1.add2Matricies(testMatrix2);
	if (testMatrix1.m_matrix[0][0] == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tester::testAddTwoMatriciesNormalCaseBothTwoByTwo()
{
	// Makes a 2 test Matricies and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 2;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix1.insertValue(i, 0, i + 1);
		testMatrix1.insertValue(i, 1, i + 1);
	}
	for (int i = 0; i <= testMatrixRowLength; i++)
	{
		testMatrix2.insertValue(i, 0, i + 2);
		testMatrix2.insertValue(i, 1, i + 2);
	}

	// Adds matrix 2 to matrix 1 and returns if the values are 
	// correctly added, with an expected result of true
	testMatrix1.add2Matricies(testMatrix2);
	if (testMatrix1.m_matrix[0][0] == 3 && 
		testMatrix1.m_matrix[0][1] == 3 && 
		testMatrix1.m_matrix[1][0] == 5 && 
		testMatrix1.m_matrix[1][1] == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tester::testTransposeMatrixEdgeCaseOneByOneMatrix()
{
	// Makes a test Matrix and fills it with a test value
	int testMatrixRowLength = 1;
	int testMatrixColumnLength = 1;
	Matrix testMatrix = Matrix(testMatrixRowLength, testMatrixColumnLength);
	testMatrix.insertValue(0, 0, 1);

	// Transposes the matrix and checks if the value was correctly 
	// maintained, with an expected result of true
	testMatrix.transposeMatrix();
	if (testMatrix.m_matrix[0][0] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tester::testTransposeMatrixNormalCaseTwoByTwo()
{
	// Makes two test Matricies and fills them with test values
	int testMatrixRowLength = 2;
	int testMatrixColumnLength = 2;
	Matrix testMatrix1 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	Matrix testMatrix2 = Matrix(testMatrixRowLength, testMatrixColumnLength);
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		testMatrix1.insertValue(i, 0, i + 1);
		testMatrix1.insertValue(i, 1, i + 1);
		testMatrix2.insertValue(i, 0, i + 1);
		testMatrix2.insertValue(i, 1, i + 1);
	}

	// Transposes matrix 1
	testMatrix1.transposeMatrix();

	// Tracker for if the matrix was correctly transposed
	bool correctlyTransposed = true;

	// Goes through each value in matrix 1 and compares it to the 
	// value at the opposite index in matrix 2, and if they aren't 
	// equal to each other, it sets the correctlyTransposed tracker 
	// to false. It then returns the correctlyTransposed value
	for (int i = 0; i < testMatrixRowLength; i++)
	{
		for (int j = 0; j < testMatrixColumnLength; j++)
		{
			if (testMatrix1.m_matrix[i][j] != testMatrix2.m_matrix[j][i])
			{
				correctlyTransposed = false;
			}
		}
	}
	return correctlyTransposed;
}
