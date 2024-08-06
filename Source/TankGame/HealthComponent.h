// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

private:

	UPROPERTY(EditAnywhere)
		float MaxHealth = 100.f;
	//health will be set in BeginPlay() function
	float Health = 0.f;

	UFUNCTION(BlueprintPure)
		float GetHealthPercent() const;
	
	//Functions called in blueprints
	UFUNCTION(BlueprintCallable)
		void HealOnOverlap();
	UFUNCTION(BlueprintCallable)
		void DamageOnOverlap(float Damage);

	UFUNCTION()
		void TakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,class AController* Inducer, AActor* DamageCauser);
		
	class ATankGameGameMode* TankGameGameMode;
};