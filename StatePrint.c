#include <stdio.h>
#include "headers.h"

void PrintState(struct MyCar *car){
	printf("Engine State : %s\n",car->Engine==1?"ON":"OFF");
	printf("AC : %s\n",car->AC==1?"ON":"OFF");
	printf("Vehicle Speed : %d Km/Hr\n",car->speed);
	printf("Room Temperature : %hu C\n",car->Senors->TemperatureSensor);
#if(WITH_ENGINE_TEMP_CONTROLLER==1)
	printf("Engine Temperature Controller State : %s \n",car->EngineTemperatureController==1?"ON":"OFF");
	printf("Engine Temperature : %hu C\n\n",car->Senors->EngineTemperatureSensor);
#else
	printf("\n");
#endif
}


