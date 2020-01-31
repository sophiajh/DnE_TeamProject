// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SYCharacter.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttackOnDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPutONDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRollOnDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPutOffDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTargetingDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShootDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHPIsZeroDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FONHPChangedDelegate);

UCLASS()
class SYCHARACTER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	APlayerCharacter();
	void SetCharacterState(ECharacterState NewState);
	ECharacterState GetCharacterState() const;
private:
	TSubclassOf<UAnimInstance> AniNoWeapon;
	TSubclassOf<UAnimInstance> AniSwordWeapon;
	TSubclassOf<UAnimInstance> AniBowWeapon;
	TSubclassOf<UAnimInstance> AniBomgWeapon;

	UAnimMontage*	MontageDead;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxHP;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat)
	float CurrentHP;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat)
	float AttackStat;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat)
	bool IsDead = false;
public:
	void SetDamage(float NewDamage);
	void SetHeal(float NewHeal);
	void SetHP(float NewHP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	enum class EcontrolMode
	{
		THIRDNEAR,
		THIRDFAR,
		NPC
	};
	void SetControlMode(EcontrolMode NewControlMode);
	EcontrolMode CurrentControlMode = EcontrolMode::THIRDFAR;
	FVector DirectionToMove = FVector::ZeroVector;

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Light)
		UPointLightComponent* PointLight;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		USkeletalMeshComponent* SK_Scabbard;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		USkeletalMeshComponent* Bow;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		UStaticMeshComponent* ST_Sword_S;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		UStaticMeshComponent* ST_Sword_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		UStaticMeshComponent* Bomb;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile)
		TSubclassOf<class AActor> ProjectileClass;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
		UActorComponent* CurrentWeapon;
	UFUNCTION(BlueprintCallable, Category = Weapon)
		void SetSword();
	UFUNCTION(BlueprintCallable, Category = Weapon)
		void SetBow();
	UFUNCTION(BlueprintCallable, Category = Weapon)
		void SetBomb();

	
private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);
	void Targeting();
	void Shoot();
	void ChangeWeapon();
	void Roll();


	UFUNCTION()
		void Attack();
	//°ø°Ý
private:
	UFUNCTION()
		void AttackCheck();
	//Ä¸½¶
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;
public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category=Attack, Meta=(AllowPrivateAccess=true))
		bool IsAttacking;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = Move, Meta = (AllowPrivateAccess = true))
		bool IsRolling;
	UPROPERTY(BlueprintAssignable)
		FAttackOnDelegate AttackOn;
	UPROPERTY(BlueprintAssignable)
		FPutONDelegate PutOn;
	UPROPERTY(BlueprintAssignable)
		FPutOffDelegate PutOff;
	UPROPERTY(BlueprintAssignable)
		FRollOnDelegate RollOn;
	UPROPERTY(BlueprintAssignable)
		FTargetingDelegate TargetOn;
	UPROPERTY(BlueprintAssignable)
		FShootDelegate Shooting;
	UPROPERTY(BlueprintAssignable)
		FOnHPIsZeroDelegate OnHPIsZero;
	UPROPERTY(BlueprintAssignable)
		FONHPChangedDelegate ONHPChanged;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
private:
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
		ECharacterState CurrentState;

};
