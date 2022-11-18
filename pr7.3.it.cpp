#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Input(int** a, const int n);
void Print(int** a, const int n);
void CountLocMinCenter(int** a, const int n, int& count);
void CountLocMinFrameH(int** a, const int n, int& count);
void CountLocMinVert(int** a, const int n, int& count);
void CountLocMinHoriz(int** a, const int n, int& count);
int SumAbsDiag(int** a, const int n, int& sum);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int n;
	int sum = 0;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	//Input(a, n);
	Print(a, n);
	int count = 0;
	int suma = SumAbsDiag(a, n, sum);
	CountLocMinCenter(a, n, count);
	CountLocMinFrameH(a, n, count);
	CountLocMinVert(a, n, count);
	CountLocMinHoriz(a, n, count);
	cout << "Sum = " << suma << endl;
	cout << "Count = " << count;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			a[i][j] = Low + rand() % (High - Low + 1);
		}
}

void Input(int** a, const int n)
{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}

void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int SumAbsDiag(int** a, const int n, int& sum) 
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			sum += abs(a[i][j]);
		}			
	}
	return sum;
}

void CountLocMinFrameH(int** a, const int n, int& count)
{
	if ((a[0][0] < a[0][1]) && (a[0][0] < a[1][0]) && (a[0][0] < a[1][1]))
		count++;
	if ((a[0][n-1] < a[0][n-2]) && (a[0][n-1] < a[1][n-1]) && (a[0][n-1] < a[1][n-2]))
		count++;
	if ((a[n-1][0] < a[n-2][0]) && (a[n-1][0] < a[n-1][1]) && (a[n-1][0] < a[n-2][1]))
		count++;
	if ((a[n-1][n-1] < a[n-1][n-2]) && (a[n-1][n-1] < a[n-2][n-1]) && (a[n-1][n-1] < a[n-2][n-2]))
		count++;
		
}

void CountLocMinVert(int** a, const int n, int& count)
{
	for (int i = 1; i < n - 1; i++) {
		if ((a[i][0] < a[i - 1][1]) && (a[i][0] < a[i][1]) && (a[i][0] < a[i + 1][1]) && (a[i][0] < a[i - 1][0]) && (a[i][0] < a[i + 1][0]))
		count++;
		if ((a[i][n - 1] < a[i - 1][n - 2]) && (a[i][n - 1] < a[i][n - 2]) && (a[i][n - 1] < a[i + 1][n - 2]) && (a[i][n - 1] < a[i + 1][n - 1]) && (a[i][n - 1] < a[i - 1][n - 1]))
			count++;
	}
}

void CountLocMinHoriz(int** a, const int n, int& count)
{
	for (int j = 1; j < n - 1; j++) {
		if ((a[0][j] < a[1][j - 1]) && (a[0][j] < a[1][j]) && (a[0][j] < a[1][j + 1]) && (a[0][j] < a[0][j + 1]) && (a[0][j] < a[0][j - 1]))
			count++;
		if ((a[n - 1][j] < a[n - 2][j - 1]) && (a[n - 1][j] < a[n - 2][j]) && (a[n - 1][j] < a[n - 2][j + 1]) && (a[n - 1][j] < a[n - 1][j + 1]) && (a[n - 1][j] < a[n - 1][j - 1]))
			count++;
	}
}

void CountLocMinCenter(int** a, const int n, int& count) 
{
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (a[i][j] < a[i - 1][j] &&
				a[i][j] < a[i + 1][j] &&
				a[i][j] < a[i][j - 1] &&
				a[i][j] < a[i][j + 1] &&
				a[i][j] < a[i - 1][j - 1] &&
				a[i][j] < a[i + 1][j - 1] &&
				a[i][j] < a[i - 1][j + 1] &&
				a[i][j] < a[i + 1][j + 1] )
				count++;
		}
	}
}
