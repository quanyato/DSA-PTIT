// Hợp và giao của 2 dãy số _ 1
// Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau. Các phần tử
// của mảng A[] và B[] đã được sắp xếp. Hãy tìm mảng hợp và giao được sắp
// giữa A[] và B[]. Ví dụ với A[] = {1, 3, 4, 5, 7}, B[]={2, 3, 5, 6} ta có
// mảng hợp Union = {1, 2, 3, 4, 5, 6, 7}, mảng giao Intersection = {3, 5}.
// In ra đáp án theo giá trị phần tử từ nhỏ đến lớn.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu
// tiên đưa vào n, m là số phần tử của mảng A[] và B[]; dòng tiếp theo là
// n số A [i] của mảng A [];dòng tiếp theo là m số B[i] của mảng B[]; các
// số được viết cách nhau một vài khoảng trống.
// T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m, A[i], B[i] ≤105.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input:				Output:
// 1					1 2 3 4 5
// 5 3					1 2 3
// 1 2 3 4 5
// 1 2 3

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100000], b[100000];
vector<int> unionArray;
vector<int> intersection;

void init()
{
	unionArray.clear();
	intersection.clear();
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
}

void print_Union()
{
	int numOfUnion = unionArray.size();
	for (int i = 0; i < numOfUnion; ++i)
	{
		cout << unionArray[i] << " ";
	}
	cout << endl;
}
void print_intersection()
{
	int numOfIntersection = intersection.size();
	for (int i = 0; i < numOfIntersection; ++i)
	{
		cout << intersection[i] << " ";
	}
	cout << endl;
}

void merge_n_push()
{
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			unionArray.push_back(a[i]);
			++i;
		}
		else if (b[j] < a[i])
		{
			unionArray.push_back(b[j]);
			++j;
		}
		else
		{
			unionArray.push_back(a[i]);
			intersection.push_back(a[i]);
			++i;
			++j;
		}
	}
	while (i < n)
	{
		unionArray.push_back(a[i]);
		++i;
	}
	while (j < m)
	{
		unionArray.push_back(b[j]);
		++j;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
		merge_n_push();
		print_Union();
		print_intersection();
	}
}
