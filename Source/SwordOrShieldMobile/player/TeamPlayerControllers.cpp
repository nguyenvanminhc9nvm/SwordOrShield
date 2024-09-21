// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamPlayerControllers.h"

ATeamPlayerControllers::ATeamPlayerControllers()
{
	SetGenericTeamId(GetGenericTeamId());
}

ETeamAttitude::Type ATeamPlayerControllers::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (APawn const* OtherPawn = Cast<APawn>(&Other))
	{
		if (auto const TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			if (TeamAgent->GetGenericTeamId() == GetGenericTeamId())
			{
				return ETeamAttitude::Friendly;
			}
			else
			{
				return ETeamAttitude::Hostile;
			}
		}
	}
	return ETeamAttitude::Neutral;
}

FGenericTeamId ATeamPlayerControllers::GetGenericTeamId() const
{
	return TeamId;
}