/*
 * LightSensorFunctions.c
 *
 *  Created on: Aug 9, 2023
 *      Author: LEGION
 */
#include <stdio.h>
#include "headers.h"

void SetLightColor(struct MyCar *car){
	car->Senors->LightColor=ReadLightColor();
	SetSpeed(car);
	CheckSpeed(car);
    CreateSenorsScreen(car);
}

unsigned char ReadLightColor(){
	char input;
	do{
		printf("Enter The Value of Light Sensors\n");
		scanf("\n%c",&input);
	}while(input!='g'&&input!='r'&&input!='o');

	return input;
}

void SetSpeed(struct MyCar *car){
	unsigned char temp =car->Senors->LightColor;
	switch (temp){
	case 'g':
		car->speed=100;
		break;
	case 'r':
		car->speed=0;
		break;
	case 'o':
		car->speed=30;
		break;
	default:
		printf("Wrong in Input\n\n");
	}
}

void CheckSpeed(struct MyCar *car){
	if(car->speed==30){
		if(car->AC==0){
			car->Senors->TemperatureSensor=car->Senors->TemperatureSensor*(5/4)+1;
			car->AC=1;
		}
		if(car->EngineTemperatureController==0){
				car->Senors->EngineTemperatureSensor=car->Senors->EngineTemperatureSensor*(5/4)+1;
				car->EngineTemperatureController=1;
		}
	}
	PrintState(car);
}
