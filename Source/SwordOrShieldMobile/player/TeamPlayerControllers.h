// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "TeamPlayerControllers.generated.h"

/**
 * 
 */
UCLASS()
class SWORDORSHIELDMOBILE_API ATeamPlayerControllers : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
public:
	ATeamPlayerControllers();
    
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	virtual FGenericTeamId GetGenericTeamId() const override;
    
private:
	UPROPERTY(EditDefaultsOnly)
	FGenericTeamId TeamId = FGenericTeamId(0);
};
