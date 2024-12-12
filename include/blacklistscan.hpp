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
    long start = timeinmsnow();
    omp_set_num_threads(16);
#pragma omp parallel
    {
        char filename[20];
        sprintf(filename,"chunks/part_%d.txt",omp_get_thread_num() - 1 )
        ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }
        
        string line;
        while (getline(file, line))
        {
            if (line.find(hash) != string::npos)
            {
                cout << "Found " << hash << " in line: " << index << ": '" << line << "'" << endl
                     << "took " << (timeinmsnow() - start) << " milliseconds. from thread "<<omp_get_thread_num() << endl;
                return true;
            }
        }
    }

    cout << endl
         << "took " << (timeinmsnow() - start) << " milliseconds." << endl;
    return false;
}
