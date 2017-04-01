#include "GestionnaireInstructions.h"

GestionnaireInstructions::GestionnaireInstructions() {}

void GestionnaireInstructions::executer() {
	Instruction uneInstruction;
	while(1){
		uneInstruction.setOpcode(blue_.receive());
        blue_.receive();
        blue_.receive();//flushing
        uneInstruction.setOperande(blue_.receive());
        blue_.receive();
        blue_.receive();//flushing
        switch(uneInstruction.getOpcode()){
                case att: 
                    delai_ms(uneInstruction.getOperande() * 25);       //25 fois la valeur de l'operande
                    break;
                case dal:
                    del_.allumerDel(uneInstruction.getOperande());
                    break;
                case det:
                    del_.fermerDel(uneInstruction.getOperande()); 
                    break;
                case sgo: 
                    piezo_.debutSon();
                    piezo_.setFrequence(uneInstruction.getOperande());
                    break;
                case sar: 
                    piezo_.arretSon();
                    break;
                case mar: 
                    moteur_.arreter();
                    break;
                case 0x61:
                    moteur_.arreter();
                    break;
                case mav:
                    moteur_.avancer(uneInstruction.getOperande()); 
                    break;
                case mre: 
                    moteur_.reculer(uneInstruction.getOperande());
                    break;
                case trd: 
                    moteur_.tournerDroite();
                    break;
                case trg: 
                    moteur_.tournerGauche();
                    break;
                case dbc:
                    //not implemented yet
                    break;
                case fbc:
                	//not implemented yet
                    break;
                case fin: 
                    finProg_ = true;
                    moteur_.arreter();
                    break;
        }
	}
}
