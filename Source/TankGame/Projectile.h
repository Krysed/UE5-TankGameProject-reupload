// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TANKGAME_API AProjectile : public AActor
{
	GENERATED_BODY()

private:
	//Setting Projectile Mesh
	UPROPERTY(EditAnywhere, Category = "Mesh")
		UStaticMeshComponent* ProjectileMesh;

	//Setting movement component for projectile, forward declaring to avoid using includes in header file
	UPROPERTY(VisibleAnywhere,Category = "Combat")
		class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, Category = "Combat")
		float Damage = 50.f;
	
	//Forward declaring SFX for projectile
	UPROPERTY(EditAnywhere, Category = "SFX")
		class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = "SFX")
		class UParticleSystemComponent* TrailPatricles;

	UPROPERTY(EditAnywhere, Category = "SFX")
		class USoundBase* LaunchSound;
	
	UPROPERTY(EditAnywhere, Category = "SFX")
		USoundBase* HitSound;
	
	UPROPERTY(EditAnywhere, Category = "SFX")
	TSubclassOf<class UCameraShakeBase>OnHitCameraShake;

	UFUNCTION()
	void OnHitEvent(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalInpulse, const FHitResult& Hit);

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
