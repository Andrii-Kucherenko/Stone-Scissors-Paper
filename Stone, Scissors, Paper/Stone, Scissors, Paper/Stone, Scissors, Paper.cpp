//Stone, Scissors, Paper
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

enum class Options
{
    STONE = 1,
    SCISSORS = 2,
    PAPER = 3,
    MAX_OPTIONS = 3
};

std::string getOptions(const Options op)
{
    switch (op)
    {
    case Options::STONE:
        return "stone";

    case Options::SCISSORS:
        return "scissors";

    case Options::PAPER:
        return "paper";
    }
}

int main()
{
    srand(time(0));

    std::string playMore;

    do
    {
        system("cls");
        std::cout << "\t\t\t***Stone, Scissors, Paper***\n\n";

        int playersChoice;
        int computersChoice;

        computersChoice = rand() % static_cast<int>(Options::MAX_OPTIONS) + 1;
        bool isCorrect;
        std::string sPlayerChoice;

        do
        {
            std::cout << "The computer made its choice. \nMake and enter your choice (1 - stone, 2 - scissors, 3 - paper): ";
            std::getline(std::cin, sPlayerChoice);

            if (sPlayerChoice != "1" && sPlayerChoice != "2" && sPlayerChoice != "3")
            {
                std::cout << "\nIncorrect input! Try again.\n\n";
            }

        } while (sPlayerChoice != "1" && sPlayerChoice != "2" && sPlayerChoice != "3");

        std::stringstream ssPlayerChoice;
        ssPlayerChoice << sPlayerChoice;
        ssPlayerChoice >> playersChoice;

        if (playersChoice == computersChoice)
        {
            std::cout << "\nDraw! And you and the computer choose " << getOptions(static_cast<Options>(playersChoice)) << ".\n\n";
        }
        else if (static_cast<Options>(playersChoice) == Options::STONE)
        {
            if (static_cast<Options>(computersChoice) == Options::SCISSORS)
            {
                std::cout << "\nYou have " << getOptions(static_cast<Options>(playersChoice)) << " and the computer has " << getOptions(static_cast<Options>(computersChoice)) << ". You win!\n\n";
            }
            else
            {
                std::cout << "\nYou have " << getOptions(static_cast<Options>(playersChoice)) << " and the computer has " << getOptions(static_cast<Options>(computersChoice)) << ". You lose!\n\n";
            }
        }
        else if (static_cast<Options>(playersChoice) == Options::SCISSORS)
        {
            if (static_cast<Options>(computersChoice) == Options::PAPER)
            {
                std::cout << "\nYou have " << getOptions(static_cast<Options>(playersChoice)) << " and the computer has " << getOptions(static_cast<Options>(computersChoice)) << ". You win!\n\n";
            }
            else
            {
                std::cout << "\nYou have " << getOptions(static_cast<Options>(playersChoice)) << " and the computer has " << getOptions(static_cast<Options>(computersChoice)) << ". You lose!\n\n";
            }
        }
        else if (static_cast<Options>(playersChoice) == Options::PAPER)
        {
            if (static_cast<Options>(computersChoice) == Options::STONE)
            {
                std::cout << "\nYou have " << getOptions(static_cast<Options>(playersChoice)) << " and the computer has " << getOptions(static_cast<Options>(computersChoice)) << ". You win!\n\n";
            }
            else
            {
                std::cout << "\nYou have " << getOptions(static_cast<Options>(playersChoice)) << " and the computer has " << getOptions(static_cast<Options>(computersChoice)) << ". You lose!\n\n";
            }
        }

        std::cout << "If you want to play again enter \'Y\' or \'y\': ";
        std::getline(std::cin, playMore);

    } while (playMore == "Y" || playMore == "y");

    return 0;
}