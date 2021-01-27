// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemContainerComponent.h"
#include "Canary.h"

/*

	For each type of item, loop through it
	Randomize the array elements, then dice roll vs. it's rarity to see if it dropped
	If it's not at the max drops of that itemType/rarity, keep going.
	Have a minimum amount of drops too (0-2)

	For things like bombs or arrows, maybe randomize how many?
	How to determine if it MUST drop 1 rare, 1 uncommons, 0-3 commons?

	


*/
// Sets default values
UItemContainerComponent::UItemContainerComponent()
{
	bEditableWhenInherited = true;
}
