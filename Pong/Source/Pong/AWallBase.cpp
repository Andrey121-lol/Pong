// Fill out your copyright notice in the Description page of Project Settings.


#include "AWallBase.h"

// Sets default values
AAWallBase::AAWallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Создаем корневой компонент сцены и устанавливаем его как корневой компонент павна
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	// Создаем статический меш компонент и присоединяем его к корневому компоненту сцены
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAWallBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAWallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

