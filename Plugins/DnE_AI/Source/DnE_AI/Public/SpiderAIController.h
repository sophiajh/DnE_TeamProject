// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DnE_AI.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "SpiderAIController.generated.h"

/**
 * 
 */
UCLASS()
class DNE_AI_API ASpiderAIController : public AAIController
{
	GENERATED_BODY()

public:
    ASpiderAIController();
    void OnPossess(APawn* aPawn) override;
    void OnUnPossess() override;
protected:
    void OnRepeatTimer();
    FTimerHandle RepeatTimerHandle;
    float RepeatInterval;
public:
    UPROPERTY()
        class UBehaviorTree* BTAsset;
    UPROPERTY()
        class UBlackboardData* BBAsset;

};
