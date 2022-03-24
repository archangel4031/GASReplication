// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FGameplayEffectModCallbackData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttrChangeDelegate, float, Attr, int32, StackcCount);

/**
 * 
 */
UCLASS()
class GASREPLICATION_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UGASAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	//Define Attributes Here

	//Attribute for Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health)

	//Attribute for Max Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHealth)

	//Attribute for Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana)

	//Attribute for Max Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana)

	//Attribute for Base Attack Damage
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_BaseAttackDamage)
	FGameplayAttributeData BaseAttackDamage;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, BaseAttackDamage)

	//Attribute for SpeedMultiplier
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_SpeedMultiplier)
	FGameplayAttributeData SpeedMultiplier;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, SpeedMultiplier)

	//Delegates for attribute changes
	FAttrChangeDelegate HealthChangeDelegate;
	FAttrChangeDelegate ManaChangeDelegate;
	FAttrChangeDelegate BaseAttackDamageChangeDelegate;
	FAttrChangeDelegate SpeedMultiplierChangeDelegate;


	//Post Gameplay Effect Execute, only to clamp values
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	//Replication Functions for Health and Mana
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	virtual void OnRep_BaseAttackDamage(const FGameplayAttributeData& OldBaseAttackDamage);
	UFUNCTION()
	virtual void OnRep_SpeedMultiplier(const FGameplayAttributeData& OldSpeedMultiplier);
	
};
