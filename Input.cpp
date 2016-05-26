#include "Input.h"

struct UndavInput::Input
{
    UndavInput::InputType tipo;
    string nombre;
    string valor;
};

UndavInput::Input* UndavInput::CreateInput(InputType type){
    Input* nuevoInput = new Input;
    nuevoInput->tipo = type;

    return nuevoInput;
}

UndavInput::InputType UndavInput::GetType(Input* input){
    return input->tipo;
}

void UndavInput::SetValue(Input* input, string value){
    input->valor = value;
}

string UndavInput::GetValue(Input* input){
    return input->valor;
}

void UndavInput::SetName(Input* input, string name){
    input->nombre = name;
}

string UndavInput::GetName(Input* input){
    return input->nombre;
}

string UndavInput::GetHtmlText(Input* input){

string mostrarMensaje;

    if (input->tipo == TextBox && input->nombre == "" && input->valor == ""){
        mostrarMensaje = "<input type='text'>";
    }

    if (input->tipo == TextBox && input->nombre != "" && input->valor != ""){
        mostrarMensaje = "<type='text' name='" + input->nombre + "' value='" + input->valor + "'>";
    }

    if (input->tipo == TextBox && input->nombre != ""){
        mostrarMensaje = "<type='text' name='" + input->nombre+"'>";
    }

    if (input->tipo == SubmitButton){
        mostrarMensaje = "<type='submit' value='" + input->nombre + "'>";
    }

    if (input->tipo == CheckBox){
        mostrarMensaje = "<type='checkbox' name='" + input->nombre + "' value='" + input->valor + "'>";
    }

    if (input->tipo == RadioButton){
        mostrarMensaje = "<type='radio' name='" + input->nombre + "' value='" + input->valor + "'>";
    }

    return mostrarMensaje;
}

void UndavInput::DestroyInput(Input* input){
    delete input;
}

