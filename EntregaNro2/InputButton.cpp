#include "InputButton.h"

struct UndavInputButton::Button
{
    UndavInput::Input *input;
};

UndavInputButton::Button* UndavInputButton::CreateButton(string name){

    Button* nuevoButton = new Button;

    nuevoButton->input = UndavInput::CreateInput(UndavInput::SubmitButton);

    UndavInput::SetName(nuevoButton->input,name);

    return nuevoButton;

}

UndavInput::Input* UndavInputButton::GetInputElement(Button* button){
    return button->input;
}

void UndavInputButton::DestroyButton(Button* button){
    delete button;
}


