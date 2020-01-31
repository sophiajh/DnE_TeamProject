// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DnE.h"
#include "SpiderAIController.h"
#include "MySpiderAIController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeadDeligateSpider);
/**
 * 
 */
UCLASS()
class DNE_AI_API AMySpiderAIController : public ASpiderAIController
{
	GENERATED_BODY()
public:
    AMySpiderAIController();
    void OnPossess(APawn* aPawn) override;
    void OnUnPossess() override;

	UFUNCTION(BlueprintCallable, Category = "MonsterAI")
		float OnDamaged(float Damage, AActor* DamageCauser);
	UFUNCTION(BlueprintNativeEvent, Category = "MonsterAI")
		void OnDead();
		virtual void OnDead_Implementation();
	UFUNCTION(BlueprintCallable, Category = "MonsterAI")
		bool GetAttackedState();
public:
    static const FName HomePosKey;
    static const FName PatrolPosKey;
    static const FName TargetKey;
	static const FName bAttackedKey;

	UPROPERTY(EditAnyWhere, Category = "MonsterAI")
		float CurrentHP;
	UPROPERTY(EditAnyWhere, Category = "MonsterAI")
		float MaxHP;

	UPROPERTY(BlueprintAssignable)
		FOnDeadDeligateSpider OnDeadDeligateSpider;
	//UPROPERTY(EditAnywhere, Category = "MonsterAI")
	//	bool bAttacked;

protected:
    void OnRepeatTimer();
    FTimerHandle RepeatTimerHandle;
    float RepeatInterval;
};
