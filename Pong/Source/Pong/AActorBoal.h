// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "AWallBase.h"
#include "APawnPlatform.h"
#include "AGoal_L.h"
#include "AGoal_R.h"
#include "DeadZone.h"
#include "AActorBoal.generated.h"

UCLASS()
class PONG_API AAActorBoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAActorBoal();

	// Статический меш компонент
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	AAPawnPlatform* Platform;
	AAWallBase* Wall;
	AAGoal_L* Goal_L;
	AAGoal_R* Goal_R;
	ADeadZone* DeadZone;
	bool IsGoal =false;
	
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "MyEvent")
	void StartBoall(FVector Value);
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "MyEvent")
	void MoveBoall(AActor* HitActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
