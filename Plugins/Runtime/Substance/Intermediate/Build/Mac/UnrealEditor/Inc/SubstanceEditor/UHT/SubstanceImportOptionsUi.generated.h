// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SubstanceImportOptionsUi.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUBSTANCEEDITOR_SubstanceImportOptionsUi_generated_h
#error "SubstanceImportOptionsUi.generated.h already included, missing '#pragma once' in SubstanceImportOptionsUi.h"
#endif
#define SUBSTANCEEDITOR_SubstanceImportOptionsUi_generated_h

#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_SPARSE_DATA
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_RPC_WRAPPERS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_ACCESSORS
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUSubstanceImportOptionsUi(); \
	friend struct Z_Construct_UClass_USubstanceImportOptionsUi_Statics; \
public: \
	DECLARE_CLASS(USubstanceImportOptionsUi, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SubstanceEditor"), NO_API) \
	DECLARE_SERIALIZER(USubstanceImportOptionsUi) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorUserSettings");} \



#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USubstanceImportOptionsUi(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USubstanceImportOptionsUi) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USubstanceImportOptionsUi); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USubstanceImportOptionsUi); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USubstanceImportOptionsUi(USubstanceImportOptionsUi&&); \
	NO_API USubstanceImportOptionsUi(const USubstanceImportOptionsUi&); \
public: \
	NO_API virtual ~USubstanceImportOptionsUi();


#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_18_PROLOG
#define FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_SPARSE_DATA \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_RPC_WRAPPERS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_ACCESSORS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_INCLASS \
	FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUBSTANCEEDITOR_API UClass* StaticClass<class USubstanceImportOptionsUi>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_Substance_Source_SubstanceEditor_Public_SubstanceImportOptionsUi_h


#define FOREACH_ENUM_ESUBSTANCEMATERIALPARENTTYPE(op) \
	op(ESubstanceMaterialParentType::Default) \
	op(ESubstanceMaterialParentType::Custom) \
	op(ESubstanceMaterialParentType::Generated) 

enum class ESubstanceMaterialParentType : uint8;
template<> struct TIsUEnumClass<ESubstanceMaterialParentType> { enum { Value = true }; };
template<> SUBSTANCEEDITOR_API UEnum* StaticEnum<ESubstanceMaterialParentType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
