// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpiderAIController.h"
#include "TutorialSpider.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AMySpiderAIController::HomePosKey(TEXT("HomePos"));
const FName AMySpiderAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AMySpiderAIController::TargetKey(TEXT("Target"));
const FName AMySpiderAIController::bAttackedKey(TEXT("bAttacked"));

AMySpiderAIController::AMySpiderAIController() {
	RepeatInterval = 3.0f;

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("BlackboardData'/DnE_AI/BB_Spider.BB_Spider'"));
	if (BBObject.Succeeded()) {
		BBAsset = BBObject.Object;
	}
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/DnE_AI/BT_Spider.BT_Spider'"));
	if (BTObject.Succeeded()) {
		BTAsset = BTObject.Object;
	}

	OnDeadDeligateSpider.AddDynamic(this, &AMySpiderAIController::OnDead);
}
void AMySpiderAIController::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);
//	GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &ASpiderAIController::OnRepeatTimer, RepeatInterval, true);

		if (UseBlackboard(BBAsset, Blackboard)) {
			if (!RunBehaviorTree(BTAsset)) {
			//	ABLOG(Error, TEXT("SpiderAIController couldn't run behavior tree!"));
			}

			// 스폰위치를 블랙보드에 저장
			Blackboard->SetValueAsVector(HomePosKey, aPawn->GetActorLocation());
		}
}
void AMySpiderAIController::OnUnPossess() {
	Super::OnUnPossess();
//	GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
}
void AMySpiderAIController::OnRepeatTimer() {
	auto CurrentPawn = GetPawn();
	if (!CurrentPawn) {
		return;
	}

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (!NavSystem) {
		return;
	}

	FNavLocation NextLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation)) {
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location);
	//	ABLOG(Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());
	}

}

float AMySpiderAIController::OnDamaged(float Damage, AActor* DamageCauser) {
//	Blackboard->SetValueAsObject(TargetKey, Cast<ATutorialSpider>(DamageCauser));
	ATutorialSpider* CurrentPawn = Cast<ATutorialSpider>(GetPawn());
	CurrentPawn->CurrentHP -= Damage;
	CurrentPawn->bAttacked = true;
	if (CurrentPawn->CurrentHP <= 0) {
		OnDeadDeligateSpider.Broadcast();
		return 0;
	}

	return CurrentHP;
}

void AMySpiderAIController::OnDead_Implementation() {

}
bool AMySpiderAIController::GetAttackedState() {
	ATutorialSpider* CurrentPawn = Cast<ATutorialSpider>(GetPawn());
	return CurrentPawn->bAttacked;
}