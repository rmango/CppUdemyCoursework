#pragma once
#include <string>

using FString = std::string;
using int32 = int;
//never use namespace in header file

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); //TODO make a more rich return value
	int32 GetMaxTries() const; //const declaration only works on class functions
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); //TODO rich return value
	// provide a method for counting bulls + cows + increasing try #

private:
	//see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
};