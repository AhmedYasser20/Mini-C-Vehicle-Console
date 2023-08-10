#include <stdio.h>
#include "headers.h"

#if (WITH_ENGINE_TEMP_CONTROLLER==1)
unsigned short ReadEngineTemperture(){
	unsigned short temp;
	printf("Enter The Engine Temperature\n");
	scanf("%hu",&temp);
	return temp;
}
void SetEngineTemperture(struct MyCar *car){
	car->Senors->EngineTemperatureSensor = ReadEngineTemperture();
	SetTempertureContoller(car);
	PrintState(car);
	CreateSenorsScreen(car);
}
void SetTempertureContoller(struct MyCar *car){
	unsigned short temp=car->Senors->EngineTemperatureSensor;
	if(temp<100 || temp>150){
		car->Senors->EngineTemperatureSensor=125;
		car->EngineTemperatureController=1;
	}
	else{
		car->EngineTemperatureController=0;
	}
}
#endif
