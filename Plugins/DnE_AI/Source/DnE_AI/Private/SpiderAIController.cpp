// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiderAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"

ASpiderAIController::ASpiderAIController() {
	RepeatInterval = 3.0f;

	//static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT(""));
	//if (BBObject.Succeeded()) {
	//	BBAsset = BBObject.Object;
	//}
	//static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/DnE_AI/BT_Spider.BT_Spider'"));
	//if (BTObject.Succeeded()) {
	//	BTAsset = BTObject.Object;
	//}
}
void ASpiderAIController::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);
	GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &ASpiderAIController::OnRepeatTimer, RepeatInterval, true);

//	if (UseBlackboard(BBAsset, Blackboard)) {
//		if (!RunBehaviorTree(BTAsset)) {
////			ABLOG(Error, TEXT("SpiderAIController couldn't run behavior tree!"));
//		}
//	}
}
void ASpiderAIController::OnUnPossess() {
	Super::OnUnPossess();
	GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
}
void ASpiderAIController::OnRepeatTimer() {
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