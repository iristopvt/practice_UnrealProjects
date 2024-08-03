// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"


UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> at
	(TEXT("/Script/Engine.AnimMontage'/Game/Blueprint/Animation/MyPlayAnimMontage.MyPlayAnimMontage'"));

	if (at.Succeeded())
	{
		_myAnimMontage = at.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconde)
{
	AMyCharacter* myCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
	if (myCharacter != nullptr)
	{
		_speed = myCharacter->GetVelocity().Size();
		_isFalling = myCharacter->GetMovementComponent()->IsFalling();
		_vartical = _vartical + (myCharacter->_varical - _vartical) * (DeltaSeconde);
		_horizontal = _horizontal + (myCharacter->_horizontal - _horizontal) * (DeltaSeconde);
		//_isDead = (myCharacter->GetCurHp() <= 0);
	}

}

void UMyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(_myAnimMontage))
	{
		Montage_Play(_myAnimMontage);

			AMyCharacter* myCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
	}
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Attack%d"), sectionIndex));
	Montage_JumpToSection(sectionName);
}
