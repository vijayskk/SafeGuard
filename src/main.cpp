#include <iostream>
#include "../include/filereader.hpp"
#include "../include/blacklistscan.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    const string str = "Helloo";
    const string filePath = "testfiles/movie.mkv";
    const string listpath = "lists/testlist2.txt";
    string hash = md5FromFile(filePath);
    if (hash != "")
    {  
        if (blackHashScan(hash,listpath))
        {
            cout<<"Threat found!!!"<<endl;
        }else{
            cout<<"No threat found"<<endl;
        }
    }else{
        cout<<"Scan Failed!!"<<endl;
    }
    
    
    return 0;
}