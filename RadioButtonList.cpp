#include "RadioButtonList.h"

struct RadioButtonList{
    string name;
    UndavInputRadio::RadioButton radioButton[];
};

RadioButtonList* CreateRadioButtonList(string name){
    RadioButtonList* radioButtonList = new RadioButtonList;
    radioButtonList->name = name;
    return radioButtonList;
}


RadioButton* GetRadioButton(RadioButtonList* radioButtons, int radioButtonIndex){
    int countRadios = 0;

    while(radioButtonIndex > countRadios)
        countRadios++;

    if(radioButtonIndex != countRadios)
        return NULL;
    else
        return radioButtons.radioButton[radioButtonIndex];
}
