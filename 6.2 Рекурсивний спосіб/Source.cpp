#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Max(int* a, const int size, int i, int max)
{
	if (a[i] > max)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, i + 1, max);
	else
		return max;
}
int Min(int* a, const int size, int i, int min)
{
	if (a[i] < min)
		min = a[i];
	if (i < size - 1)
		return Min(a, size, i + 1, min);
	else
		return min;
}


int Sum(int* a, const int size, int i, int S)
{
	S += a[i];
	if (i < size - 1)
		return Sum(a, size, i + 1, S);
	else
		return S;
}
int main()
{

	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 26;
	int a[n];
	int Low = -40;
	int High = 20;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "max = " << Max(a, n, 1, a[0]) << endl;
	cout << "S = " << Sum(a, n, 0,0) << endl;
	cout << "min = " << Min(a, n, 1, a[0]) << endl;
	return 0;
}