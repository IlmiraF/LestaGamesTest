// Copyright Epic Games, Inc. All Rights Reserved.

#include "LestaGamesTestGameMode.h"
#include "LestaGamesTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALestaGamesTestGameMode::ALestaGamesTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
