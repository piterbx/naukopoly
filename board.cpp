#include "board.h"
#include <iostream>
#include <string>
Board::Board()
{
    fields[0].setFieldName("Start");
    fields[0].setPropertyPrice(0);

    fields[1].setFieldName("Uniwersytet Rzeszowski");
    fields[1].setPropertyPrice(60);

    fields[2].setFieldName("Wygrana na Loterii");
    fields[2].setPropertyPrice(100);

    fields[3].setFieldName("Politechnika Rzeszowska");
    fields[3].setPropertyPrice(100);

    fields[4].setFieldName("Karta specjalna");
    fields[4].setPropertyPrice(0);

    fields[5].setFieldName("Podatek");
    fields[5].setPropertyPrice(200);

    fields[6].setFieldName("Uniwersytet Łódzki");
    fields[6].setPropertyPrice(120);

    fields[7].setFieldName("Bilet na powrót do domu");
    fields[7].setPropertyPrice(50);

    fields[8].setFieldName("Politechnika Łódzka");
    fields[8].setPropertyPrice(100);

    fields[9].setFieldName("Akademia Sztuk Pięknych");
    fields[9].setPropertyPrice(130);

    fields[10].setFieldName("Więzienie");
    fields[10].setPropertyPrice(0);

    fields[11].setFieldName("Politechnika Gdańska");
    fields[11].setPropertyPrice(150);

    fields[12].setFieldName("Karta specjalna");
    fields[12].setPropertyPrice(0);

    fields[13].setFieldName("Uniwersytet Gdański");
    fields[13].setPropertyPrice(120);

    fields[14].setFieldName("Akademia Muzyczna");
    fields[14].setPropertyPrice(130);

    fields[15].setFieldName("Podatek");
    fields[15].setPropertyPrice(200);

    fields[16].setFieldName("Politechnika Poznańska");
    fields[16].setPropertyPrice(170);

    fields[17].setFieldName("Bilet na powrót do domu");
    fields[17].setPropertyPrice(50);

    fields[18].setFieldName("Uniwersytet Przyrodniczy");
    fields[18].setPropertyPrice(90);

    fields[19].setFieldName("Uniwersytet Ekonomiczny");
    fields[19].setPropertyPrice(80);

    fields[20].setFieldName("Płatny parking");
    fields[20].setPropertyPrice(80);

    fields[21].setFieldName("Uniwersytet Jagielloński");
    fields[21].setPropertyPrice(200);

    fields[22].setFieldName("Karta specjalna");
    fields[22].setPropertyPrice(0);

    fields[23].setFieldName("AGH");
    fields[23].setPropertyPrice(210);

    fields[24].setFieldName("Politechnika Krakowska");
    fields[24].setPropertyPrice(190);

    fields[25].setFieldName("Podatek");
    fields[25].setPropertyPrice(200);

    fields[26].setFieldName("UMCS");
    fields[26].setPropertyPrice(160);

    fields[27].setFieldName("Politechnika Lubelska");
    fields[27].setPropertyPrice(220);

    fields[28].setFieldName("Kazik");
    fields[28].setPropertyPrice(40);

    fields[29].setFieldName("Uniwersytet Medyczny");
    fields[29].setPropertyPrice(140);

    fields[30].setFieldName("Idź do więzienia");
    fields[30].setPropertyPrice(0);

    fields[31].setFieldName("Politechnika Warszawska");
    fields[31].setPropertyPrice(150);

    fields[32].setFieldName("SGH");
    fields[32].setPropertyPrice(230);

    fields[33].setFieldName("Syrenka warszawska");
    fields[33].setPropertyPrice(50);

    fields[34].setFieldName("WAT");
    fields[34].setPropertyPrice(80);

    fields[35].setFieldName("Podatek");
    fields[35].setPropertyPrice(200);

    fields[36].setFieldName("Karta specjalna");
    fields[36].setPropertyPrice(0);

    fields[37].setFieldName("Uniwersytet Wrocławski");
    fields[37].setPropertyPrice(90);

    fields[38].setFieldName("Bilet na powrót do domu");
    fields[38].setPropertyPrice(50);

    fields[39].setFieldName("Politechnika Wrocławska");
    fields[39].setPropertyPrice(140);


}
