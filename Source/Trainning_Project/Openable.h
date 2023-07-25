#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Openable.generated.h"

UINTERFACE(MinimalAPI)
class UOpenable : public UInterface
{
	GENERATED_BODY()
};

class TRAINNING_PROJECT_API IOpenable
{
	GENERATED_BODY()

public:
	virtual void Open() = 0;
	virtual void Close() = 0;
};
