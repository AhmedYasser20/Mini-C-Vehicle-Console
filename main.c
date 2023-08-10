#include <stdio.h>
#include "headers.h"

int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
	struct CarSensors s={'r',35,90};
	struct MyCar Car={10,0,0,0,&s};
	unsigned char input=MainScreen();
	ImplementInputFormMainScreen(input,&Car);

	return 0;
}
