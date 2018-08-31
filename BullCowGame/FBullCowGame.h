#pragma once
#include <string>

using FString = std::string;
using int32 = int;
//never use namespace in header file

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus { //strongly typed enum bc used "class"
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); //TODO make a more rich return value
	int32 GetMaxTries() const; //const declaration only works on class functions
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus  CheckGuessValidity(FString) const; //TODO rich return value
	FBullCowCount SubmitGuess(FString);


private:
	//see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};