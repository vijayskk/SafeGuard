#include <time.h>
#include <omp.h>
#include <fstream>
#include <iostream>
using namespace std;

long timeinmsnow()
{
    auto now = chrono::system_clock::now();

    auto duration = now.time_since_epoch();

    // Convert duration to milliseconds
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(
                            duration)
                            .count();
    return milliseconds;
}

bool blackHashScan(string hash)
{
    bool state = false;
    long start = timeinmsnow();
    omp_set_num_threads(128);
    cout<<"Scanning..."<<endl;
#pragma omp parallel
    {
        char filename[20];
        sprintf(filename,"chunks/part_%d.txt",omp_get_thread_num() + 1);
        ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file! : "<<filename << std::endl;
        }
        
        string line;
        long index = 0;
        while (getline(file, line))
        {
            if (line.find(hash) != string::npos)
            {
                cout << "Found " << hash << " in line: " << index + 1 << ": '" << line << "'" << endl
                     << "took " << (timeinmsnow() - start) << " milliseconds. from file "<<filename << endl;
                state = true;
            }
            index++;
            if (state)
            {
                break;
            }
            
        }
        //cout<<"Thread "<< omp_get_thread_num() <<" completed."<<endl;
        
    }
    if (!state)
    {
        cout << endl<< "took " << (timeinmsnow() - start) << " milliseconds." << endl;
    }
    
    
    return state;
}
