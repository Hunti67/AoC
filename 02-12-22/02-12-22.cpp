#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

#define ROCK_SCORE 1
#define PAPER_SCORE 2
#define SCISSOR_SCORE 3

#define DRAW_SCORE 3
#define WIN_SCORE 6
#define LOSS_SCORE 0

// Rock    beats Scissor
// Scissor beats Paper
// Paper   beats Rock
// Same thing is a draw


// First colum == opponent play
// A == Rock
// B == Paper
// C == Scissors

// Second colum == my play
// X == Rock
// Y == Paper
// Z == Scissors

// Scoring is 1 pt Rock, 2 pt paper, 3 pt scissor for whoever wone the round playing that move
// + the score for the round,
// 0 == loss
// 3 == draw 
// 6 == win

// Strategy guide
// if they choose Rock (A)    I should choose Paper.   End with a score of 8
// if they choose Paper (B)   I should choose Rock.    End with a score of 1
// if they choose Scissor (C) I should choose Scissor. End with a score of 6

// Part 2 
// X means I need to lose
// Y means it needs to be a draw
// Z means it needs to be a win

static int ReadInput(ifstream &ptrFileHnd);
static int RockPaperScissors(char oppTurn, char userTurn);
static int RPS2(char oppTurn, char myTurn);
static char GetMyTurn(char oppTurn, char endRes);

int main()
{

    cout << "Starting challenge" << endl;
    ifstream ipFIleHnd;


    ipFIleHnd.open("/home/hunti/code/AoC/02-12-22/02-12-22-ip.txt");
    // ipFIleHnd.open("01-12-22-ip.txt");

    if(ipFIleHnd.is_open())
    {
        cout << "File opened success" << endl;
        ReadInput(ipFIleHnd);


    } else {
        ipFIleHnd.close();
        cout << "File failed to open" << endl;
    }

    return 0;
}

static inline void PrintMyTurn(char go)
{

    cout << " I Play ";

    switch(go)
    {
        case 'X':
        {
            cout << "Rock  ";
            break;
        }

        case 'Y':
        {
            cout << "Paper  ";
            break;
        }

        case 'Z':
        {
            cout << "Scissors  ";
            break;
        }

        default:
        {
            cout << "Error" << endl;
            break;
        }
    }

    cout << endl;
}

static int ReadInput(ifstream &ptrFileHnd)
{
    int status = -1;
    string line;

    unsigned int totalScore = 0;
    unsigned int score = 0;

    char *ptrLine;
    char turn = '\0';

    while(getline(ptrFileHnd, line))
    {
        if(line.length() > 0)
        {
            // score = RockPaperScissors(line[0], line[2]);
            turn = GetMyTurn(line[0], line[2]);

            // cout << "Opp " << line[0] << "  vs  " << turn << " my turn" << endl; 
            score = RPS2(line[0], turn);

            cout << "My score == " << score << endl;
            totalScore += score;
        }

    }
    cout << "Total score = " << totalScore << endl;



    return status;
}


static int RockPaperScissors(char oppTurn, char userTurn)
{
    int score = 0;


    cout << "Opp: " << oppTurn << " vs User: " << userTurn << endl;

    switch(oppTurn)
    {
        case 'A':
        {
            switch(userTurn)
            {
                case 'X':
                {
                    // Draw
                    score = ROCK_SCORE + DRAW_SCORE;
                    break;
                }
                case 'Y':
                {
                    // User wins
                    score = PAPER_SCORE + WIN_SCORE;
                    break;
                }
                case 'Z':
                {
                    // Opponent wins
                    score = SCISSOR_SCORE + LOSS_SCORE;
                    break;
                }
                default:
                {
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            break;
        }

        case 'B':
        {
            switch(userTurn)
            {
                case 'X':
                {
                    // Loss
                    score = ROCK_SCORE + LOSS_SCORE;
                    break;
                }
                case 'Y':
                {
                    // User wins
                    score = PAPER_SCORE + DRAW_SCORE;
                    break;

                }
                case 'Z':
                {
                    // Opponent wins
                    score = SCISSOR_SCORE + WIN_SCORE;
                    break;
                }
                default:
                {
                    cout << "Invalid input" << endl;
                    break;
                }
                
            }
            break;
        }
        case 'C':
        {
            switch(userTurn)
            {        
                case 'X':
                {
                    // Draw
                    score = ROCK_SCORE + WIN_SCORE;
                    break;
                }
                case 'Y':
                {
                    // User wins
                    score = PAPER_SCORE + LOSS_SCORE;
                    break;

                }
                case 'Z':
                {
                    // Opponent wins
                    score = SCISSOR_SCORE + DRAW_SCORE;
                    break;
                }
                default:
                {
                    cout << "Invalid input" << endl;
                    break;
                }
            }
            break;
        }
        default:
        {
            cout << "Invalid opp turn" << endl;
            break;
        }
        
    }

    return score;
}

static char GetMyTurn(char oppTurn, char endRes)
{
    char myTurn = '\0';

    cout << "End Res: " << endRes << "  ";

    switch(oppTurn)
    {
        case 'A':
        {
            switch(endRes)
            {
                case 'X':
                {
                    myTurn = 'C';
                    break;
                }
                case 'Y':
                {
                    myTurn = 'A';
                    break;
                }
                case 'Z':
                {
                    myTurn = 'B';
                    break;
                }
                default:
                break;
            }
            break;   
        }
        case 'B':
        {
            switch(endRes)
            {
                case 'X':
                {
                    myTurn = 'A';
                    break;
                }
                case 'Y':
                {
                    myTurn = 'B';
                    break;
                }
                case 'Z':
                {
                    myTurn = 'C';
                    break;
                }
                default:
                break;
            }
            break;
        }
        case 'C':
        {
            switch(endRes)
            {
                case 'X':
                {
                    myTurn = 'B';
                    break;
                }
                case 'Y':
                {
                    myTurn = 'C';
                    break;
                }
                case 'Z':
                {
                    myTurn = 'A';
                    break;
                }
                default:
                break;
            }
        }
        
        default:
        break;
    }

    return myTurn;
}

static inline int GetTurnScore(char turn)
{
    int score = 0;
    switch(turn)
    {
        case 'A':
        {
            score = ROCK_SCORE;
            break;
        }
        case 'B':
        {
            score = PAPER_SCORE;
            break;
        }
        case 'C':
        {
            score = SCISSOR_SCORE;
            break;
        }
        default:
        break;
    }

    return score;
}

static int RPS2(char oppTurn, char myTurn)
{
    int score = 0;

    cout << "Opp: " << oppTurn << " vs User: " << myTurn << endl;

    score += GetTurnScore(myTurn);

    if(oppTurn == myTurn)
    {
        score += DRAW_SCORE;
    }
    else if ( ((myTurn == 'A') && (oppTurn == 'C')) ||
              ((myTurn == 'B') && (oppTurn == 'A')) ||
              ((myTurn == 'C') && (oppTurn == 'B')))
    {
        score += WIN_SCORE;
    }
    else
    {
        score += LOSS_SCORE;
    }



    return score;
}


