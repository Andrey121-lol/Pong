// Fill out your copyright notice in the Description page of Project Settings.


#include "AActorBoal.h"

// Sets default values
AAActorBoal::AAActorBoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Создаем статический меш компонент и присоединяем его к корневому компоненту сцены
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);



}

void AAActorBoal::StartBoall_Implementation(FVector Value)
{
	StaticMesh->SetPhysicsLinearVelocity(Value);
	IsGoal=false;
}

void AAActorBoal::MoveBoall_Implementation(AActor* HitActor)
{
	Platform= Cast<AAPawnPlatform>(HitActor);
	if (Platform )
	{
		FVector NewLinearVelocity;
		float RandFloat = FMath::RandRange(-1000.0f,1000.0f);
		NewLinearVelocity.X=StaticMesh->GetPhysicsLinearVelocity().X*(-1);
		NewLinearVelocity.Y=Platform->StaticMesh->GetPhysicsLinearVelocity().Y+RandFloat;
		NewLinearVelocity.Z=StaticMesh->GetPhysicsLinearVelocity().Z;
		StaticMesh->SetPhysicsLinearVelocity(NewLinearVelocity);
	}
	Wall =Cast<AAWallBase>(HitActor);
	if (Wall)
	{
		FVector NewLinearVelocity;
		NewLinearVelocity.X=StaticMesh->GetPhysicsLinearVelocity().X;
		NewLinearVelocity.Y=StaticMesh->GetPhysicsLinearVelocity().Y*(-1);
		NewLinearVelocity.Z=StaticMesh->GetPhysicsLinearVelocity().Z;
		StaticMesh->SetPhysicsLinearVelocity(NewLinearVelocity);
	}
	Goal_L=Cast<AAGoal_L>(HitActor);
	if (Goal_L)
	{
		IsGoal=true;
		StaticMesh->SetPhysicsLinearVelocity(FVector(0,0,0));
		SetActorLocation(FVector(0,0,65));
		ScoreL=ScoreL++;
		FVector Value (1000.0f,0.0f,0.0f);
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this, FName("StartBoall"), Value);
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, 3.0f, false);
	}
	Goal_R=Cast<AAGoal_R>(HitActor);
	if (Goal_R)
	{
		IsGoal=true;
		StaticMesh->SetPhysicsLinearVelocity(FVector(0,0,0));
		SetActorLocation(FVector(0,0,65));
		ScoreR=ScoreR++;
		FVector Value (-1000.0f,0.0f,0.0f);
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this, FName("StartBoall"), Value);
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, 3.0f, false);
	}
	Bot=Cast<AAiPlatform>(HitActor);
	if (Bot)
	{
		FVector NewLinearVelocity;
		float RandFloat = FMath::RandRange(-1000.0f,1000.0f);
		NewLinearVelocity.X=StaticMesh->GetPhysicsLinearVelocity().X*(-1);
		NewLinearVelocity.Y=Bot->StaticMeshComponent->GetPhysicsLinearVelocity().Y+RandFloat;
		NewLinearVelocity.Z=StaticMesh->GetPhysicsLinearVelocity().Z;
		StaticMesh->SetPhysicsLinearVelocity(NewLinearVelocity);	
	}
	
	DeadZone=Cast<ADeadZone>(HitActor);
	if (DeadZone)
	{
		StaticMesh->SetPhysicsLinearVelocity(FVector(0,0,0));
		SetActorLocation(FVector(0,0,65));
		bool RandBool=FMath::RandBool();
		if(RandBool)
		{
			StartBoall(FVector(1000,0,0));
		}
		else
		{
			StartBoall(FVector(-1000,0,0));
		}
	}
}

// Called when the game starts or when spawned
void AAActorBoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAActorBoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

