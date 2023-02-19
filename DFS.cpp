#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix;
string filePath = "C:\\Users\\YATO\\OneDrive - ptit.edu.vn\\Documents\\Dev\\PTIT\\TRR2\\input001.in";

void getN_fromFile(string filePath)
{
    fstream inputFile;
    inputFile.open(filePath, ios::in);
    inputFile >> n;
    inputFile.close();
}

void getMatrix_fromFile(string filePath)
{
    int temp;
    fstream inputFile;
    inputFile.open(filePath, ios::in);
    inputFile >> n;
    matrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> temp;
            matrix[i].push_back(temp);
        }
    }
    inputFile.close();
}

int main()
{
    getN_fromFile(filePath);
    getMatrix_fromFile(filePath);
    
}