#include <iostream>
#include <string>
#include "Input.h"
#include "Select.h"
#include "OptionItem.h"
#include "RadioButtonList.h"
#include "InputRadioButton.h"

using std::cout;
using std::endl;
using std::string;
using UndavSelect::Select;
using UndavRadioButtonList::RadioButtonList;
using UndavInputRadio::RadioButton;

void PruebaSelect();
UndavSelect::Select* CrearPeliculas();

void PruebaRadioButtonList();
UndavRadioButtonList::RadioButtonList* CrearEstadosCiviles();

int main() {
	PruebaSelect();
	PruebaRadioButtonList();
}

void PruebaSelect(){
	UndavSelect::Select* peliculas = CrearPeliculas();
	UndavSelect::RemoveOption(peliculas, 2);
	UndavSelect::RemoveOption(peliculas, 200000);
	UndavSelect::SelectItem(peliculas, 1);
	UndavSelect::RemoveOption(peliculas, UndavSelect::GetSelectedItem(peliculas));
	UndavSelect::AddOption(peliculas, UndavOptionItem::CreateOptionItem("Ultima pelicula", "last"));
	cout<<UndavSelect::GetHtmlText(peliculas)<<endl;
	UndavSelect::DestroySelect(peliculas);
}

UndavSelect::Select* CrearPeliculas()
{
	char **movies = new char* [3];
	movies[0] = new char[8];
	movies[1] = new char[7];
	movies[2] = new char[5];
	movies[0][0]='a';movies[0][1]='b';movies[0][2]='c';movies[0][3]=',';movies[0][4]='0';movies[0][5]='0';movies[0][6]='7';movies[0][7]='\0';
	movies[1][0]='x';movies[1][1]='y';movies[1][2]='z';movies[1][3]=',';movies[1][4]='0';movies[1][5]='9';movies[1][6]='\0';
	movies[2][0]='o';movies[2][1]=',';movies[2][2]='r';movies[2][3]='o';movies[2][4]='\0';

	return UndavSelect::CreateSelectFor("movie", movies, 3);
}


void PruebaRadioButtonList()
{
	UndavRadioButtonList::RadioButtonList* estadosCiviles = CrearEstadosCiviles();
	cout<<"Cantidad de estados civiles: "<<UndavRadioButtonList::Count(estadosCiviles)<<endl;
        UndavInputRadio::RadioButton* nuevoRadioButton=UndavRadioButtonList::GetRadioButton(estadosCiviles, 1);
	UndavInputRadio::Check(nuevoRadioButton);
	UndavInputRadio::RadioButton* estadoCivilSeleccionado = UndavRadioButtonList::GetSelectedRadioButton(estadosCiviles);
	cout<<"Estado civil seleccionado: "<<UndavInput::GetHtmlText(UndavInputRadio::GetInputElement(estadoCivilSeleccionado))<<endl;
	UndavRadioButtonList::DestroyRadioButtonList(estadosCiviles);
}



UndavRadioButtonList::RadioButtonList* CrearEstadosCiviles(){
	char **estadosCiviles = new char* [3];
	estadosCiviles[0] = new char[8];
	estadosCiviles[1] = new char[7];
	estadosCiviles[2] = new char[5];
	estadosCiviles[0][0]='s';estadosCiviles[0][1]='o';estadosCiviles[0][2]='l';estadosCiviles[0][3]='t';estadosCiviles[0][4]='e';estadosCiviles[0][5]='r';estadosCiviles[0][6]='o';estadosCiviles[0][7]='\0';
	estadosCiviles[1][0]='c';estadosCiviles[1][1]='a';estadosCiviles[1][2]='s';estadosCiviles[1][3]='a';estadosCiviles[1][4]='d';estadosCiviles[1][5]='o';estadosCiviles[1][6]='\0';
	estadosCiviles[2][0]='o';estadosCiviles[2][1]='t';estadosCiviles[2][2]='r';estadosCiviles[2][3]='o';estadosCiviles[2][4]='\0';
        string name="estadoCivil";
	return UndavRadioButtonList::CreateRadioButtonListFor(name, estadosCiviles, 3);

}
