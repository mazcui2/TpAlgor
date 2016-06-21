#include <iostream>
#include "Input.h"
#include "InputText.h"
#include "InputCheckBox.h"
#include "InputRadioButton.h"
#include "InputButton.h"
#include "Form.h"
#include "Select.h"
#include "RadioButtonList.h"
#include "OptionItem.h"
#include <string>

using std::string;
using std::cout;
using std::endl;
using namespace UndavInput;
using namespace UndavInputTextBox;
using namespace UndavInputRadio;
using namespace UndavInputCheckBox;
using namespace UndavInputButton;
using namespace UndavForm;
using namespace UndavSelect;
using namespace UndavRadioButtonList;
using namespace UndavOptionItem;

const string ComandoPost = "post";
const string ComandoMostrar = "mostrar";

typedef void (*TipoFuncionEjecutar)(void* parametro);

enum TipoComando { Ayuda, MostrarFormularioSubscripcion, RealizarPost};

struct Comando{
	TipoFuncionEjecutar ejecutar;
	void* parametro;
};

Comando* CrearComando(int argc, char* argv[]);
TipoComando ObtenerTipoComando(int argc, char* argv[]);
Form* CrearFormulario(OnFormSubmitted accion);
Form* CrearFormularioPreCargado(OnFormSubmitted accion);
bool ComandoValido(string comando);

void MostrarAyuda(void* nombrePrograma);
void ConfirmarFormualario(void* formulario);
void MostrarFormulario(Form* form);
void MostrarHttpPost(Form* form);

int main(int argc, char* argv[]) {
	Comando* comandoSelecionado = CrearComando(argc, argv);
	comandoSelecionado->ejecutar(comandoSelecionado->parametro);

	delete comandoSelecionado;
	return 0;
}

void ConfirmarFormualario(void* formulario)
{
	UndavForm::Submit((Form*) formulario);
	//NO ANDA PIBE
	//UndavForm::DestroyForm((Form*) formulario);
}

void MostrarFormulario(Form* form)
{
	cout<<"<!DOCTYPE html>"<<endl;
	cout<<"<html>"<<endl;
	cout<<"<body>"<<endl;

	cout<<UndavForm::GetHtmlText(form)<<endl;

	cout<<"</body>"<<endl;
	cout<<"</html>"<<endl;
}

void MostrarHttpPost(Form* form)
{
	cout<<"http://www.undav.edu.ar/subscripcion?"<<UndavForm::Serialize(form)<<endl;
}

Form* CrearFormulario(OnFormSubmitted accion)
{
	Form* formulario = CreateForm(accion);
	UndavInputTextBox::TextBox* nombre = CreateTextBox("nombre");
	UndavInputTextBox::TextBox* apellido = CreateTextBox("apellido");
	UndavInputTextBox::TextBox* mail = CreateTextBox("mail");
	UndavSelect::Select* carrera = CreateSelect("carrera");
	UndavRadioButtonList::RadioButtonList* subscripcion = CreateRadioButtonList("subscripcion");
	UndavInputButton::Button* boton = CreateButton("Aceptar");

	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Ingenieria en informatica", "informatica"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Economia", "economia"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Ingenieria en materiales", "materiales"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Licenciatura en gerencia de empresas", "gerencia"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Periodismo", "periodismo"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Abogacia", "abogacia"));

	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "diaria"));
	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "semanal"));
	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "quincenal"));
	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "mensual"));
    cout<<"paso add radio"<<endl;
	UndavForm::AddField(formulario, "Nombre", GetInputElement(nombre));
	UndavForm::AddField(formulario, "Apellido", GetInputElement(apellido));
	UndavForm::AddField(formulario, "Correo electronico", GetInputElement(mail));
	UndavForm::AddField(formulario, "Carrera que cursa", carrera);
	UndavForm::AddField(formulario, "¿Que tipo de subscripcion quiere?", subscripcion);
	cout<<"paso add field"<<endl;
	UndavForm::SetSubmitButton(formulario, boton);
	cout<<"paso submit"<<endl;

	return formulario;
}

