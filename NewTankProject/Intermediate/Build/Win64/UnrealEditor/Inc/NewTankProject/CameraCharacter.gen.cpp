// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NewTankProject/Public/CameraCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraCharacter() {}
// Cross Module References
	NEWTANKPROJECT_API UClass* Z_Construct_UClass_ACameraCharacter_NoRegister();
	NEWTANKPROJECT_API UClass* Z_Construct_UClass_ACameraCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_NewTankProject();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void ACameraCharacter::StaticRegisterNativesACameraCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACameraCharacter);
	UClass* Z_Construct_UClass_ACameraCharacter_NoRegister()
	{
		return ACameraCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ACameraCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraRShoulderLocation_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraRShoulderLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraOriginLocation_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraOriginLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACameraCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_NewTankProject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CameraCharacter.h" },
		{ "ModuleRelativePath", "Public/CameraCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraRShoulderLocation_MetaData[] = {
		{ "Category", "CameraCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CameraCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraRShoulderLocation = { "CameraRShoulderLocation", nullptr, (EPropertyFlags)0x002008000009000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCharacter, CameraRShoulderLocation), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraRShoulderLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraRShoulderLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraOriginLocation_MetaData[] = {
		{ "Category", "CameraCharacter" },
		{ "Comment", "// Arrow Component for the Camera Origin viewpoint location\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CameraCharacter.h" },
		{ "ToolTip", "Arrow Component for the Camera Origin viewpoint location" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraOriginLocation = { "CameraOriginLocation", nullptr, (EPropertyFlags)0x002008000009000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCharacter, CameraOriginLocation), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraOriginLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraOriginLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraComp_MetaData[] = {
		{ "Category", "CameraCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CameraCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraComp = { "CameraComp", nullptr, (EPropertyFlags)0x002008000009000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCharacter, CameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraComp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACameraCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraRShoulderLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraOriginLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCharacter_Statics::NewProp_CameraComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACameraCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACameraCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACameraCharacter_Statics::ClassParams = {
		&ACameraCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACameraCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACameraCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACameraCharacter()
	{
		if (!Z_Registration_Info_UClass_ACameraCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACameraCharacter.OuterSingleton, Z_Construct_UClass_ACameraCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACameraCharacter.OuterSingleton;
	}
	template<> NEWTANKPROJECT_API UClass* StaticClass<ACameraCharacter>()
	{
		return ACameraCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACameraCharacter);
	struct Z_CompiledInDeferFile_FID_NewTankProject_Source_NewTankProject_Public_CameraCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewTankProject_Source_NewTankProject_Public_CameraCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACameraCharacter, ACameraCharacter::StaticClass, TEXT("ACameraCharacter"), &Z_Registration_Info_UClass_ACameraCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACameraCharacter), 4029249572U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NewTankProject_Source_NewTankProject_Public_CameraCharacter_h_3797740222(TEXT("/Script/NewTankProject"),
		Z_CompiledInDeferFile_FID_NewTankProject_Source_NewTankProject_Public_CameraCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NewTankProject_Source_NewTankProject_Public_CameraCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
