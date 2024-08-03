// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */


DECLARE_MULTICAST_DELEGATE(AttackDelegate);
DECLARE_MULTICAST_DELEGATE(DeathDelegate);

UCLASS()
class MYPRACTICE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UMyAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconde) override;

	void PlayAttackMontage();

	void JumpToSection(int32 sectionIndex);

	AttackDelegate _attackDelegate;
	DeathDelegate _deathDelegate;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawen, Meta = (AllowPrivateAccess = true))
	float _speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawen, Meta = (AllowPrivateAccess = true))
	bool _isFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawen, Meta = (AllowPrivateAccess = true))
	bool _isDead;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawen, Meta = (AllowPrivateAccess = true))
	float _vartical;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pawen, Meta = (AllowPrivateAccess = true))
	float _horizontal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pawen, Meta = (AllowPrivateAccess = true))
	class UAnimMontage* _myAnimMontage;
};
