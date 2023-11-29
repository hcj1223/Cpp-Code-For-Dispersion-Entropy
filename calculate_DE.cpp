#include <bits/stdc++.h>
using namespace std;

double normalCDF(double value); // 计算NCDF
double Dispn(vector<double> &x, int c, int m, int d);

int main()
{
    // 从文件中读取向量
    vector<double> x;
    ifstream inputFile("signal01.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file.\n";
        return 1;
    }
    double value;
    while (inputFile >> value)
        x.push_back(value);
    inputFile.close();

    cout << "C++ Results:" << endl;
    cout << "Dispersion Entropy (Dispx): " << Dispn(x, 3, 2, 1) << endl;
    cout << "Reverse Dispersion Entropy (RDE): " << Dispn(x, 3, 2, 1) / pow(3, 2) << endl;
    return 0;
}

double normalCDF(double value)
{
    return 0.5 * erfc(-value * M_SQRT1_2);
}
double Dispn(vector<double> &x, int c, int m, int d)
{
    vector<double> z;
    for (int i = 0; i < x.size(); i++)
        z.push_back(round(normalCDF(x[i]) * c + 0.5));

    vector<vector<double>> zmc;
    for (int i = 0; i < x.size() - (m - 1) * d; i++)
    {
        vector<double> t;
        for (int j = i; j <= i + (m - 1) * d; j += d)
            t.push_back(z[j]);
        zmc.push_back(t);
    }

    map<vector<double>, double> mp;
    for (int i = 0; i < x.size() - (m - 1) * d; i++)
        mp[zmc[i]] += 1;

    vector<double> p;
    for (auto it = mp.begin(); it != mp.end(); it++)
        p.push_back(it->second / (x.size() - (m - 1) * d));

    double DE = 0;
    for (int i = 0; i < p.size(); i++)
        DE -= p[i] * log(p[i]);

    return DE;
}