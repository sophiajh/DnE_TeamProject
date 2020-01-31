// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DnE.h"
#include "GameFramework/Character.h"
#include "TutorialSpider.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttackDelegate, AActor*);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class DNE_AI_API ATutorialSpider : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATutorialSpider();
	virtual void PossessedBy(AController* NewController) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnyWhere, Category = "MonsterAI")
		float CurrentHP;
	UPROPERTY(EditAnyWhere, Category = "MonsterAI")
		float MaxHP;

	UFUNCTION(BlueprintNativeEvent, Category="MonsterAI")
		void Attack();
		virtual void Attack_Implementation();
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "MonsterAI")
		FOnAttackEndDelegate OnAttackEndDelegate;

	UPROPERTY(EditAnywhere, Category = "MonsterAI")
		bool bAttacked;
	//UPROPERTY(BlueprintAssignable)
	//	FOnAttackDelegate OnAttackDelegate;
};
