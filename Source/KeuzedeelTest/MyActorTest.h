

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "GameFramework/Actor.h"
#include "MyActorTest.generated.h"

UCLASS()
class KEUZEDEELTEST_API AMyActorTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorTest();

	// Property = variables
	// BlueprintReadWrite = can change in blueprint

#pragma region Step2 Return something
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestVariables")
	int32 valueA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestVariables")
	int32 valueB;

	// Syntax for a function that has two ints
	UFUNCTION(BlueprintCallable, Category = "TestFunctions")
	int32 CalculateValues(int32 value1, int32 value2);
#pragma endregion
	
#pragma region Step3 & Make timer
	// Save timerHandle
	FTimerHandle EventTimerHandle;
	//float myTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerVariables")
	int32 timerCount;
	UPROPERTY(BlueprintReadWrite, Category = "TimerVariables")
	float timer;
	
	// Syntax for a function that has a float
	UFUNCTION(BlueprintCallable, Category = "TestFunctions")
	void DoSomethingAfterTimer(float timer1);

	UFUNCTION(BlueprintCallable, Category = "TimerFunctions")
	void OnTimer();
#pragma endregion

#pragma region Step4 Spawn object
	FVector thisPosition;
	FRotator thisRotation;
	UClass* thisClassToInstantiate;
	FString thisDebugTwo;

	UFUNCTION(BlueprintCallable, Category = "SpawnTest")
	void SpawnActorAfterDelay(FString debugOne, FString debugTwo, float delay, FVector position, FRotator rotation, UClass* ClassToInstantiate);
	UFUNCTION(BlueprintCallable, Category = "TimerFunctions")
	void CheckAfterDelay();
#pragma endregion

#pragma region Step5 Play sequence
	ULevelSequencePlayer* sequencePlayer;
	ULevelSequence* sequenceToPlay;
	FString theDebugTwo;

	UFUNCTION(BlueprintCallable, Category = "SequenceFunctions")
	void PlaySequenceAfterDelay(FString debugOne, FString debugTwo, float delay, ULevelSequence* levelSequence);
	UFUNCTION(BlueprintCallable, Category = "SequenceFunctions")
	void PlayAfterDelay();
#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};