#include <iostream>
#include "Input.h"
#include "InputText.h"
#include "InputCheckBox.h"
#include "InputRadioButton.h"
#include "InputButton.h"
#include <string>

using std::string;
using std::cout;
using std::endl;
using namespace UndavInput;
using namespace UndavInputTextBox;
using namespace UndavInputRadio;
using namespace UndavInputCheckBox;
using namespace UndavInputButton;

void PruebaFormularioSubscripcion();
void MostrarCampoInput(string nombreCampo, Input* input);
void MostrarCampoCheckeable(string texto, Input* input, bool agregarNuevaLinea);
void MostrarComienzoFormulario();
void MostrarFinFormulario(Button* submit);

int main() {
	PruebaFormularioSubscripcion();
	return 0;
}

void PruebaFormularioSubscripcion()
{
	UndavInputTextBox::TextBox* inputNombre = CreateTextBox("nombre");
	UndavInputTextBox::TextBox* inputEmail = CreateTextBox("email");
	UndavInputRadio::RadioButton* inputResumenDiario = CreateRadioButton("resumen", "diario");
	UndavInputRadio::RadioButton* inputResumenSemanal = CreateRadioButton("resumen", "semanal");
	UndavInputRadio::RadioButton* inputResumenQuincenal = CreateRadioButton("resumen", "quincenal");
	UndavInputCheckBox::CheckBox* inputAceptaTerminos = CreateCheckBox("confirmacion", "true");
	UndavInputButton::Button* submit = UndavInputButton::CreateButton("Suscribirme!");

	MostrarComienzoFormulario();
	MostrarCampoInput("Nombre", UndavInputTextBox::GetInputElement(inputNombre));
	MostrarCampoInput("Email", UndavInputTextBox::GetInputElement(inputEmail));
	MostrarCampoCheckeable("Quiero un resumen diario", UndavInputRadio::GetInputElement(inputResumenDiario), false);
	MostrarCampoCheckeable("Quiero un resumen semanal", UndavInputRadio::GetInputElement(inputResumenSemanal), false);
	MostrarCampoCheckeable("Quiero un resumen quincenal", UndavInputRadio::GetInputElement(inputResumenQuincenal), true);
	MostrarCampoCheckeable("Acepto los terminos y condiciones", UndavInputCheckBox::GetInputElement(inputAceptaTerminos), true);
	MostrarFinFormulario(submit);

}

void MostrarCampoInput(string nombreCampo, Input* input)
{
	cout<<nombreCampo<<":"<<"<br>"<<endl;
	cout<<UndavInput::GetHtmlText(input)<<endl;
	cout<<"<br>"<<endl;
}

void MostrarCampoCheckeable(string texto, Input* input, bool agregarNuevaLinea)
{
	cout<<UndavInput::GetHtmlText(input)<<" "<<texto;
	if(agregarNuevaLinea)
	{
		cout<<"<br>"<<endl;
	}
}

void MostrarComienzoFormulario()
{
	cout<<"<!DOCTYPE html>"<<endl;
	cout<<"<html>"<<endl;
	cout<<"<body>"<<endl;
	cout<<"<form>"<<endl;
}

void MostrarFinFormulario(Button* submit)
{
	cout<<"<br><br>"<<endl;
	cout<<UndavInput::GetHtmlText(UndavInputButton::GetInputElement(submit))<<endl;
	cout<<"</form>"<<endl;
	cout<<"</body>"<<endl;
	cout<<"</html>"<<endl;
}
