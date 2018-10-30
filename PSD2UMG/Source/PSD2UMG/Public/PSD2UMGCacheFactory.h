
/**

Copyright 2018 swd. All rights reserved.

*/

#pragma once

#include "Factories/Factory.h"

#if WITH_EDITOR
#include "Editor/UnrealEd/Public/EditorReimportHandler.h"
#endif

#include "PSD2UMGCacheFactory.generated.h"

UCLASS()
class UPSD2UMGCacheFactory : public UFactory, public FReimportHandler
{
	GENERATED_UCLASS_BODY()

	virtual bool DoesSupportClass(UClass* Class) override;
	virtual UClass* ResolveSupportedClass() override;

	virtual UObject* FactoryCreateBinary(
		UClass* InClass,
		UObject* InParent,
		FName InName,
		EObjectFlags Flags,
		UObject* Context,
		const TCHAR* Type,
		const uint8*& Buffer,
		const uint8* BufferEnd,
		FFeedbackContext* Warn) override;

	virtual bool CanReimport(UObject* Obj, TArray<FString>& OutFilenames) override;
	virtual void SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths) override;
	virtual EReimportResult::Type Reimport(UObject* Obj) override;

};