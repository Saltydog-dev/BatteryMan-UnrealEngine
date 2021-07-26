/**
* \File BatteryMan_GameMode.h
* \Author Stéphane Boulanger
* \Source https://www.youtube.com/watch?v=LsNW4FPHuZE&t=4573s
* \Version 0.1
* \date juillet 2021
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BatteryMan_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONEXAMPLE_API ABatteryMan_GameMode : public AGameMode
{
	GENERATED_BODY()

	ABatteryMan_GameMode();

	virtual void BeginPlay() override; 

	virtual void Tick(float DeltaTime) override; 

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> PlayerRecharge; 

	float Spawn_Z = 500.0f; 

	UPROPERTY(EditAnywhere)
		float Spawn_X_Min; 

	UPROPERTY(EditAnywhere)
		float Spawn_X_Max;

	UPROPERTY(EditAnywhere)
		float Spawn_Y_Min;

	UPROPERTY(EditAnywhere)
		float Spawn_Y_Max;
	

	void SpawnPlayerRecharge();

};
