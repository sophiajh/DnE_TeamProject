// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "SYCharacter.h"
#include "DrawDebugHelpers.h"
#include "SY_Projectile.h"
#include "Camera/PlayerCameraManager.h"
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	SK_Scabbard = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Scabbard"));
	ST_Sword_S = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ST_Sword_S"));
	ST_Sword_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ST_Sword_L"));
	Bow = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Bow"));
	Bomb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bomb"));

	CameraBoom->SetupAttachment(GetCapsuleComponent());
	PointLight->SetupAttachment(GetMesh());
	FollowCamera->SetupAttachment(CameraBoom);

	ProjectileClass = ASY_Projectile::StaticClass();
	PointLight->SetIntensity(200.0f);
	PointLight->SetRelativeLocation(FVector(0.000004f, 15.280977f, 0.000019f));
	PointLight->SetAttenuationRadius(150.0f);
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
	CameraBoom->TargetArmLength = 600;
	CameraBoom->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BELICA(TEXT("/SYCharacter/Sword_Elf/Models/SK_Elf.SK_Elf"));
	if (BELICA.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(BELICA.Object);
	}



	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BOW(TEXT("/SYCharacter/ParagonSparrow/Characters/Heroes/Sparrow/Meshes/Sparrow.Sparrow"));
	if (BOW.Succeeded())
	{
		/*Bow->SetupAttachment(GetMesh());
		Bow->SetSkeletalMesh(BOW.Object);
		Bow->SetMasterPoseComponent(GetMesh());*/

		FName Bow_Socket(TEXT("Bow_pelvis_Sock"));
		//FName Bow_Socket(TEXT("Bowhand_Socket"));
		if (GetMesh()->DoesSocketExist(Bow_Socket))
		{

			Bow->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, Bow_Socket);
			Bow->SetSkeletalMesh(BOW.Object);
			//Bow->SetMasterPoseComponent(GetMesh());
		}
		
	}


	static ConstructorHelpers::FObjectFinder<UStaticMesh> BOMB(TEXT("/SYCharacter/SY/Mesh/Shape_Sphere.Shape_Sphere"));
	if (BOMB.Succeeded())
	{
		Bomb->SetStaticMesh(BOMB.Object);
	}
		


	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SCABBARD(TEXT("/SYCharacter/Sword_Elf/Models/Wepons/SK_Scabbard.SK_Scabbard"));
	if (SCABBARD.Succeeded())
	{
		SK_Scabbard->SetupAttachment(GetMesh());
		SK_Scabbard->SetSkeletalMesh(SCABBARD.Object);
		SK_Scabbard->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
		SK_Scabbard->SetMasterPoseComponent(GetMesh());
	}

	FName sSocket(TEXT("Wepon_S"));
	if (SK_Scabbard->DoesSocketExist(sSocket))
	{

		static ConstructorHelpers::FObjectFinder<UStaticMesh> SWORDS(TEXT("/SYCharacter/Sword_Elf/Models/Wepons/ST_Sword_S.ST_Sword_S"));
		if (SWORDS.Succeeded())
		{
			ST_Sword_S->SetStaticMesh(SWORDS.Object);
		}
		ST_Sword_S->SetupAttachment(SK_Scabbard, sSocket);
	}

	FName lSocket(TEXT("Wepon_L"));
	if (SK_Scabbard->DoesSocketExist(lSocket))
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SWORDL(TEXT("/SYCharacter/Sword_Elf/Models/Wepons/ST_Sword_L.ST_Sword_L"));
		if (SWORDL.Succeeded())
		{
			ST_Sword_L->SetStaticMesh(SWORDL.Object);
		}
		ST_Sword_L->SetupAttachment(SK_Scabbard, lSocket);
	}


	//캐릭터 애니메이션
	
	static ConstructorHelpers::FClassFinder<UAnimInstance> NOWEAPONANI(TEXT("/SYCharacter/Sword_Elf/Animations/ABP_SY_Elf_NoWeapon1.ABP_SY_Elf_NoWeapon1_C"));
	{
		AniNoWeapon = NOWEAPONANI.Class;
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance> SWORDANI(TEXT("/SYCharacter/Sword_Elf/Animations/ABP_SY_Elf_Sword.ABP_SY_Elf_Sword_C"));
	{
		AniSwordWeapon = SWORDANI.Class;
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance> BOWANI(TEXT("/SYCharacter/Sword_Elf/Animations/ABP_SY_Elf_Bow.ABP_SY_Elf_Bow_C"));
	{
		AniBowWeapon = BOWANI.Class;
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> BOMBANI(TEXT("/SYCharacter/SY/Animation/throw/ABP_ElfGripThrowAction.ABP_ElfGripThrowAction_C"));
	{
		AniBomgWeapon = BOMBANI.Class;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> DRAWN(TEXT("/SYCharacter/Sword_Elf/Animations/Dead_Montage.Dead_Montage"));
	{
		MontageDead = DRAWN.Object;
	}
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetAnimInstanceClass(AniNoWeapon);
	 


	SetControlMode(EcontrolMode::THIRDFAR);

	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed = 10.0f;
	GetCharacterMovement()->JumpZVelocity = 600.0f;


	
	IsAttacking = false;
	IsRolling = false;
	CurrentWeapon = nullptr;

	AttackRange = 200.0f;
	AttackRadius = 50.0f;

	MaxHP = 100.0f;
	CurrentHP = MaxHP;
}

void APlayerCharacter::SetCharacterState(ECharacterState NewState)
{
	//ABCHECK(CurrentState != NewState);
	CurrentState = NewState;

	switch (CurrentState)
	{
	case ECharacterState::LOADING:
	{
		break;
	}
	case ECharacterState::READY:
	{
		break;
	}
	case ECharacterState::DEAD:
	{
		break;
	}
	}
}

ECharacterState APlayerCharacter::GetCharacterState() const
{
	return CurrentState;
}
// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AttackOn.AddDynamic(this, &APlayerCharacter::AttackCheck);
}
float APlayerCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser); //* CurrentCombo;
	UE_LOG(LogTemp, Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);
	SetDamage(FinalDamage);
	return FinalDamage;

}
void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;

}
// Called to bind functionality to input

