#include "MiniBoss.h"


MiniBoss::MiniBoss() {
    srand(time(NULL));
    int select = rand() % 6;
    if (select == 0) 
        setMonsterAttributes(
            MINIBOSS,
            3,
            "Soberano Corrompido"
        );
    else if (select == 0) 
        setMonsterAttributes(
            MINIBOSS,
            3,
            "Fauno Corrompido"
        );
    else if (select == 0) 
        setMonsterAttributes(
            MINIBOSS,
            3,
            "Dullahan"
        );
    else if (select == 0) 
        setMonsterAttributes(
            MINIBOSS,
            4,
            "T�natos"
        );
    else if (select == 0) 
        setMonsterAttributes(
            MINIBOSS,
            4,
            "N�nive"
        );
    else
        setMonsterAttributes(
            MINIBOSS,
            5,
            "Carniceiro Sanguin�rio"
        );
}