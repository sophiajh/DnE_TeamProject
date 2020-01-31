// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsAttacked.h"
#include "TutorialSpider.h"
#include "MySpiderAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsAttacked::UBTDecorator_IsAttacked() {

}
bool UBTDecorator_IsAttacked::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const {
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto Controller = Cast<AMySpiderAIController>(OwnerComp.GetAIOwner());
	if (!Controller) {
		return false;
	}

	bResult = Controller->GetAttackedState();
	//auto ControlledPawn = Cast<ATutorialSpider>(Controller->GetPawn());
	//bResult = ControlledPawn->bAttacked;

	return bResult;
}