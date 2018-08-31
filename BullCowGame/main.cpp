/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic, see the FBullCowGame class. 
*/

//change

#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

using FText = std::string; //FText for user interaction in Unreal
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//the entry point for the application
int main() {

	std::cout << BCGame.GetCurrentTry();

	bool willRepeat = false;
	do {
		PrintIntro();
		PlayGame();
		willRepeat = AskToPlayAgain();
	} while (willRepeat);

	return 0;
}

void PrintIntro() {
	//introduce the game
	constexpr int32 WORD_LENGTH = 5; //constexpr cannot change once program is running
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	return;
}

FText GetGuess() {
	//get a guess from player
	std::cout << "Enter your guess" << std::endl;
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: " << std::endl;
	
	//loop for number of turns askingfor guesses
	constexpr int32 NUM_TURNS = 1;
	int32 i = NUM_TURNS;
	do {
		FText Guess = GetGuess(); //TODO make loop checking valid 
		
		//submit valid guess to game
		// print number of bulls and cows

		std::cout << "Your guess was " << Guess << std::endl;
		i--;
	} while (i > 0);

	//TODO add a game summary
}

bool AskToPlayAgain() {
	std::cout << "Would you like to play again? (y/n)" << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);

	if (Response.length() <= 3) {
		FText LowerResponse = "";
		for (char letter : Response) {
			LowerResponse += tolower(letter);
		}
		if (LowerResponse[0] == 'y' || LowerResponse == "yes") {
			return true;
		}
		else if (LowerResponse[0] == 'n' || LowerResponse == "no") {
			return false;
		}
	} 
	
	//if response is not acceptable
	std::cout << "Please respond with y or n" << std::endl;
	return AskToPlayAgain();
}