#include "ColleactableItem.h"

// Sets default values
AColleactableItem::AColleactableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Tags.Add("CollectableItem");

}

// Called when the game starts or when spawned
void AColleactableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColleactableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
