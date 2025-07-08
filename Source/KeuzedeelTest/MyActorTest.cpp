#include "MyActorTest.h"
#include "Runtime/Engine/Public/TimerManager.h"

// Sets default values
AMyActorTest::AMyActorTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Define the default values
	valueA = 0;
	valueB = 0;

	timerCount = 0;
}

// Called when the game starts or when spawned
void AMyActorTest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Step 2
int32 AMyActorTest::CalculateValues(int32 value1, int32 value2)
{
	return value1 + value2;
}

// Step 3
void AMyActorTest::DoSomethingAfterTimer(float timer1)
{
	// Pass the set timer as the counting timer
	timer = timer1;

	// Trigger the timer
	GetWorld()->GetTimerManager().SetTimer(EventTimerHandle, this, &AMyActorTest::OnTimer, 1, true);
}

// Timer needed for all other functions
void AMyActorTest::OnTimer()
{
	// When function is called count the timer
	++timerCount;

	// Check if the counter passes the time
	if (timerCount >= timer)
	{
		PlayAfterDelay();

		//CheckAfterDelay();
		// Clear the timer handle so it won't keep triggering events
		GetWorld()->GetTimerManager().ClearTimer(EventTimerHandle);
	}
}

// Step 4
void AMyActorTest::SpawnActorAfterDelay(FString debugOne, FString debugTwo, float delay, FVector position, FRotator rotation, UClass* ClassToInstantiate)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, debugOne);

	// Pass the delay as the timer
	timer = delay;

	// Pass actor information
	thisPosition = position;
	thisRotation = rotation;
	thisClassToInstantiate = ClassToInstantiate;

	// Pass the debug text
	thisDebugTwo = debugTwo;

	// Trigger the delay
	GetWorld()->GetTimerManager().SetTimer(EventTimerHandle, this, &AMyActorTest::OnTimer, 1, true);
}

// Step 4
void AMyActorTest::CheckAfterDelay()
{
	FActorSpawnParameters SpawnInfo;

	// Spawn the actor
	GetWorld()->SpawnActor(thisClassToInstantiate, &thisPosition, &thisRotation, SpawnInfo);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, thisDebugTwo);
}

// Step 5
void AMyActorTest::PlaySequenceAfterDelay(FString debugOne, FString debugTwo, float delay, ULevelSequence* levelSequence)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, debugOne);

	// Pass the delay as the timer
	timer = delay;
	// Pass actor information
	sequenceToPlay = levelSequence;
	// Pass the debug text
	theDebugTwo = debugTwo;

	// Trigger the delay
	GetWorld()->GetTimerManager().SetTimer(EventTimerHandle, this, &AMyActorTest::OnTimer, 1, true);
}

// Step 5
void AMyActorTest::PlayAfterDelay()
{
	// Create local OutActor
	ALevelSequenceActor* OutActor;
	// Create a level sequence player
	sequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), sequenceToPlay, FMovieSceneSequencePlaybackSettings(), OutActor);
	
	// Check if sequence has been added
	if (sequencePlayer)
	{
		sequencePlayer->Play();
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, thisDebugTwo);
}