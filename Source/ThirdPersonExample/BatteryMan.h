/**
* \File BatteryMan.h
* \Author Stéphane Boulanger
* \Source https://www.youtube.com/watch?v=LsNW4FPHuZE&t=4573s
* \Version 0.1
* \date juillet 2021
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/UserWidget.h"

#include "BatteryMan.generated.h"

UCLASS()
class THIRDPERSONEXAMPLE_API ABatteryMan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABatteryMan();

	UPROPERTY(VisibleAnywhere, BlueprintREadOnly, Category = Camera)
		USpringArmComponent* CameraBoom; 

	UPROPERTY(VisibleAnywhere, BlueprintREadOnly, Category = Camera)
		UCameraComponent* FollowCamera; 


	// Movement of the player 
	void MoveForward(float Axis); 
	void MoveRight(float Axis); 

	// To know if the character is dead or not 
	bool bDead; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Power;

	UPROPERTY(EditAnywhere)
		float Power_Treshold; 

	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> Player_Power_Widget_Class;
	UUserWidget* Player_Power_Widget; 

	void RestartGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
