#include "Triggercomponent.h"

UTriggerComponent::UTriggerComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (MoverActor) 
	{
		Mover = MoverActor->FindComponentByClass<UMover>();
		if (Mover) 
		{
			UE_LOG(LogTemp, Warning, TEXT("Successfully found the mover component!"));
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to find the mover component!"));
		}
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("MoverActor is nullptr"));
	}

	if (IsPressurePlate) 
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, 
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherCmop, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("PressurePlateActivator")) 
	{
		if (Mover) 
		{
			Mover->ShouldMove = true;
		}
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherCmop, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("PressurePlateActivator")) 
	{
		if (Mover)
		{
			Mover->ShouldMove = false;
		}
	}
}
