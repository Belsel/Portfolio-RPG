// Fill out your copyright notice in the Description page of Project Settings.


#include "PortfolioRPGAssetManager.h"
#include "PortfolioRPGItem.h"
#include "AbilitySystemGlobals.h"

/*const FPrimaryAssetType	UPortfolioRPGAssetManager::SkillItemType = TEXT("Skill");

UPortfolioRPGAssetManager& UPortfolioRPGAssetManager::Get()
{
	UPortfolioRPGAssetManager* This = Cast<UPortfolioRPGAssetManager>(GEngine->AssetManager);

	if (This)
	{
		return *This;
	}
	else
	{
		UE_LOG(LogActionRPG, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be RPGAssetManager!"));
		return *NewObject<UPortfolioRPGAssetManager>(); // never calls this
	}
}

void UPortfolioRPGAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
}


UPortfolioRPGItem* UPortfolioRPGAssetManager::ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning)
{
	FSoftObjectPath ItemPath = GetPrimaryAssetPath(PrimaryAssetId);

	// This does a synchronous load and may hitch
	UPortfolioRPGItem* LoadedItem = Cast<UPortfolioRPGItem>(ItemPath.TryLoad());

	if (bLogWarning && LoadedItem == nullptr)
	{
		UE_LOG(LogActionRPG, Warning, TEXT("Failed to load item for identifier %s!"), *PrimaryAssetId.ToString());
	}

	return LoadedItem;
}

*/