// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "MyCharacter.h"
//#include "MyHpBar.h"
#include "MyStatComponent.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyStatComponent::Reset()
{
	_curHp = _maxHp;
}

void UMyStatComponent::SetLevellAndInit(int level)
{
	auto myGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if (myGameInstance)
	{
		FMystatData* data = myGameInstance->GetStatDataMyLevel(level);
		_maxHp = data->maxHp;
		_attackDamage = data->attack;
		_curHp = _maxHp;

		UE_LOG(LogTemp, Log, TEXT("%s...hp : %d, attackDamage : %d"), *GetOwner()->GetName(), _maxHp, _attackDamage);
	}
}

void UMyStatComponent::SetHp(int32 hp)
{
	// curhp의 수정은 무조건 이 함수를 통해서 이루어진다.
	// -> 이 함수가 호출 될때마다 hpbar가 바뀌면 되겟다.
	//AddCurHp()
	_curHp = hp;
	if (_curHp < 0)
		_curHp = 0;
	if (_curHp > _maxHp)
		_curHp = _maxHp;

	float ratio = HpRatio();
	_hpChangedDelegate.Broadcast(ratio);

}

int UMyStatComponent::AddCurHp(float amount)
{
	// amount dmage가 들어왔을 때 
	// 방어력 스탯이나, 데미지 경감 등의 옵션으로 amount가 줄어든 채로
	// _curHp가 더해진다.

	// ex) amount *= 0.8f; // 20%? 
	int beforeHp = _curHp;
	int afterHp = beforeHp + amount;
	SetHp(afterHp);


	return afterHp - beforeHp;
}

void UMyStatComponent::AddAttackDamage(float amount)
{
	_attackDamage += amount;

}

