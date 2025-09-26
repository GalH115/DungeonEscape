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

void UTriggerComponent::Trigger(bool NewTriggerValue)
{
    IsTriggered = NewTriggerValue;
    
    if (Mover)
    {
        Mover->SetShouldMove(IsTriggered);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("%s doesn't have a mover to trigger!"), *GetOwner()->GetActorNameOrLabel());
    }
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherCmop, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
    {
        ActivatorCount++; // Increase Activator by 1
        
        if (!IsTriggered)
        {
            Trigger(true);
        }
    }
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherCmop, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator"))
    {
        ActivatorCount--; // Decreasae Activator by 1
        
        if (IsTriggered && ActivatorCount == 0)
        {
            Trigger(false);
        }
    }
}
