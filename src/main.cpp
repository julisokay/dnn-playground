//
// Created by Jul on 09.04.2023.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int convert_big_endian(const uint_fast8_t bytes[4]);

int main () {
    string line;
    ifstream myFile ("../data/train-images.idx3-ubyte", ios::in | ios::binary);

    if (myFile.is_open ())
    {
        ::uint_fast8_t bytes[16];
        myFile.read((char*) bytes, 16);
        int magicNumber = convert_big_endian(bytes);
        int n = convert_big_endian(bytes + 4);
        int rows = convert_big_endian(bytes + 8);
        int cols = convert_big_endian(bytes + 12);
        cout << "magicNumber = " << magicNumber << "\nn = " << n << "\nrows = " << rows << "\ncols = " << cols << "\n";
        for (int i = 0; i < n; i++) {

        }
        myFile.close();
    }
    else cout << "Unable to open file";

    return 0;
}

int convert_big_endian(const uint_fast8_t *bytes)
{
    return bytes[3] | (bytes[2] << 8) | (bytes[1] << 16) | (bytes[0] << 24);
}