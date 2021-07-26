/**
* \File BatteryMan_GameMode.cpp
* \Author Stéphane Boulanger 
* \Source https://www.youtube.com/watch?v=LsNW4FPHuZE&t=4573s
* \Version 0.1
* \date juillet 2021
*/


#include "BatteryMan_GameMode.h"
#include "GameFramework/Actor.h"

ABatteryMan_GameMode::ABatteryMan_GameMode()
{
	PrimaryActorTick.bCanEverTick = true; 
}

void ABatteryMan_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryMan_GameMode::SpawnPlayerRecharge, FMath::RandRange(2, 5), true);
}


void ABatteryMan_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 


}

void ABatteryMan_GameMode::SpawnPlayerRecharge()
{
	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnPosition = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor(PlayerRecharge, &SpawnPosition, &SpawnRotation);
}
