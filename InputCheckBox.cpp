#include "InputCheckBox.h"

struct UndavInputCheckBox::CheckBox
{
    UndavInput::Input *input;
};

UndavInputCheckBox::CheckBox* UndavInputCheckBox::CreateCheckBox(){

    CheckBox* nuevoCheckBox = new CheckBox;

    nuevoCheckBox->input = UndavInput::CreateInput(UndavInput::CheckBox);

    return nuevoCheckBox;

}

UndavInputCheckBox::CheckBox* UndavInputCheckBox::CreateCheckBox(string name,string value){

    CheckBox* nuevoCheckBox = new CheckBox;

    nuevoCheckBox->input = UndavInput::CreateInput(UndavInput::CheckBox);

    UndavInput::SetName(nuevoCheckBox->input,name);

    UndavInput::SetValue(nuevoCheckBox->input,value);

    return nuevoCheckBox;

}

UndavInput::Input* UndavInputCheckBox::GetInputElement(CheckBox* checkBox){
    return checkBox->input;
}
