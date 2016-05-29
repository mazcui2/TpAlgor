#include "InputRadioButton.h"

struct UndavInputRadio::RadioButton
{
    UndavInput::Input *input;
    bool valor;
};

UndavInputRadio::RadioButton* UndavInputRadio::CreateRadioButton(){

    RadioButton* nuevoRadioButton = new RadioButton;

    nuevoRadioButton->input = UndavInput::CreateInput(UndavInput::RadioButton);

    return nuevoRadioButton;

}

UndavInputRadio::RadioButton* UndavInputRadio::CreateRadioButton(string name,string value){

    RadioButton* nuevoRadioButton = new RadioButton;

    nuevoRadioButton->input = UndavInput::CreateInput(UndavInput::RadioButton);

    UndavInput::SetName(nuevoRadioButton->input,name);

    UndavInput::SetValue(nuevoRadioButton->input,value);

    return nuevoRadioButton;

}

UndavInput::Input* UndavInputRadio::GetInputElement(RadioButton* radioButton){
    return radioButton->input;
}

void UndavInputRadio::Check(RadioButton* radioButton){
    radioButton->valor = true;
}

void UndavInputRadio::Uncheck(RadioButton* radioButton){
    radioButton->valor = false;
}

bool UndavInputRadio::IsChecked(RadioButton* radioButton){
    return(radioButton->valor);
}

void UndavInputRadio::DestroyRadioButton(RadioButton* radioButton){
    delete radioButton;
}
