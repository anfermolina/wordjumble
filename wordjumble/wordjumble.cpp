////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Assignment:     PROG1260 Assignment 3
//  Instructor:     David Burchill
//  Year / Term:    Fall 2022
//  File name:      wordjumble.cpp
// 
//  Student name:   Anfer Molina
//  Student email:  amolinaflores01@mynbcc.ca
// 
//     I certify that this work is my work only, any work copied from Stack Overflow, textbooks, 
//     or elsewhere is properly cited. 
// 
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BUG 
//  list any and all bugs in your code 
//  1. I didnt get abc to work because of xyz, I tried ijk...
//

#include <iostream>
#include <random>
#include <string>


const int NUM_WORDS = 10;
const std::string words[NUM_WORDS] = {
  "apple",
  "banana",
  "orange",
  "grape",
  "strawberry",
  "watermelon",
  "pineapple",
  "mango",
  "peach",
  "cherry"
};

void playJumble() {
    // random word from the array
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> pick(0, NUM_WORDS - 1);
    std::string randomWord = words[pick(rng)];
    std::string secretWord = randomWord;

    // shuffle the letters 
    std::shuffle(randomWord.begin(), randomWord.end(), rng);

    std::cout << "The jumbled word is: " << randomWord << std::endl;
    std::cout << "Enter your guess: " << std::endl;
    while (true) {
        std::string guess;
        std::cin >> guess;

        // checks to start a new game or quit
        if (guess == "P" || guess == "p") {
            playJumble();
            return;
        }
        else if (guess == "Q" || guess == "q") {
            return;
        }

        // checks the guess
        if (guess == secretWord) {
            std::cout << "Congratulations!!! You guessed the secret word!" << std::endl;
            return;
        }
        else {
            std::cout << "Incorrect guess. Try again." << std::endl;
        }
    }
}

const std::string prompt = R"(
*************** Word Jumble ******************
*                                            *
* (P) - Play Word Jumble                     *
* (Q) - Quit program                         *
*                                            *
**********************************************
)";

int main() {

    bool isPlaying{ true };

    while (isPlaying)
    {
        std::string msg{ "" };
        system("CLS");
        std::cout << prompt;
        msg = "";


        char c;
        std::cin >> c;

        if (c == 'p' || c == 'P')
        {
            playJumble();
        }

        else if (toupper(c) == 'Q')
        {
            break;
        }
        else
        {
           msg = "Choose a valid selection\n";
           std::cout << msg << std::endl;

        }

        system("pause");

    }

}

