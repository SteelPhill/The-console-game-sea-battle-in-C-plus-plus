#define Rows 12
#define Columns 12
#define TotalShipsNumber 10
#define Ship 'O'
#define Empty ' '
#define Miss '*'
#define Hit '+'
#define Killed 'X'
#define EnterCode 13
#define EscCode 27
#define OneCode 49
#define TwoCode 50
#define ThreeCode 51

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
using namespace std;

enum class ModeMenuItems
{
	PlayerVsAI = OneCode,
	AIVsAI = TwoCode,
	GoToMainMenu = EscCode
};

enum class DifficultyMenuItems
{
	Easy = OneCode,
	Hard = TwoCode,
	GoToMainMenu = EscCode
};

struct PlayerData
{
	string name;
	bool isPlayer;
	bool isFirstAI;
	bool isEasyAI;
};

struct Coordinates
{
	int abscissa;
	int ordinate;
};

struct ShotResult
{
	bool isHit;
	bool isKilled;
	int howManyShipsLeft = TotalShipsNumber;
};

struct Cell
{
	Coordinates coordinates;
	ShotResult result;
};


#include "TryKillShip.h"
#include "TryReadValue.h"
#include "PrintPlayField.h"
#include "MenusAndActions.h"
#include "Shooting.h"
#include "BeginFillField.h"
#include "GameModes.h"
#include "SaveAndLoad.h"
#include <Windows.h>


//MAIN()
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	char firstPlayerField[Rows][Columns];
	char secondPlayerField[Rows][Columns];

	PlayerData firstPlayerData;
	PlayerData secondPlayerData;

	ModeMenuItems gameMode;
	DifficultyMenuItems difficulty;

	bool isNewGame;
	bool isProgramContinue;

	do
	{
		Cell firstPlayerLastShot;
		Cell secondPlayerLastShot;

		isProgramContinue = TryContinueSelectedInMainMenu(isNewGame, gameMode, difficulty, firstPlayerField, secondPlayerField, firstPlayerLastShot, secondPlayerLastShot, firstPlayerData, secondPlayerData);
		if (!isProgramContinue)
			return;

		SelectedMode(isNewGame, gameMode, difficulty, firstPlayerField, secondPlayerField, firstPlayerLastShot, secondPlayerLastShot, firstPlayerData, secondPlayerData);

	} while (true);
}