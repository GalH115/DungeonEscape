#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColleactableItem.generated.h"

UCLASS()
class DUNGEONESCAPE_API AColleactableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColleactableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY (EditAnywhere) FString ItemName;
    
};
