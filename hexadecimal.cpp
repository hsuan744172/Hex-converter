#include"bits/stdc++.h"
using namespace std;

string integer(int n, int base)
{
    if (n == 0)
    {
        return "0";
    }

    string new_num = "";
    while (n > 0)
    {
        new_num = to_string(n % base) +' '+ new_num;
        n /= base;
    }

    return new_num;
}

string fractional(double n, int base)
{
    if (n == 0.0)
    {
        return "0";
    }

    string new_num = ".";
    int maxIterations = 64; // 小數點後64位
    while (n > 0 && maxIterations-- > 0)
    {
        n *= base;
        int digit = static_cast<int>(floor(n));
        new_num += ' ' + to_string(digit);
        if (n >= 1)
        {
            n -= digit;
        }
    }

    return new_num;
} 
int main()
{
    ofstream outfile("output.txt", ios::app);
    string number;
    cout << "Input number:";
    cin >> number;
    outfile <<number<<endl;
    int base;
    cout << "Input base:";
    while(cin >> base && base!=0){
        
        vector<string> tokens;
        string part;

        if (number.find(".") == string::npos)
        {
            int integerPart = stoi(number);
            cout << integer(integerPart, base) << endl;
            outfile << integer(integerPart, base)<<endl;
        }
        else
        {
            for (char i : number)
            {
                if (i == '.')
                {
                    tokens.push_back(part);
                    part.clear();
                }
                else
                {
                    part.push_back(i);
                }
            }
            tokens.push_back(part);

            int integerPart = stoi(tokens[0]);
            double fractionalPart = stod("0." + tokens[1]);
            cout << integer(integerPart, base) + fractional(fractionalPart, base) << endl;
            outfile<<integer(integerPart, base) + fractional(fractionalPart, base) << endl;
        }
        cout << "Input base:";
    }
    outfile.close();
}
