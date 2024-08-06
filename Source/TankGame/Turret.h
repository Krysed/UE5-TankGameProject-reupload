// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"

/**
 *
 */
UCLASS()
class TANKGAME_API ATurret : public ABasePawn
{
	GENERATED_BODY()

private:
	float FireRate = 2.f;
	FTimerHandle FireRateTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Forward declaring tank to not include too many files in header
	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "CombatSettings")
		float FireRange = 1200.f;

	/**
	 * @brief Check if target is valid and call Fire() function if valid
	*/
	void CheckFireCondition();

	/**
	 * @brief check if target is in FireRange
	 * @return true or false
	*/
	bool InFireRangeWithTank();
public:
	//Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();
};
