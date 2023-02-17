// Thu nghiem cac thuat toan sap xep

#include <bits/stdc++.h>
using namespace std;

// Insertion sort algorithm
void insertSort(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}

// Quick sort algorithm
void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}
int partition(int a[], int l, int r)
{
    int x = a[r], i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r], a[i + 1]);
    return i + 1;
}

// merge sort algorithm
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

int main()
{
    int n = 9, a[10] = {20, 2, 9, 7, 12, 15, 1, 6, 8};

    // insertSort(a, 0, n - 1);
    quickSort(a, 0, n - 1);
    // mergeSort(a, 0, n - 1);

    cout << "Mang da sap xep:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}