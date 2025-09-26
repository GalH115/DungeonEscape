#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONESCAPE_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    
private:
    
    UPROPERTY(VisibleAnywhere) bool ShouldMove = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere) FVector MoveOffset;

	UPROPERTY(EditAnywhere) float MoveTime = 4.0f;

	UPROPERTY(VisibleAnywhere) bool ReachedTargetLocation = false;

	FVector TargetLocation;
	FVector StartLocation;
    
    bool GetShouldMove();
    
    void SetShouldMove(bool NewShouldMove);
};
