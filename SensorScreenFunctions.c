#include <stdio.h>
#include "headers.h"

void CreateSenorsScreen(struct MyCar *car){
	unsigned char input=SenorsScreen();
	ImplementInputFormSensorsScreen(input,car);
}

unsigned char SenorsScreen(){
	//print the mainScreen's options and read the choice
	unsigned char input;
	do{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	#if (WITH_ENGINE_TEMP_CONTROLLER==1)
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
	#else
	printf("\n");
	#endif
	scanf("\n%c",&input);
	}while(input!='a' && input!='b'&&input!='c'
			#if(WITH_ENGINE_TEMP_CONTROLLER==1)
			&&input!='d'
			#endif
					);
	return (input-'a');
}

void ImplementInputFormSensorsScreen(unsigned char input,struct MyCar *car ){
	#if (WITH_ENGINE_TEMP_CONTROLLER==1)
		void (*ptr[4])(struct MyCar *)={TurningOffVeicleEngine,SetLightColor,SetTempertureRoom,SetEngineTemperture};
		ptr[input](car);
	#else
		void (*ptr[3])(struct MyCar *)={TurningOffVeicleEngine,SetLightColor,SetTempertureRoom};
		ptr[input](car);
	#endif
}


