/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Funciones Pre-Autonomas
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////

void brazoUp()
{
	int a=0;
	while (a==0){
		if(SensorValue[dgtl4]==0){
			a=1;
	    motor[port1] = 0;
		  motor[port10]  = 0;
		}
		else {
			motor[port1] = 127;
			motor[port10]  = 127;
		}
	}
}
void brazoDown()
{
	int a=0;
	while (a==0){
		if(SensorValue[dgtl3]==0){
			a=1;
	    motor[port1] = 0;
		  motor[port10]  = 0;
		}
		else {
			motor[port1] = -127;
			motor[port10]  = -127;
		}
	}
}
void brazoDownMed()
{
	motor[port1] = -127;
	motor[port10]  = -127;
	wait1Msec(200);
	motor[port1] = 0;
	motor[port10]  = 0;

}
void brazoUpMed(float tiempo)
{
	motor[port1] = 127;
	motor[port10]  = 127;
	wait1Msec(tiempo*1000);
	motor[port1] = 0;
	motor[port10]  = 0;

}
void adelante(int velocidad, float tiempo, int brazo)
{
		motor[port2] = velocidad/4;
    motor[port3] = velocidad/4;
	  motor[port4] = velocidad/4;
    motor[port5] = velocidad/4;
    wait1Msec(200);
    motor[port2] = velocidad/2;
    motor[port3] = velocidad/2;
	  motor[port4] = velocidad/2;
    motor[port5] = velocidad/2;
    wait1Msec(200);

    while(SensorValue[dgtl1]==1 && SensorValue[dgtl5]==1) {
    	motor[port2] = velocidad;
	    motor[port3] = velocidad;
		  motor[port4] = velocidad;
	    motor[port5] = velocidad;
	    if (brazo==1) {
	    	brazoUp();
	  	}
  	}

    motor[port2] = velocidad;
    motor[port3] = velocidad;
	  motor[port4] = velocidad;
    motor[port5] = velocidad;

		wait1Msec(tiempo*1000);

    motor[port2] = 0;
    motor[port3] = 0;
	  motor[port4] = 0;
    motor[port5] = 0;
}
void adelanteTiempo(int velocidad, float tiempo, int brazo)
{
		motor[port2] = velocidad/4;
    motor[port3] = velocidad/4;
	  motor[port4] = velocidad/4;
    motor[port5] = velocidad/4;
    wait1Msec(200);
    motor[port2] = velocidad/2;
    motor[port3] = velocidad/2;
	  motor[port4] = velocidad/2;
    motor[port5] = velocidad/2;
    wait1Msec(200);
    if (brazo==1) {
    	brazoUp();
  	}

    motor[port2] = velocidad;
    motor[port3] = velocidad;
	  motor[port4] = velocidad;
    motor[port5] = velocidad;

		wait1Msec(tiempo*1000);

    motor[port2] = 0;
    motor[port3] = 0;
	  motor[port4] = 0;
    motor[port5] = 0;
}
void transversal(int velocidad, float tiempo, int brazo)
{
		motor[port7] = velocidad/4;
    wait1Msec(200);
    motor[port7] = velocidad/2;
    wait1Msec(200);
    if (brazo==1) {
    	brazoUp();
  	}

    motor[port7] = velocidad;

		wait1Msec(tiempo*1000);

    motor[port7] = 0;
}
void atras(int velocidad, float tiempo, int brazo)
{
    motor[port2] = -velocidad;
    motor[port3]  = -velocidad;
	  motor[port4] = -velocidad;
    motor[port5]  = -velocidad;
		if (brazo==1){
				brazoUpMed(1.2);
		}
		wait1Msec(tiempo*1000);

    motor[port2] = 0;
    motor[port3]  = 0;
	  motor[port4] = 0;
    motor[port5]  = 0;
}
void click()
{
	int a=0;
	while (a==0) {
		if(SensorValue[dgtl2]==0){
			a=1;
		}
	}
}
void orugaTraga(int velocidad)
{
	motor[port9]=-velocidad;
}
void orugaEscupe(int velocidad)
{
	motor[port9]=velocidad;
}
void orugaOff()
{
	motor[port9]=0;
}
void adelanteLine(int velocidad, int lado)
{
	int turnLeft=0;
	int turnRight=0;
		motor[port2] = velocidad;
    motor[port3]  = velocidad;
	  motor[port4] = velocidad;
    motor[port5]  = velocidad;
    wait1Msec(1000);
    if (lado==-1) {
			while(SensorValue[lnL]>2960) {
				motor[port2] = velocidad;
		    motor[port3]  = velocidad;
			  motor[port4] = velocidad;
		    motor[port5]  = velocidad;
			}
		}
		else {
			while(SensorValue[lnR]>2900) {
				motor[port2] = velocidad;
		    motor[port3]  = velocidad;
			  motor[port4] = velocidad;
		    motor[port5]  = velocidad;
			}
		}
	  motor[port2] = velocidad * lado;
    motor[port3] = velocidad * lado;
	  motor[port4] = -velocidad * lado;
    motor[port5] = -velocidad* lado;
    wait1Msec(160);
    motor[port2] = 0;
    motor[port3]  = 0;
    motor[port4] = 0;
    motor[port5]  = 0;
    brazoUp();

	  while(SensorValue[dgtl1]==1 && SensorValue[dgtl5]==1 && SensorValue[dgtl6]==1) {
			motor[port2] = velocidad/2-turnLeft;
	    motor[port3]  = velocidad/2-turnLeft;
		  motor[port4] = velocidad/2-turnRight;
	    motor[port5]  = velocidad/2-turnRight;
	    if (SensorValue[lnR]<2900) {
	    	turnLeft=velocidad/2;
			}
			else if (SensorValue[lnL]<2960) {
	    	turnRight=velocidad/2;
			}
			else {
				turnLeft=0;
				turnRight=0;
			}
		}
    motor[port2] = 0;
    motor[port3]  = 0;
    motor[port4] = 0;
    motor[port5]  = 0;
}
void girar(int velocidad,float tiempo, int lado) {
	motor[port2]= velocidad;
	motor[port3]= velocidad;
	motor[port4]= -velocidad;
	motor[port5]= -velocidad;
	wait1Msec(tiempo * 1000);
	motor[port2]= 0;
	motor[port3]= 0;
	motor[port4]= 0;
	motor[port5]= 0;
}