void APlayerCharacter::SetSword()
{
	if (CurrentWeapon != ST_Sword_L)
	{
		
		if (GetMesh()->IsPlaying())
		{
			GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
			GetMesh()->SetAnimInstanceClass(nullptr);
		}
		IsAttacking = false;
		IsRolling = false;
		CurrentWeapon = ST_Sword_L;
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
		GetMesh()->SetAnimInstanceClass(AniSwordWeapon);
		FName handr(TEXT("hand_rSocket"));
		if (GetMesh()->DoesSocketExist(handr))
		{
			ST_Sword_L->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, handr);
			ST_Sword_L->WeldToImplementation(GetMesh(), handr);
		}

		FName Bow_Socket(TEXT("Bow_pelvis_Sock"));
		if (GetMesh()->DoesSocketExist(Bow_Socket))
		{
			Bow->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, Bow_Socket);
			Bow->WeldToImplementation(GetMesh(), Bow_Socket);
		}

	}
}
void APlayerCharacter::SetBow()
{
	//if (CurrentWeapon == nullptr || CurrentWeapon == ST_Sword_L)
	if (CurrentWeapon != Bow)
	{
		if (GetMesh()->IsPlaying())
		{
			GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
			GetMesh()->SetAnimInstanceClass(nullptr);
			
		}
		IsAttacking = false;
		IsRolling = false;
		CurrentWeapon = Bow;
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
		GetMesh()->SetAnimInstanceClass(AniBowWeapon);
	
		FName lSocket(TEXT("Wepon_L"));
		if (SK_Scabbard->DoesSocketExist(lSocket))
		{
			ST_Sword_L->AttachToComponent(SK_Scabbard, FAttachmentTransformRules::KeepRelativeTransform, lSocket);
		}
		FName Bow_Socket(TEXT("Bowhand_Socket"));
		if (GetMesh()->DoesSocketExist(Bow_Socket))
		{
			Bow->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, Bow_Socket);
		}



		
	}
}
void APlayerCharacter::SetBomb()
{
	if (CurrentWeapon != Bomb)
	{
		
		if (GetMesh()->IsPlaying())
		{
			GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
			GetMesh()->SetAnimInstanceClass(nullptr);

		}
		IsAttacking = false;
		IsRolling = false;
		CurrentWeapon = Bomb;
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
		GetMesh()->SetAnimInstanceClass(AniBomgWeapon);

		FName BombSocket(TEXT("Bomb_Socket"));
		Bomb->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, BombSocket);
		FName lSocket(TEXT("Wepon_L"));
		if (SK_Scabbard->DoesSocketExist(lSocket))
		{
			ST_Sword_L->AttachToComponent(SK_Scabbard, FAttachmentTransformRules::KeepRelativeTransform, lSocket);
		}
		FName Bow_Socket(TEXT("Bow_pelvis_Sock"));
		if (GetMesh()->DoesSocketExist(Bow_Socket))
		{
			Bow->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, Bow_Socket);
			Bow->WeldToImplementation(GetMesh(), Bow_Socket);
		}
	}
}
void APlayerCharacter::ChangeWeapon()
{
	//검으로
	if (CurrentWeapon != ST_Sword_L)
	{
		SetSword();
		return;
	}
	//활로
	if (CurrentWeapon != Bow)
	{
		SetBow();
		return;

	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &APlayerCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &APlayerCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::Turn);


	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Attack);
	PlayerInputComponent->BindAction(TEXT("Targeting"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Targeting);
	PlayerInputComponent->BindAction(TEXT("Targeting"), EInputEvent::IE_Released, this, &APlayerCharacter::Shoot);
	PlayerInputComponent->BindAction(TEXT("Roll"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Roll);
	PlayerInputComponent->BindAction(TEXT("GainBomb"), EInputEvent::IE_Pressed, this, &APlayerCharacter::SetBomb);
	PlayerInputComponent->BindAction(TEXT("WeaponChange"), EInputEvent::IE_Pressed, this, &APlayerCharacter::ChangeWeapon);
}
void APlayerCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);

}
void APlayerCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);

}
void APlayerCharacter::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}
void APlayerCharacter::Turn(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

void APlayerCharacter::Attack()
{	
	if (CurrentWeapon == nullptr)
	{
		return;
	}
	if (!IsAttacking)
	{
		AttackOn.Broadcast();
		//IsAttacking = true;
	}
}

void APlayerCharacter::Targeting()
{
	
	//SetControlMode(EcontrolMode::THIRDNEAR);
	TargetOn.Broadcast();
}
void APlayerCharacter::Shoot()
{
	
	//SetControlMode(EcontrolMode::THIRDFAR);
	Shooting.Broadcast();
	if (ProjectileClass != NULL)
	{
		if (GetWorld() != NULL)
		{
			FVector SocketLoc;
			SocketLoc = Bow->GetSocketLocation("BowEmitterSocket");
			
	
			//const FRotator SpawnRotation = Controller->GetControlRotation();
			//GetMesh()->GetForwardVector();
			// const FRotator SpawnRotation = Bow->GetSocketRotation("BowEmitterSocket");
			FRotator SpawnRotation = Bow->GetSocketRotation("BowEmitterSocket");
			
			/*APlayerCameraManager::GetActorRotation();
			FRotator CameraRotation = APlayerCameraManager::GetActorRotation();
			SpawnRotation.Yaw = CameraRotation.Yaw;*/

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			GetWorld()->SpawnActor<AActor>(ProjectileClass, SocketLoc, SpawnRotation, ActorSpawnParams);
		}
	}

}

void APlayerCharacter::Roll()
{
	if (!IsRolling)
	{
		RollOn.Broadcast();
	}
}

void APlayerCharacter::AttackCheck()
{
	TArray<FHitResult> HitResults;
	FCollisionQueryParams Params(NAME_None, false, this);

	/*SweepSingleByChannel*/

	bool bResult = GetWorld()->SweepMultiByProfile(
		HitResults,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		TEXT("PlayerAttack"),
		FCollisionShape::MakeSphere(AttackRadius),
		Params);
#if ENABLE_DRAW_DEBUG
	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(
		GetWorld(),
		Center,
		HalfHeight,
		AttackRadius,
		CapsuleRot,
		DrawColor,
		false,
		DebugLifeTime);

#endif
	if (bResult)
	{
		for (auto& HitResult : HitResults)
		{
			if (HitResult.Actor.IsValid())
			{
				UE_LOG(LogTemp, Warning, TEXT("Throw Damage Actor Name : %s"), *HitResult.Actor->GetName());
				FDamageEvent DamageEvent;
				float CurrentDamage = 50;
				HitResult.Actor->TakeDamage(CurrentDamage, DamageEvent, GetController(), this);

			}
		}
		

	}
}
void APlayerCharacter::SetControlMode(EcontrolMode NewControlMode)
{
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
	case EcontrolMode::THIRDFAR:
	{
		//SpringArm->TargetArmLength = 450.0f;
		//SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		ArmLengthTo = 450.0f;
		CameraBoom->bUsePawnControlRotation = true;
		CameraBoom->bInheritPitch = true;
		CameraBoom->bInheritRoll = true;
		CameraBoom->bInheritYaw = true;
		CameraBoom->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
		//캐릭터가 움직이는 방향으로 캐릭터를 자동으로 회전시켜줌
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;//보간
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;
	}
	
	case EcontrolMode::THIRDNEAR:
	{

		/*ArmLengthTo = 200.0;		
		CameraBoom->bUsePawnControlRotation = true;
		CameraBoom->bInheritPitch = true;
		CameraBoom->bInheritRoll = true;
		CameraBoom->bInheritYaw = true;
		CameraBoom->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;

		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;*/
	}

	case EcontrolMode::NPC:
	{
		/*bUseControllerRotationYaw = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);*/
		//break; 
	}

	}
}

void APlayerCharacter::SetDamage(float NewDamage)
{
	SetHP(FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, MaxHP));

}
void APlayerCharacter::SetHP(float NewHP)
{
	CurrentHP = NewHP;
	ONHPChanged.Broadcast();

	if (CurrentHP < KINDA_SMALL_NUMBER)
	{
		CurrentHP = 0.0f;
		OnHPIsZero.Broadcast();
		IsDead = true;
		/*if (GetMesh()->IsPlaying())
		{
			GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
			GetMesh()->SetAnimInstanceClass(nullptr);
		}
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
		GetMesh()->GetAnimInstance()->Montage_Play(MontageDead, 1, EMontagePlayReturnType::MontageLength, 0.5f, true);*/
		SetActorEnableCollision(false);
	}
}
void APlayerCharacter::SetHeal(float NewHeal)
{
	SetHP(FMath::Clamp<float>(CurrentHP + NewHeal, CurrentHP, MaxHP));
}