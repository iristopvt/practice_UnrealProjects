// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();

	static ConstructorHelpers::FClassFinder<AMyCharacter>
		myCharacter(TEXT("/Script/Engine.Blueprint'/Game/Blueprint/Player/MyCharacter_BP.MyCharacter_BP_C'"));

	if (myCharacter.Succeeded())
	{
		DefaultPawnClass = myCharacter.Class;
	}

}

void AMyGameModeBase::BeginPlay()
{
}
