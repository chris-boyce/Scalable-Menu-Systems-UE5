// Chris Boyce 1908671 - Advanced C++ Module 


#include "GraphicsSettings.h"

#include "Engine/RendererSettings.h"

void UGraphicsSettings::ChangeAASetting(FString SettingType)
{
	URendererSettings* RendererSettings = GetMutableDefault<URendererSettings>();
	
	
	if(SettingType == "Low")
	{
		RendererSettings->DefaultFeatureAntiAliasing = EAntiAliasingMethod::AAM_TemporalAA;
		UE_LOG(LogTemp, Warning , TEXT("IS TEMPORTALAA"))
	}
	else if(SettingType == "Medium")
	{
		RendererSettings->DefaultFeatureAntiAliasing = EAntiAliasingMethod::AAM_FXAA;
		UE_LOG(LogTemp, Warning , TEXT("IS FXAA"))
	}
	else if(SettingType == "High")
	{
		RendererSettings->DefaultFeatureAntiAliasing = EAntiAliasingMethod::AAM_MSAA;
		UE_LOG(LogTemp, Warning , TEXT("IS MSAA"))
	}
	else
	{
		RendererSettings->DefaultFeatureAntiAliasing = EAntiAliasingMethod::AAM_TemporalAA;
	}
}
