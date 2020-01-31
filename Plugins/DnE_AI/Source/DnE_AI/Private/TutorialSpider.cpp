// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialSpider.h"

// Sets default values
ATutorialSpider::ATutorialSpider()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxHP = 100.0f;
	CurrentHP = MaxHP;
	bAttacked = false;
}

// Called when the game starts or when spawned
void ATutorialSpider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutorialSpider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATutorialSpider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATutorialSpider::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);

	if (!IsPlayerControlled()) {
		GetCharacterMovement()->MaxWalkSpeed = 150.0f;
	}
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
}

//void ATutorialSpider::Attack() {
//
//}

void ATutorialSpider::Attack_Implementation() {

}