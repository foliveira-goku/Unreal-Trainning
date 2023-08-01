
#include "TanksPlayerController.h"
#include "GameFramework/Pawn.h"

void ATanksPlayerController::SetPlayerEnabledState(bool playerEnabled)
{
	if (playerEnabled)
		GetPawn()->EnableInput(this);
	else
		GetPawn()->DisableInput(this);

	bShowMouseCursor = playerEnabled;
}
