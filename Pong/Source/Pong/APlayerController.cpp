// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayerController.h"
#include "Components/StaticMeshComponent.h"
#include "APawnPlatform.h" // Подключаем заголовочный файл для APawnPlatform

// Sets default values
AAPlayerController::AAPlayerController()
{
	// Set this controller to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//PlatformSM = NULL;
}

// Called when the game starts or when spawned
void AAPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAxis("MovePlatformMouse", this, &AAPlayerController::MoveOnServer);
	
}


