#include <stdio.h>
#include "headers.h"

unsigned short ReadTempertureRoom(){
	unsigned short temp;
	printf("Enter The Room Temperature\n");
	scanf("%hu",&temp);
	return temp;
}
void SetTempertureRoom(struct MyCar *car){
	car->Senors->TemperatureSensor = ReadTempertureRoom();
	SetAC(car);
	PrintState(car);
	CreateSenorsScreen(car);
}
void SetAC(struct MyCar *car){
	unsigned short temp=car->Senors->TemperatureSensor;
	if(temp<10 || temp>30){
		car->Senors->TemperatureSensor=20;
		car->AC=1;
	}
	else{
		car->AC=0;
	}
}
