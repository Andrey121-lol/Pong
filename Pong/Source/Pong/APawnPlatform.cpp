// Fill out your copyright notice in the Description page of Project Settings.


#include "APawnPlatform.h"

// Sets default values
AAPawnPlatform::AAPawnPlatform()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Создаем корневой компонент сцены и устанавливаем его как корневой компонент павна
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	// Создаем статический меш компонент и присоединяем его к корневому компоненту сцены
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	// Создаем камера компонент и присоединяем его к корневому компоненту сцены
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAPawnPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPawnPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAPawnPlatform::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

