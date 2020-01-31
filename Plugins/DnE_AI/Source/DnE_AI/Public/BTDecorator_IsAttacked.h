// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsAttacked.generated.h"

/**
 * 
 */
UCLASS()
class DNE_AI_API UBTDecorator_IsAttacked : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_IsAttacked();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
