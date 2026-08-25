#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, divisor;

    // Input from user
    cout << "Enter data: ";
    cin >> data;

    cout << "Enter generator polynomial: ";
    cin >> divisor;

    // Append zeros to data
    string temp = data;

    for (int i = 0; i < divisor.length() - 1; i++)
    {
        temp += '0';
    }

    // Modulo-2 division
    for (int i = 0; i <= temp.length() - divisor.length(); i++)
    {
        // If current bit is 1, perform XOR
        if (temp[i] == '1')
        {
            for (int j = 0; j < divisor.length(); j++)
            {
                // XOR operation
                if (temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Get CRC remainder
    int remainderLength = divisor.length() - 1;

    string remainder =
        temp.substr(temp.length() - remainderLength);

    // Create transmitted codeword
    string codeword = data + remainder;

    cout << "\nCRC Remainder: " << remainder << endl;
    cout << "Transmitted Codeword: " << codeword << endl;

    return 0;
}