void autoAdelante(int lado) {
	//brazoUp();
	//adelante(127, 0, 0); //3 espacio: Levantar brazo mientras avanza =1,
	//brazoDownMed();
	//atras(127, 1.5, 0);
	//brazoDown();
	//click();
	//adelante(127, 0, 1);
	//brazoDownMed();
	//atras(127, 1.5, 0);
	//brazoDown();
	//click();
	//adelanteTiempo(127, 1.5, 0); //Levantar brazo mientras avanza =1,
	////adelanteLine(127, lado); //Lado Derecho = 1, Lado Izquierdo = -1
	adelanteTiempo(127, 1.5, 0); //Levantar brazo mientras avanza =1,
	orugaEscupe(127);
}
void autoAtras(int lado) {
	orugaTraga(127);
	adelanteTiempo(127, 0.4, 0); //Levantar brazo mientras avanza =1,
  wait1Msec(200);
	orugaOff();
	//girar(127, 0.4, 1);
	transversal((65*lado), 2, 0);
	atras(127, 1.1, 0);
	transversal((65*lado), 1.6, 0);
	adelanteTiempo(127, 0.6, 0); //Levantar brazo mientras avanza =1,
	atras(127, 1.3, 0); //brazoupMed 1
	adelanteTiempo(127, 0.5, 0); //Levantar brazo mientras avanza =1,
	transversal((65*lado), 1, 0);
	atras(127, 1, 0);
}
