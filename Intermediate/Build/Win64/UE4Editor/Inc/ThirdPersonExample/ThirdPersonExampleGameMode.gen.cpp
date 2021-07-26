// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThirdPersonExample/ThirdPersonExampleGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThirdPersonExampleGameMode() {}
// Cross Module References
	THIRDPERSONEXAMPLE_API UClass* Z_Construct_UClass_AThirdPersonExampleGameMode_NoRegister();
	THIRDPERSONEXAMPLE_API UClass* Z_Construct_UClass_AThirdPersonExampleGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ThirdPersonExample();
// End Cross Module References
	void AThirdPersonExampleGameMode::StaticRegisterNativesAThirdPersonExampleGameMode()
	{
	}
	UClass* Z_Construct_UClass_AThirdPersonExampleGameMode_NoRegister()
	{
		return AThirdPersonExampleGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AThirdPersonExampleGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ThirdPersonExample,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ThirdPersonExampleGameMode.h" },
		{ "ModuleRelativePath", "ThirdPersonExampleGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThirdPersonExampleGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::ClassParams = {
		&AThirdPersonExampleGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AThirdPersonExampleGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AThirdPersonExampleGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AThirdPersonExampleGameMode, 1953146846);
	template<> THIRDPERSONEXAMPLE_API UClass* StaticClass<AThirdPersonExampleGameMode>()
	{
		return AThirdPersonExampleGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AThirdPersonExampleGameMode(Z_Construct_UClass_AThirdPersonExampleGameMode, &AThirdPersonExampleGameMode::StaticClass, TEXT("/Script/ThirdPersonExample"), TEXT("AThirdPersonExampleGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AThirdPersonExampleGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
