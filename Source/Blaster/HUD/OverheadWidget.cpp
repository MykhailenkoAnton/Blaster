// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(const FString& TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	if (!InPawn)
	{
		return;
	}

	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ROLE_None:
		Role = FString("None");
		break;
	case ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy");
		break;
	case ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy");
		break;
	case ROLE_Authority:
		Role = FString("Authority");
		break;
	case ROLE_MAX:
		break;
	default:
		break;
	}
	
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);

	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::SetNameText(const FString& NameToDisplay)
{
	if (DisplayName)
	{
		DisplayName->SetText(FText::FromString(NameToDisplay));
	}
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	if (!InPawn)
	{
		return;
	}

	if (InPawn->GetPlayerState())
	{
		SetNameText(InPawn->GetPlayerState()->GetPlayerName());
	}
}

void UOverheadWidget::BeginDestroy()
{
	RemoveFromParent();
	Super::BeginDestroy();
}