#include "add_Alu.h"

sumalu :: sumalu (sc_module_name nm) : sc_module(nm){
    SC_METHOD(process);
    sensitive << aIn << bIn << scAlu;
   }

//MATEMATICAS
void sumalu :: suma(){

    cOut.write(aIn.read() + bIn.read());

}
void sumalu :: resta(){

    cOut.write(aIn.read() - bIn.read());//Revisar

}
void sumalu :: mult(){

    cOut.write(aIn.read() * bIn.read());
    /*int aux = aIn.read();
    int aux2 = 0;
    for(int i = 0; i < aux ; i++){
        aux2 = aux2 + bIn.read();
    }
    cOut.write(aux2);*/
}
void sumalu :: div(){
    //a/b
    cOut.write(aIn.read() / bIn.read());

}
void sumalu :: modu(){
    //%a/b
    cOut.write(aIn.read() % bIn.read());

}

//Desplazamiento 
/*
>>
	

Arithmetic right shift
	

expr >> constant

<<
	

Arithmetic left shift
	

expr << constant
*/
void sumalu :: salt(int salto){
    
    zero.write(0);
    switch(salto){//Comparacon 1== 2!=, 3>= 4<=
        
        case 1://==
            
            if(aIn.read()==bIn.read()){

                zero.write(1);
            }
                        
        break;

        case 2://!=
            if(aIn.read()!=bIn.read()){

                zero = 1;
            }
        break;

        case 3://>=
            if(aIn.read()>=bIn.read()){

                zero = 1;
            }

        break;

        case 4://<=
            if(aIn.read()<=bIn.read()){

                zero = 1;
            }

        break;

    }

}
//comparacion
void sumalu :: and1(){

    cOut.write(aIn.read() and bIn.read());

}
void sumalu :: or1(){

    cOut.write(aIn.read() or bIn.read());
}


void sumalu :: process(){



    //int sc = scAlu.read();
    switch(scAlu.read()){//señal de control

        case 0://suma
            suma();
        break;

        case 1:
            resta();
        break;

        case 2:
            mult();
        break;

        case 3:
            div();
        break;

        case 4:
            modu();
        break;

        case 5://SALTOS
            salt(1);
        break;

        case 6:
            salt(2);
        break;

        case 7:

            salt(3);

        break;

        case 8:

            salt(4);

        break;

    }

}


sumalu::~sumalu() {}