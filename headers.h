/*
 * headers.h
 *
 *  Created on: Aug 9, 2023
 *      Author: LEGION
 */

#ifndef HEADERS_H_
#define HEADERS_H_
#define WITH_ENGINE_TEMP_CONTROLLER 0

struct CarSensors{
	char LightColor;
	short TemperatureSensor;
	short EngineTemperatureSensor;
};

struct MyCar{
	short speed;
	char Engine;						//1 == ON 0==OFF
	char AC;							//1 == ON 0==OFF
	char EngineTemperatureController;	//1 == ON 0==OFF
	struct CarSensors *Senors;
};

void PrintState(struct MyCar *car);
void CheckSpeed(struct MyCar *car);

unsigned char MainScreen();
void ImplementInputFormMainScreen(unsigned char input,struct MyCar *car );
void TurningOnVeicleEngine(struct MyCar *car);
void TurningOffVeicleEngine(struct MyCar *car);
void QuitingSystem(struct MyCar *car);

void CreateSenorsScreen(struct MyCar *car);
unsigned char SenorsScreen();
void ImplementInputFormSensorsScreen(unsigned char input,struct MyCar *car );

void SetLightColor(struct MyCar *car);
unsigned char ReadLightColor();
void SetSpeed(struct MyCar *car);


void SetTempertureRoom(struct MyCar *car);
unsigned short ReadTempertureRoom();
void SetAC(struct MyCar *car);

#if (WITH_ENGINE_TEMP_CONTROLLER==1)
void SetTempertureContoller(struct MyCar *car);
void SetEngineTemperture(struct MyCar *car);
#endif
#endif /* HEADERS_H_ */
