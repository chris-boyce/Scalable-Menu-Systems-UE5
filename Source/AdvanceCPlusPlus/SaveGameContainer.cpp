// Chris Boyce 1908671 - Advanced C++ Module 


#include "SaveGameContainer.h"

ASaveGameContainer::ASaveGameContainer()
{

}

void ASaveGameContainer::BeginPlay()
{
	Super::BeginPlay();
}

void ASaveGameContainer::SaveGunSkin(UMaterial* GunTexture)
{
	SaveGameData->SaveGunTextureData(GunTexture);
}

void ASaveGameContainer::SaveMouseSense(float MouseSens)
{
	SaveGameData->SaveMouseSens(MouseSens);
}