Form* CrearFormularioPreCargado(OnFormSubmitted accion)
{
	Form* formulario = CreateForm(accion);

	UndavInputTextBox::TextBox* nombre = CreateTextBox("nombre", "Juan");
	UndavInputTextBox::TextBox* apellido = CreateTextBox("apellido", "Gomez");
	UndavInputTextBox::TextBox* mail = CreateTextBox("mail", "jg@gomez.com");
	UndavSelect::Select* carrera = CreateSelect("carrera");
	UndavRadioButtonList::RadioButtonList* subscripcion = CreateRadioButtonList("subscripcion");
	UndavInputButton::Button* boton = CreateButton("Aceptar");

	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Ingenieria en informatica", "informatica"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Economia", "economia"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Ingenieria en materiales", "materiales"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Licenciatura en gerencia de empresas", "gerencia"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Periodismo", "periodismo"));
	UndavSelect::AddOption(carrera, UndavOptionItem::CreateOptionItem("Abogacia", "abogacia"));

	UndavSelect::SelectItem(carrera, 3);

	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "diaria"));
	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "semanal"));
	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "quincenal"));
	UndavRadioButtonList::AddRadioButton(subscripcion, CreateRadioButton("subscripcion", "mensual"));

	Check(UndavRadioButtonList::GetRadioButton(subscripcion, 2));

	UndavForm::AddField(formulario, "Nombre", GetInputElement(nombre));
	UndavForm::AddField(formulario, "Apellido", GetInputElement(apellido));
	UndavForm::AddField(formulario, "Correo electronico", GetInputElement(mail));
	UndavForm::AddField(formulario, "Carrera que cursa", carrera);
	UndavForm::AddField(formulario, "¿Que tipo de subscripcion quiere?", subscripcion);
	UndavForm::SetSubmitButton(formulario, boton);

	return formulario;
}



Comando* CrearComando(int argc, char* argv[])
{
	TipoComando tipoComando = ObtenerTipoComando(argc, argv);
	tipoComando = MostrarFormularioSubscripcion;
	Comando* comando = NULL;
	switch (tipoComando) {
		case Ayuda:
			comando = new Comando;
			comando->parametro = argv[0];
			comando->ejecutar = MostrarAyuda;
			break;
		case MostrarFormularioSubscripcion:
			comando = new Comando;
			comando->parametro = CrearFormulario(MostrarFormulario);
			cout<<"creo el form"<<endl;
			comando->ejecutar = ConfirmarFormualario;
			break;
		case RealizarPost:
			comando = new Comando;
			comando->parametro = CrearFormulario(MostrarHttpPost);
			comando->ejecutar = ConfirmarFormualario;
			break;
		default:
			break;
	}

	return comando;
}

TipoComando ObtenerTipoComando(int argc, char* argv[])
{
	TipoComando tipoComando = Ayuda;
	if(argc == 2 && ComandoValido(argv[1]))
	{
		string comando = argv[1];
		tipoComando = (comando == ComandoMostrar) ? MostrarFormularioSubscripcion : RealizarPost;
	}
	return tipoComando;
};

void MostrarAyuda(void* nombrePrograma)
{
	cout<<"Usar: ["<<(char*)nombrePrograma<<"] [opcion]"<<endl;
	cout<<"\t [opcion]: Valores validos"<<endl;
	cout<<"\t\t\t["<<ComandoPost<<"]: Escribe en la salida estandar una peticion Http post del formulario"<<endl;
	cout<<"\t\t\t["<<ComandoMostrar<<"]: Escribe en la salida estandar la representacion HTML del formulario"<<endl;
}

bool ComandoValido(string comando)
{
	return comando == ComandoPost || comando == ComandoMostrar;
}
