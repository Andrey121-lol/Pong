// Fill out your copyright notice in the Description page of Project Settings.


#include "AiPlatform.h"

// Sets default values
AAiPlatform::AAiPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// Установить статик меш компонент как рут компонент
	SetRootComponent(StaticMeshComponent);

}

// Called when the game starts or when spawned
void AAiPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAiPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

