#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

long timeinmsnow(){
    auto now = chrono::system_clock::now();

    auto duration = now.time_since_epoch();

    // Convert duration to milliseconds
    auto milliseconds
        = chrono::duration_cast<chrono::milliseconds>(
              duration)
              .count();
    return milliseconds;
}

bool blackHashScan(string hash, string hashfile)
{
    ifstream file(hashfile);
    if (!file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    cout<<"Scanning..."<<endl;
    long start = timeinmsnow();
    string line;
    long index = 1;
    while (getline(file,line))
    {        
        if (line.find(hash) != string::npos)
        {
            cout<<"Found "<<hash<<" in line: "<<index<<": '"<<line<<"'"<<endl<< "took "<<(timeinmsnow()-start)<<" milliseconds."<<endl;
            return true;

        } 
        index++;
    }
    cout<<endl<< "took "<<(timeinmsnow()-start)<<" milliseconds."<<endl;
    return false;
}
