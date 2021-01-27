#include <iostream>
#include <ctime>

void PrintASCIIArt() 
{

    std::cout << "\n        ....                             \n";
    std::cout << "    ,od88888bo.                            \n";
    std::cout << "    ,d88888888888b                         \n";
    std::cout << "    ,dP\"\"'   `\"Y888b       ,.           \n";
    std::cout << "    d'         `\"Y88b     .d8b. ,         \n";
    std::cout << "    '            `Y88[  , `Y8P' db         \n";
    std::cout << "                  `88b  Ybo,`',d88)        \n";
    std::cout << "                   ]88[ `Y888888P\"        \n";  
    std::cout << "                  ,888)  `Y8888P'          \n";
    std::cout << "                 ,d888[    `\"\"'          \n";
    std::cout << "              .od8888P          ...        \n";
    std::cout << "         ..od88888888bo,      .d888b       \n";
    std::cout << "              `\"\"Y888888bo. .d888888b    \n";
    std::cout << "    .             `Y88b\"Y88888P\"' `Y8b   \n";
    std::cout << "    :.             `Y88[ `\"\"\"'     `88[ \n";
    std::cout << "    |b              |88b            Y8b.   \n";
    std::cout << "    `8[             :888[ ,         :88)   \n";
    std::cout << "    Yb              :888) `b.       d8P'   \n";
    std::cout << "    `8b.           ,d888[  `Ybo.  .d88[    \n";
    std::cout << "    Y8b.         .dWARP'   `Y8888888P      \n";
    std::cout << "    `Y88bo.   .od8888P'      \"YWARP'      \n";
    std::cout << "    `\"Y8888888888P\"'           `\"'      \n";
    std::cout << "        `\"Y8888P\"\"'                     \n";
    std::cout << "            `""'                           \n"; // warp.tmt.1997

}

void PrintIntroduction(int Difficulty) 
{
    // PrintASCIIArt();

    // Introduction
    if (Difficulty == 1)
    {
        std::cout << "\nYou are an explorer, attempting to retrieve a treasure from the tomb of Chandra Gupta I. The entrance wall has an inscription:\n\n";
        std::cout << "\"The treasure will be kept from those not worthy of my knowledge.\n";
        std::cout << "Complete this trial and I you will be one step closer to the truth... but fail and suffer the consequences.\"\n\n";

        std::cout << "You enter the tomb confident of your abilities and encounter a large room.\n\n";
    }

    std::cout << "There is a number carved in the floor of this room: " << Difficulty << "\n\n";

    std::cout << "The farthest wall has 3 empty spaces and numbered tiles are scattered in the ground. To the right of the empty spaces there are less ominous inscriptions:\n";
}

bool PlayGame(int Difficulty, int MaxDifficulty) 
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    
    const int CodeA = rand() % (Difficulty + 1) + Difficulty;
    const int CodeB = rand() % (Difficulty + 1) + Difficulty;
    const int CodeC = rand() % (Difficulty + 1) + Difficulty;

    // Compute and declare sum and products
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Show messages with hints about the numbers
    std::cout << ">> The sum of the numbers is " << CodeSum << ".\n";
    std::cout << ">> The product of the numbers is " << CodeProduct << ".\n\n";

    // Store player's guesses
    int GuessA, GuessB, GuessC;
    std::cout << "Insert the 3 tiles: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    // Feedback to user
    std::cout << "\nIn the wall there are three tiles: " << GuessA << " " << GuessB << " " << GuessC;

    // GuessSum and GuessProduct 
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\nThe room starts to rumble and a secret door opens on the wall. You survived this trial!\n";
        
        if (Difficulty < MaxDifficulty)
        {
            std::cout << "You cross the secret door to find another room, exactly like the one you were in.\n\n";
        }        
        
        return true;
    } 

    else
    {
        std::cout << "\n\nThe room starts to rumble and the floor collapses as you tried to run to the exit. The king has claimed yet another victim of greed...\n\n";
        return false;
    }
}

// Main function
int main() 
{   
    srand(time(NULL));

    int LevelDifficulty = 1;
    int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) {

        bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore();  // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "You crossed the last secret door to find the tomb of King Chandra Gupta I. Above the tomb there is a message written in paper:\n\n";
    std::cout << "\"Sorry mate, I got here before. If you wish to find the treasure come for me.\n\n";
    std::cout << "Yours,\n";
    std::cout << "  The Llama.\"\n\n";

    return 0;
}