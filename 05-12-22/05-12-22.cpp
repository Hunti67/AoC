#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#define PART_ONE
// #define PART_TWO

using namespace std;

static const string date = "05-12-22";
static const string filename = "/home/hunti/code/AoC/" + date + "/" + date + "-ip.txt";

static int RunThroughFile(ifstream &ptrFileHnd);


int main()
{
    cout << "Starting challenge " << date << endl;
    ifstream ipFileHnd;

    ipFileHnd.open(filename);

    if(ipFileHnd.is_open())
    {
        cout << "File opened success" << endl;
        RunThroughFile(ipFileHnd);

    } else {
        ipFileHnd.close();
        cout << "File failed to open" << endl;
    }

    return 0;
}


static int RunThroughFile(ifstream &ptrFileHnd)
{
    int status = -1;
    int answer = 0;
    int total = 0;
    string line;

     while(getline(ptrFileHnd, line))
    {   
        if(line.length() > 0)
        {          
            
        }
    }

    cout << "Answer = " << answer << endl;

    return status;
}