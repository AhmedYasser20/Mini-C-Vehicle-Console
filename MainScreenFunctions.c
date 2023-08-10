#include <stdio.h>
#include "headers.h"

void CreateMainScreen(struct MyCar *car){
	unsigned char input=MainScreen();
	ImplementInputFormMainScreen(input,car );
}
void TurningOnVeicleEngine(struct MyCar *car){
	//printf("Turn on Vehicle Engine\n");
	car->Engine=1;
	CreateSenorsScreen(car);
}
void TurningOffVeicleEngine(struct MyCar *car){
	puts("Turn off Vehicle Engine\n");
	car->Engine=0;
	CreateMainScreen(car);
}
void QuitingSystem(struct MyCar *car){
	//maybe need to do some code in future
	printf("Quit the System");
	return;
}
unsigned char MainScreen(){
	//print the mainScreen's options and read the choice
	unsigned char input;
	do{
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf("\n%c",&input);
	}while(input!='a' && input!='b'&&input!='c');
	return (input-'a');
}

void ImplementInputFormMainScreen(unsigned char input,struct MyCar *car ){
	//i think i donot need to pointer to function becouse number of functions is small
	//maybe later we need to add more
	void (*ptr[3])(struct MyCar *)={TurningOnVeicleEngine,TurningOffVeicleEngine,QuitingSystem};
	ptr[input](car);
}

