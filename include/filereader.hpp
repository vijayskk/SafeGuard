#include "openssl/md5.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


char * convertIntToHex(int num)
{
    char *hexval = new char[2];
    for (int i = 0; i < 2; i++)
    {
        int temp = num % 16;
        if (temp < 10)
        {
            hexval[1 - i] = temp + 48;
        }
        else if (temp >= 10)
        {
            hexval[1 - i] = (temp - 10) + 97;
        }
        num /= 16;
    }
    return hexval;
}


string md5FromFile(const string &filepath)
{
    ifstream file(filepath, ios::in | ios::binary | ios::ate); // Initializing file stream
    long filesize = 0;

    if (!file.is_open())
    {
        cerr << "Error opening " << filepath << endl;
        return 0;
    }
    else
    {
        filesize = file.tellg(); // Reading filesize
        cout << "File read successfull : " << filepath << endl
             << "File size : " << filesize / 1000000 << " MBytes" << endl;
    }

    char * memBlock = new char[filesize];
    file.seekg(0, ios::beg);
    file.read(memBlock, filesize);
    file.close();

    unsigned char md5_result[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)memBlock, filesize, md5_result);
    string output = "";
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        output.append(convertIntToHex((int)md5_result[i]));
    }
    delete[] memBlock;
    return output;
}