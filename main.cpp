#include "Prohledavac.h"
#include "Bludiste.h"

// include na hlavicku vasi tridy
#include "VasRobot.h" 

#include <string>
#include <iostream>
#include <vector>
#include <memory>

const std::vector<std::string> vstupniSoubory = {
	"PRAZDNY_bludiste.dat",
	"ZED1_bludiste.dat",
	"ZED2_bludiste.dat",
	"NAHODNY_bludiste.dat",
	"LABYRINT_bludiste.dat"
};

int main() {

    // Nacteni vstupnich souboru ze seznamu vzdy jako zakryte i odkryte bludiste
  
    std::vector<std::shared_ptr<Bludiste>> ukoly;

    for (const auto& nazevSouboru : vstupniSoubory) {
        ukoly.push_back(std::make_shared<Bludiste>(nazevSouboru));
        ukoly.push_back(std::make_shared<BludisteOdkryte>(nazevSouboru));
    }
    
    std::shared_ptr<Prohledavac> robot = std::make_shared<VasRobot>(); // tady doplnite misto "VasRobot" tridu vaseho robota

    // Ted se pokusime pomoci robota projit vsechna bludiste
    
    for (auto & bludiste : ukoly) {
        std::cout << "Prohledavam bludiste " << bludiste->nazev() << ": \n";
        
        if (!robot->start(*bludiste))
            std::cout << "Nepodarilo se inicializovat robota :(\n";
        else {

            // Maximalni pocet kroku robota je omezeny zde
            for (int i=0; i < 100000 && !bludiste->cil(); ++i) {
                robot->krok(*bludiste);
            }
        
            if (bludiste->cil())    
                std::cout << robot->jmeno() << " potreboval " << bludiste->pocet_kroku() << " kroku a " << bludiste->pocet_narazu() << " narazu.\n";
            else 
                std::cout << robot->jmeno() << " nenasel cestu.\n";
            
            if (!robot->stop())
                std::cout << "Pomoc, robota nejde vypnout!!!\n";
        }

	bludiste->uloz_cestu(bludiste->nazev() + "_cesta.dat");
    }

    return 0;
}
