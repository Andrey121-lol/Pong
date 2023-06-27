// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "APawnPlatform.generated.h"

UCLASS()
class PONG_API AAPawnPlatform : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAPawnPlatform();
	
	// Корневой компонент сцены
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	// Статический меш компонент
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	// Камера компонент
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Func
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "MyEvent")
	void MoveRight(float value);
	
	
	//Vars
};
