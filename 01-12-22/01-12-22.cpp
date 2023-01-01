#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static int RunThroughFile(ifstream &ptrFileHnd);

int main()
{
    cout << "Starting challenge" << endl;
    ifstream ipFIleHnd;


    ipFIleHnd.open("/home/hunti/code/AoC/01-12-22-ip.txt");
    // ipFIleHnd.open("01-12-22-ip.txt");

    if(ipFIleHnd.is_open())
    {
        cout << "File opened success" << endl;
        RunThroughFile(ipFIleHnd);


    } else {
        ipFIleHnd.close();
        cout << "File failed to open" << endl;
    }
    

    return 0;
}


static int RunThroughFile(ifstream &ptrFileHnd)
{
    int status = -1;
    string line;
    unsigned int highestCal = 0;
    unsigned int totalCal = 0;
    unsigned int highestElf = 0;
    int curIndex = 0;
    int curCal = 0;


    while(getline(ptrFileHnd, line))
    {   

        if(line.length() == 0)
        {
            // cout << "empty liine" << endl;
            curIndex += 1;
            // cout << "Elf " << curIndex << ": " << totalCal << " Calories" << endl;
            if(totalCal > highestCal)
            {
                highestCal = totalCal;
                highestElf = curIndex;
            }

            totalCal = 0;

        }else{

            curCal = stoi(line);
            totalCal += curCal;

        }



    }

    cout << "Highest Cal = " << highestCal << endl;
    cout << "Highest Elf = " <<  highestElf << endl;


    return status;
}

