#include "VasRobot.h"

bool VasRobot::start(Bludiste & map) { 

    // Tady muzete doplnit kod pro inicializaci robota

    return true; 
}

bool VasRobot::start(BludisteOdkryte & map) { 

    // Tady muzete doplnit kod pro inicializaci robota pri prochazeni znameho bludiste

    return true; 
}

bool VasRobot::stop() {

    // Tady muzete doplnit kod pro zastaveni robota

   return true;
}

void VasRobot::krok(Bludiste & map) { 
    
    // Tato metoda se bude opakovat, dokud robot nedosahne cile nebo maximalniho poctu kroku

}

void VasRobot::krok(BludisteOdkryte & map) { 
    
    // Tato metoda se bude opakovat, dokud robot nedosahne cile nebo maximalniho poctu kroku
    // Verze pro odkryte bludiste

}

std::string VasRobot::jmeno() {

    // Tato metoda by mela vratit jmeno robota
    return "JmenoRobota";
}