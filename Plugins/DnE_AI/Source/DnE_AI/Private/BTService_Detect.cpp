// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "MySpiderAIController.h"
#include "DnECharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_Detect::UBTService_Detect() {
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (!ControllingPawn) {
		return;
	}

	UWorld* World = ControllingPawn->GetWorld();
	FVector DetectCenter = ControllingPawn->GetActorLocation();
	float DetectRadius = 600.0f;

	if (!World) {
		return;
	}
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		DetectCenter,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult) {
		// 합칠 때 캐릭터 클래스 + 블랙보드의 Target 기반클래스 수정할 것
		for (auto& OverlapResult : OverlapResults) {
			ACharacter* DnECharacter = Cast<ACharacter>(OverlapResult.GetActor());
			if (DnECharacter && DnECharacter->GetController()->IsPlayerController()) {
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMySpiderAIController::TargetKey, DnECharacter);
			//	DrawDebugSphere(World, DetectCenter, DetectRadius, 16, FColor::Green, false, 0.2f);
			//	DrawDebugPoint(World, DnECharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
			//	DrawDebugLine(World, ControllingPawn->GetActorLocation(), DnECharacter->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}
		}
	}
//	else {
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMySpiderAIController::TargetKey, nullptr);
//	}
//	DrawDebugSphere(World, DetectCenter, DetectRadius, 16, FColor::Red, false, 0.2f);

}