// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerFire.generated.h"

/**
 * 
 */
UCLASS()
class TPSPROJECT_API UPlayerFire : public UPlayerBaseComponent
{
	GENERATED_BODY()

public:
	UPlayerFire();

	virtual void BeginPlay() override;

	virtual void SetupInputBinding(class UInputComponent* PlayerInputComponent) override;
	
public:
	UPROPERTY(EditAnywhere, Category = BulletFactory)
		TSubclassOf<class ABullet> bulletFactory;

	void InputFire();

	bool bUsingGrenadeGun = true;

	void ChangeToGrenadeGun();

	void ChangeToSniperGun();

	void SniperAim();

	bool bSniperAim = false;

	UPROPERTY(EditDefaultsOnly, Category = SniperUI)
	TSubclassOf<class UUserWidget> sniperUIFactory;

	class UUserWidget* _sniperUI;

	UPROPERTY(EditAnywhere, Category = BulletEffect)
	class UParticleSystem* bulletEffectfactory;

	UPROPERTY(EditDefaultsOnly, Category = SniperUI)
	TSubclassOf<class UUserWidget> crosshairUIFactory;

	class UUserWidget* _crosshairUI;


	UPROPERTY(EditDefaultsOnly, Category = CameraMotion)
	TSubclassOf<class UCameraShakeBase> cameraShake;

	UPROPERTY(EditDefaultsOnly, Category = Sound)
	class USoundBase* bulletSound;

	UPROPERTY()
	class UCameraComponent* tpsCamComp;


	UPROPERTY()
	class USkeletalMeshComponent* gunMeshComp;

	UPROPERTY()
	class UStaticMeshComponent* sniperGunComp;

};