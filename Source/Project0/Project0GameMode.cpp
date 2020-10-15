// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project0GameMode.h"
#include "Project0Character.h"
#include "UObject/ConstructorHelpers.h"

AProject0GameMode::AProject0GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
