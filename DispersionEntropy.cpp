#include <bits/stdc++.h>
using namespace std;

double normalCDF(double value); // 计算NCDF
double Dispn(vector<double> &x, int c, int m, int d);

int main()
{
    // 从文件中读取向量
    vector<double> x;
    ifstream inputFile("TestData.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file.\n";
        return 1;
    }
    double value;
    while (inputFile >> value)
        x.push_back(value);
    inputFile.close();

    int c, m, d;
    cout << "Please enter ..." << endl;
    cout << "c = ";
    cin >> c;
    cout << "m = ";
    cin >> m;
    cout << "d = ";
    cin >> d;

    cout << "C++ Results:" << endl;
    cout << "Dispersion Entropy (Dispx): " << Dispn(x, c, m, d) << endl;
    cout << "Reverse Dispersion Entropy (RDE): " << Dispn(x, c, m, d) / pow(c, m) << endl;
    return 0;
}

// 步骤（1）计算NCDF
double normalCDF(double value)
{
    return 0.5 * erfc(-value * M_SQRT1_2);
}
double Dispn(vector<double> &x, int c, int m, int d)
{
    // 步骤（1）映射到c个类
    vector<double> z;
    for (int i = 0; i < x.size(); i++)
        z.push_back(round(normalCDF(x[i]) * c + 0.5));

    // 步骤（2）映射为一个分散模式
    vector<vector<double>> zmc;
    for (int i = 0; i < x.size() - (m - 1) * d; i++)
    {
        vector<double> t;
        for (int j = i; j <= i + (m - 1) * d; j += d)
            t.push_back(z[j]);
        zmc.push_back(t);
    }

    // 步骤（3）求出相对频率
    map<vector<double>, double> mp;
    for (int i = 0; i < x.size() - (m - 1) * d; i++)
        mp[zmc[i]] += 1;

    vector<double> p;
    for (auto it = mp.begin(); it != mp.end(); it++)
        p.push_back(it->second / (x.size() - (m - 1) * d));

    // 步骤（4）得出结果
    double DE = 0;
    for (int i = 0; i < p.size(); i++)
        DE -= p[i] * log(p[i]);

    return DE;
}