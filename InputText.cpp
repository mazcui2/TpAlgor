#include "InputText.h"

struct UndavInputTextBox::TextBox
{
    UndavInput::Input *input;
};

UndavInputTextBox::TextBox* UndavInputTextBox::CreateTextBox(){

    TextBox* nuevoTextBox = new TextBox;

    nuevoTextBox->input = UndavInput::CreateInput(UndavInput::TextBox);

    return nuevoTextBox;

}

UndavInputTextBox::TextBox* UndavInputTextBox::CreateTextBox(string name){

    TextBox* nuevoTextBox = new TextBox;

    nuevoTextBox->input = UndavInput::CreateInput(UndavInput::TextBox);

    UndavInput::SetName(nuevoTextBox->input,name);

    return nuevoTextBox;

}

UndavInputTextBox::TextBox* UndavInputTextBox::CreateTextBox(string name,string defaultValue){

    TextBox* nuevoTextBox = new TextBox;

    nuevoTextBox->input = UndavInput::CreateInput(UndavInput::TextBox);

    UndavInput::SetName(nuevoTextBox->input,name);

    UndavInput::SetValue(nuevoTextBox->input,defaultValue);

    return nuevoTextBox;

}
UndavInput::Input* UndavInputTextBox::GetInputElement(TextBox* textBox){
    return textBox->input;
}

void UndavInputTextBox::DestroyTextBox(TextBox* textBox){
    delete textBox;
}
