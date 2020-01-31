// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInAttackRange.h"
#include "TutorialSpider.h"
#include "MySpiderAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange() {
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const {
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (!ControllingPawn) {
		return false;
	}

	// 공격받으면 블랙보드의 Target값이 HitActor로 변경되도록 설정할 것
//	auto Target = Cast<ATutorialSpider>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMySpiderAIController::TargetKey));
	auto Target = OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMySpiderAIController::TargetKey);
	if (!Target) {
		return false;
	}

	ACharacter* TargetCharacter = Cast<ACharacter>(Target);

	// AttackRange = 200.0f
	bResult = (TargetCharacter->GetDistanceTo(ControllingPawn) <= 200.0f);
	return bResult;
}