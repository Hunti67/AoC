#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// #define PART_ONE
#define PART_TWO
using namespace std;

static const string date = "04-12-22";

static const string filename = "/home/hunti/code/AoC/" + date + "/" + date + "-ip.txt";



static int RunThroughFile(ifstream &ptrFileHnd);
static int FindOverlap(string line);
static int GetNumSections(string elf);
// static int CheckSections(string large, string small);
static int CheckSections(int pLargeBuff[], int pSmallBuff[]);
static void PrintSection(string section);
static int CheckStartPos(string line);
static int ExtractSections(string line, int pBuff[]);

/**
 * Need to find out how many elves fully overlap the paired elfs job.
 * Every section has a unique id number. and each elf is assigned a seciton.
 * 
 * check which elf has more sections
 * check if the first section for the less worked elf
 * check the last section for the less worked elf is within the more worked elf
*/


int main()
{
    cout << "Starting challenge " << date << endl;
    ifstream ipFIleHnd;


    // ipFIleHnd.open("/home/hunti/code/AoC/04-12-22/04-12-22-ip.txt");
    ipFIleHnd.open(filename);
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
    int total = 0;
    string line;

     while(getline(ptrFileHnd, line))
    {   
        if(line.length() > 0)
        {
            // Part one
            if(FindOverlap(line) == 1)
            {
                total += 1;
            }

            
            
        }
    }
    cout << "Total number of overlaps = " << total << endl;


    return status;
}

static int FindOverlap(string line)
{
    int num = 0;
    string elf1 = line.substr(0, line.find(','));
    string elf2 = line.substr(line.find(',') + 1);

    int elves[2][2] = {{0,0}, {0,0}};

    ExtractSections(elf1, &elves[0][0]);
    ExtractSections(elf2, &elves[1][0]);

    cout << "Elf 1: " << elf1 << "  Elf 2: " << elf2 << endl;

    int elf1span = GetNumSections(elf1);
    int elf2span = GetNumSections(elf2);



    // cout << "Elf 1 span = " << elf1span << " vs Elf 2 Span = " << elf2span << endl; 

#ifdef PART_TWO
    num = CheckSections(&elves[0][0], &elves[1][0]);
#endif

#ifdef PART_ONE

    if(elf1span > elf2span)
    {
        cout << "Elf 1 has larger span" << endl;
        // num = CheckSections(elf1, elf2);
        num = CheckSections(&elves[0][0], &elves[1][0]);

    }else if (elf2span > elf1span){
        cout << "Elf 2 has larger span" << endl;
        // num = CheckSections(elf2, elf1);
        num = CheckSections(&elves[1][0], &elves[0][0]);

    }else{
        // cout << "Elves have same span" << endl;
        // If number of sections are the same but start positions are different then no overlap
        if( (elves[0][0]) == (elves[1][0]))
        {
            num = 1;    
        }

    }
#endif

    return num;
}


static int GetNumSections(string elf)
{
    int num = 0;
    int buff[2] = {0,0};
    string starts = elf.substr(0, elf.find('-'));
    int start = stoi(starts);
    
    string ends = elf.substr(elf.find('-')+1);
    
    int end = stoi(ends);

    ExtractSections(elf, &buff[0]);
    end = buff[1];
    start = buff[0];
    
    // cout << "End " << end << "  vs Start " << start ;
    // cout << "  End " << buff[1] << "  vs Start " << buff[0];
    num = end - start;
    // cout << "  Diff = " << num << endl;

    return num;
}


// static int CheckSections(string large, string small)
static int CheckSections(int pLargeBuff[], int pSmallBuff[])
{
    int overlap = 0;
    // int startL = stoi(&large[0]);
    // int startS = stoi(&small[0]);
    // int endL   = stoi(&large[3]);
    // int endS   = stoi(&small[3]);

    // if((startS >= startL) && (endS <= endL))

#ifdef PART_ONE
    if((pSmallBuff[0] >= pLargeBuff[0]) && (pSmallBuff[1] <= pLargeBuff[1]))
    {
        cout << "Complete Overlap" << endl;
        
        overlap = 1;
    }
#endif
#ifdef PART_TWO

    if(pSmallBuff[0] == pLargeBuff[0])
    {
        overlap = 1;
    }
    else if(pSmallBuff[0] <= pLargeBuff[0]) // Start of 1 < Start of 2?
    {
        if(pSmallBuff[1] >= pLargeBuff[0]) // End of 1 > Start of 2?
        {
            overlap = 1;
        }
    }else{
        // Start of 1 > Start of 2
        if(pSmallBuff[0] <= pLargeBuff[1])
        {
            overlap = 1;
        }
    }

    if(overlap == 1)
    {
        cout << "Overlap " << endl;
    }
    
    

#endif
    
    


    return overlap;
}

static void PrintSection(string section)
{
    int start = stoi(&section[0]);
    int end = stoi(&section[3]);


    for(int i = start; i < end; i++)
    {
        cout << i << ". ";
    }
    cout << endl;


}

static int CheckStartPos(string line)
{
    int status = 0;
    



    return status;
}

static int ExtractSections(string line, int pBuff[])
{
    int status = 0;
    string starts = line.substr(0, line.find('-'));
    string ends = line.substr(line.find('-') + 1);
    int start = stoi(starts);
    int end = stoi(ends);

    pBuff[0] = start;
    pBuff[1] = end;


    return status;
}