#include <iostream>
#include "../include/filereader.hpp"
#include "../include/blacklistscan.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    const string str = "Helloo";
    const string filePath = "testfiles/hello.dmg";
    string hash = md5FromFile(filePath);
    if (hash != "")
    {  
        if (blackHashScan(hash))
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
