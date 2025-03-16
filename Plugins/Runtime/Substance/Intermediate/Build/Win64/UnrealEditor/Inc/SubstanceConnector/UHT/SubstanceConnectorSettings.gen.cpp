// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Source/SubstanceConnector/Classes/SubstanceConnectorSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSubstanceConnectorSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SUBSTANCECONNECTOR_API UClass* Z_Construct_UClass_USubstanceConnectorSettings();
	SUBSTANCECONNECTOR_API UClass* Z_Construct_UClass_USubstanceConnectorSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SubstanceConnector();
// End Cross Module References
	void USubstanceConnectorSettings::StaticRegisterNativesUSubstanceConnectorSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USubstanceConnectorSettings);
	UClass* Z_Construct_UClass_USubstanceConnectorSettings_NoRegister()
	{
		return USubstanceConnectorSettings::StaticClass();
	}
	struct Z_Construct_UClass_USubstanceConnectorSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USubstanceConnectorSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SubstanceConnector,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USubstanceConnectorSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USubstanceConnectorSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** Implements the settings for the Substance Connector plugin. */" },
		{ "IncludePath", "SubstanceConnectorSettings.h" },
		{ "ModuleRelativePath", "Classes/SubstanceConnectorSettings.h" },
		{ "ToolTip", "Implements the settings for the Substance Connector plugin." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USubstanceConnectorSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USubstanceConnectorSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USubstanceConnectorSettings_Statics::ClassParams = {
		&USubstanceConnectorSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A2u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USubstanceConnectorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_USubstanceConnectorSettings_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_USubstanceConnectorSettings()
	{
		if (!Z_Registration_Info_UClass_USubstanceConnectorSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USubstanceConnectorSettings.OuterSingleton, Z_Construct_UClass_USubstanceConnectorSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USubstanceConnectorSettings.OuterSingleton;
	}
	template<> SUBSTANCECONNECTOR_API UClass* StaticClass<USubstanceConnectorSettings>()
	{
		return USubstanceConnectorSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USubstanceConnectorSettings);
	USubstanceConnectorSettings::~USubstanceConnectorSettings() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceConnector_Classes_SubstanceConnectorSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceConnector_Classes_SubstanceConnectorSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USubstanceConnectorSettings, USubstanceConnectorSettings::StaticClass, TEXT("USubstanceConnectorSettings"), &Z_Registration_Info_UClass_USubstanceConnectorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USubstanceConnectorSettings), 2229027560U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceConnector_Classes_SubstanceConnectorSettings_h_3714166775(TEXT("/Script/SubstanceConnector"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceConnector_Classes_SubstanceConnectorSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceConnector_Classes_SubstanceConnectorSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
