#include <iostream>
#include <fstream>
#include <string>


#define PART_ONE
// #define PART_TWO

using namespace std;

static const string date = "04-12-22";
static const string filename = "/home/hunti/code/AoC/" + date + "/" + date + "-ip.txt";

static int RunThroughFile(ifstream &ptrFileHnd);


int main()
{
    cout << "Starting challenge" << endl;
    ifstream ipFileHnd;

    // ipFIleHnd.open("/home/hunti/code/AoC/03-12-22/03-12-22-ip.txt");
    ipFileHnd.open(filename);
    // ipFIleHnd.open("01-12-22-ip.txt");

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