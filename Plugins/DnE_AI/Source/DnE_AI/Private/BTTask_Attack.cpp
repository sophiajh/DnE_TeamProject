// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "MySpiderAIController.h"
#include "TutorialSpider.h"

UBTTask_Attack::UBTTask_Attack() {
	bNotifyTick = true;
	IsAttacking = false;
	AddFlag = false;
//	Cast<ATutorialSpider>(ATutorialSpider::StaticClass())->OnAttackEndDelegate.AddDynamic(this, &UBTTask_Attack::SetAttackState);
}
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto TutorialSpider = Cast<ATutorialSpider>(OwnerComp.GetAIOwner()->GetPawn());
	if (!TutorialSpider) {
		return EBTNodeResult::Failed;
	}
	TutorialSpider->Attack();
	IsAttacking = true;
	//TutorialSpider->OnAttackEndDelegate.AddLambda([this]() -> void {
	//	IsAttacking = false; 
	//});
	if (!AddFlag) {
		TutorialSpider->OnAttackEndDelegate.AddDynamic(this, &UBTTask_Attack::SetAttackState);
		AddFlag = true;
	}
	return EBTNodeResult::InProgress;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (!IsAttacking) {
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
void UBTTask_Attack::SetAttackState() {
	IsAttacking = false;
}