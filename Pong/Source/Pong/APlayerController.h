// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/StaticMeshComponent.h"
#include "APlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API AAPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	// Sets default values for this controller's properties
	AAPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	
};
