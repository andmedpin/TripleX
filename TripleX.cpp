#include <iostream>
#include <ctime>

void PlayIntroduction(int Difficulty)
{   
    std::cout << std::endl;
    
    std::cout << "                     ____ ____ ____ ____ ____ ____ ____                           \n";
    std::cout << "                    ||T |||r |||i |||p |||l |||e |||X ||                          \n";
    std::cout << "                    ||__|||__|||__|||__|||__|||__|||__||                          \n";
    std::cout << "                    |/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|                          \n";

    std::cout << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    std::cout << "*                                                                               *\n"; 
    std::cout << "*                                                                               *\n"; 
    // cout means caracter output, angled brackets (<<) are the insertion operator  
    std::cout << "*      You're a secret agent trying to break into a level " << Difficulty << " secure server room. * \n";
    std::cout << "*      You will need to enter the correct codes to continue...                  * \n";
    std::cout << "*                                                                               *\n"; 
    std::cout << "*                                                                               *\n"; 
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";

   
}

bool PlayGame(int LevelDifficulty, int MaxDifficulty)
{  
    PlayIntroduction(LevelDifficulty);
    // Variable Declarations
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeMult = CodeA * CodeB * CodeC;
    
    // Print Instructions to the Terminal
    // Print Mult and Sum to the Terminal
    std::cout<< "\n - There are 3 numbers in the code";
    std::cout<< "\n - The Codes Add-Up to: " << CodeSum;
    std::cout<< "\n - The Codes Multiply to: " << CodeMult << std:: endl;
    
    int GuessA, GuessB, GuessC;

    // Store Players guess
    // cin means caracter input, angled brackets (>>) are the extraction operator
    std:: cout << std:: endl;
    std::cin>> GuessA >> GuessB >> GuessC;
    std:: cout << std:: endl;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessMult = GuessA * GuessB * GuessC;
    
    // Using if statement to compare the Guess and the Code 
    if (GuessSum == CodeSum && GuessMult == CodeMult)
    {
        if (LevelDifficulty == (MaxDifficulty - 1))
        {
            std::cout << "Great, now onto the last level...";
        }
        else
        {
            std::cout << "Level "<< LevelDifficulty << " hacked.";
        }

        return true;
    }
    else 
    { 
        std::cout << "Those are not the right numbers!"; 
        return false; 
    }


    std::cout << std::endl;
}

void PLayEndMessage()
{
    std::cout << std::endl << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    std::cout << "*                                                                               *\n"; 
    std::cout << "*                                                                               *\n"; 
    std::cout << "*      Congrats, you're in...                                                   *\n";
    std::cout << "*      You've stole the nuclear codes and now you can detonate the bombs.       *\n";
    std::cout << "*                                                                               *\n"; 
    std::cout << "*                                                                               *\n"; 
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
}

int main() 
{
    //Seeding Random Num Generator using the Computer's time
    srand(time(NULL));

    const int MaxDifficulty = 3;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxDifficulty) //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            //Increase Level Difficulty
            ++LevelDifficulty;
        }
        
    }

    PLayEndMessage();

    return 0;
}

/*
g++ TripleX.cpp -o TripleX
./TripleX
*/