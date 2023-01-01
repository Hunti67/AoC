#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


static int CalcPriority(char item);
static int SeperateCompartments(string rucksack);
static int RunThroughFile(ifstream &ptrFileHnd);
static char FindCommon(string str1, string str2);
static int PartTwo(string line);
static char FindBadgeItem(vector<string> &ptrStr);


int main()
{
    cout << "Starting challenge" << endl;
    ifstream ipFIleHnd;

    ipFIleHnd.open("/home/hunti/code/AoC/03-12-22/03-12-22-ip.txt");
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
    int curCal = 0;
    int prioritySum = 0;


    while(getline(ptrFileHnd, line))
    {   
        if(line.length() > 0)
        {
            // Part one
            // prioritySum += SeperateCompartments(line);

            // Part two
            prioritySum += PartTwo(line);


        }
    }


    cout << "Priority Sum = " << prioritySum << endl;

    return 0;
}

static int SeperateCompartments(string rucksack)
{
    int length = 0;
    string com1 = rucksack.substr(0, rucksack.length()/2);
    string com2 = rucksack.substr(rucksack.length()/2);
    char common = '\0';
    unsigned int priority = 0;

    cout << "Compartment 1 = " << setw(30) << left << com1 << "  :  " << "Compartment 2 = " << com2 << endl;

    common = FindCommon(com1, com2);

    cout << "Common = " << common << endl;

    
    priority = CalcPriority(common);




    return priority;
}

static char FindCommon(string str1, string str2)
{
    string::iterator it;
    char common = '\0';

    for(int j = 0; j < str1.length(); j++)
    {
        for(int i = 0; i < str2.length(); i++)
        {
            if(str1[j] == str2[i])
            {
                // cout << str1[j] << " Is common" << endl;
                common = str1[j];
                break;
            }
        }
        if(common != '\0')
        {
            break;
        }
    }

    return common;
}


static int CalcPriority(char item)
{
    int priority = 0;
    unsigned int scratch = 0;

    if(item < 'a')
    {
        // Capital
        priority = ((int)item - 64) + 26;
    }else{
        // lower case
        priority = (int)item - 96;
    }

    cout << "Priority = " << priority << endl;

    return priority;
}


static int PartTwo(string line)
{
    static unsigned int count = 1;
    static vector<string> elfGroup;
    char item = '\0';
    int priority = 0;

    elfGroup.push_back(line);

    if((count++ % 3) == 0)
    {
        cout << "Group of elves : " << count << endl;
        item = FindBadgeItem(elfGroup);
        cout << "Common Item == " << item << endl;
        elfGroup.clear();

        if(item != '\0')
        {
            priority = CalcPriority(item);
        }

    }



    return priority;
}

static char FindBadgeItem(vector<string> &ptrStr)
{
    char item = '\0';
    int longestItem = 0;
    string::iterator it, it1, it2;
    
 
        // cout << "Elf No " << " Rucksack: " << ptrStr[0] << endl;

    for(int i = 1; i < 3; i++)
    {
        for(it1 = ptrStr[0].begin(); it1 < ptrStr[0].end(); it1++)
        {
            for(it = ptrStr[1].begin(); it < ptrStr[1].end(); it++)
            {
                if((*it1) == (*it))
                {
                    for(it2 = ptrStr[2].begin(); it2 < ptrStr[2].end(); it2++)
                    {
                        if((*it1) == (*it2))
                        {
                            item = (char)(*it);
                        }
                    }
                }
            }
        }
    }

    return item;
}