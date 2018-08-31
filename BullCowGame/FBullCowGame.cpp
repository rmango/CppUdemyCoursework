#include "FBullCowGame.h" //if including something in std library, use <>, if in own files, use ""

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	
	if (false) { //not an isogram
		return EGuessStatus::Not_Isogram;
	} else if (false) {//not lowercase
		return EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLength()) {//guess length wrong
		return EGuessStatus::Wrong_Length;
	} else {
		return EGuessStatus::Ok;
	}
}

//recieves a valid guess, increments turn, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increments turn #
	MyCurrentTry++;

	//setup return variable
	FBullCowCount BullCowCount;

	//loop through all letters in guess
		//compare letters against hidden word
	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		for (int32 j = 0; j < MyHiddenWord.length(); j++) {
			if (Guess[i] == MyHiddenWord[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
