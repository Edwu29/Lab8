/*  Program: Lab8, Matrix Chain Product
	Author: Edward Wu
	Class: CSCI 230
	Date: 04.30.2020
	Description: 

	I certify that the code below is my own work.

	Exception(s): N/A

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include<iomanip>
using namespace std;
typedef vector<vector<int>> Matrix;
int matrixChainProduct(int dim[], int n, Matrix& N);
void printMatrix(Matrix& N, int n);
int main()
{
	int minNumOfMul, minNumOfMul2;
	int dim[] = { 2, 10, 50, 20 }; //Matrices BCD
	int size = sizeof(dim) / sizeof(dim[0]);
	int  n = size - 1;
	Matrix N(n, vector<int>(n, 0));
	cout << "For Matrices BCD, where B is 2x10, C is 10 x50 and D is 50x20" << endl;
	minNumOfMul=matrixChainProduct(dim, n, N);
	cout <<"The minimum number of multiplications is "<< minNumOfMul << endl;
	printMatrix(N, n);

	int dim2[] = { 10, 5, 2, 20, 12, 4, 60 };
	int size2 = sizeof(dim2) / sizeof(dim2[0]);
	int n2 = size2 - 1;
	Matrix N2(n2, vector<int>(n2, 0));
	cout << "For Matrices BCDEFG, where B is 10x5, C is 5x2, D is 2x20, E is 20x12, F is 12x4 and G is 4x60" << endl;
	minNumOfMul2= matrixChainProduct(dim2, n2, N2);
	cout <<"The minimum number of multiplications is "<< minNumOfMul2 << endl;
	printMatrix(N2, n2);
	system("pause");
	return 0;
}
int matrixChainProduct(int dim[], int n, Matrix& N)
{
	int j=0;
	for (int i = 0;i <n;i++)
	{	
			N[i][j] = 0;	
	}
	for (int b = 1;b <= n-1;b++)
	{
		for (int i=0;i <= n-b-1;i++)
		{
			j = i + b;
			N[i][j] = INT_MAX;
			for (int k = i;k <= j-1;k++)
			{
				N[i][j] = min(N[i][j], N[i][k] + N[k + 1][j] + (dim[i] * dim[k + 1] * dim[j + 1]));
			}
		}
	}
	return N[0][n - 1];
}
void printMatrix(Matrix& N, int n)
{

	cout << "Matrix: " << n << " x " << n << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout <<setw(5)<< N[i][j] <<setw(5)<< "     ";
		}
		cout << endl;
	}
}
