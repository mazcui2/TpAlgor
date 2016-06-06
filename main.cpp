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

void PruebaSelect();
Select* CrearPeliculas();

void PruebaRadioButtonList();
RadioButtonList* CrearEstadosCiviles();

int main() {
	PruebaSelect();
	PruebaRadioButtonList();
}

void PruebaSelect()
{
	Select* peliculas = CrearPeliculas();
    UndavSelect::RemoveOption(peliculas, 2);
	UndavSelect::RemoveOption(peliculas, 200000);
	UndavSelect::RemoveOption(peliculas, UndavSelect::GetSelectedItem(peliculas));
	UndavSelect::SelectItem(peliculas, 1);
	UndavSelect::RemoveOption(peliculas, UndavSelect::GetSelectedItem(peliculas));
	UndavSelect::AddOption(peliculas, UndavOptionItem::CreateOptionItem("Ultima pelicula", "last"));

	cout<<UndavSelect::GetHtmlText(peliculas)<<endl;
	UndavSelect::DestroySelect(peliculas);
}

void PruebaRadioButtonList()
{
	RadioButtonList* estadosCiviles = CrearEstadosCiviles();
	cout<<"Cantidad de estados civiles: "<<UndavRadioButtonList::Count(estadosCiviles)<<endl;
	UndavInputRadio::Check(UndavRadioButtonList::GetRadioButton(estadosCiviles, 1));
	UndavInputRadio::RadioButton* estadoCivilSeleccionado = UndavRadioButtonList::GetSelectedRadioButton(estadosCiviles);
	cout<<"Estado civil seleccionado: "<<UndavInput::GetHtmlText(UndavInputRadio::GetInputElement(estadoCivilSeleccionado))<<endl;
	UndavRadioButtonList::DestroyRadioButtonList(estadosCiviles);
}


Select* CrearPeliculas()
{
	char **movies = new char* [5];
	for(int i =0; i <5 ;++i)
	{
		movies[i] = new char[2];
		for(int j = 0; j <2;++j)
		{
			movies[i][j] = '\0';
		}
		movies[i][0]=i;
	}
	return UndavSelect::CreateSelectFor("movie", movies, 5);
}

RadioButtonList* CrearEstadosCiviles()
{
	char **estadosCiviles = new char* [3];
	estadosCiviles[0] = new char[8];
	estadosCiviles[1] = new char[7];
	estadosCiviles[2] = new char[5];
	estadosCiviles[0][0]='s';estadosCiviles[0][1]='o';estadosCiviles[0][2]='l';estadosCiviles[0][3]='t';estadosCiviles[0][4]='e';estadosCiviles[0][5]='r';estadosCiviles[0][6]='o';estadosCiviles[0][6]='\0';
	estadosCiviles[1][0]='c';estadosCiviles[1][1]='a';estadosCiviles[1][2]='s';estadosCiviles[1][3]='a';estadosCiviles[1][4]='d';estadosCiviles[1][5]='o';estadosCiviles[1][6]='\0';
	estadosCiviles[2][0]='o';estadosCiviles[2][1]='t';estadosCiviles[2][2]='r';estadosCiviles[2][3]='o';estadosCiviles[2][4]='\0';
	return UndavRadioButtonList::CreateRadioButtonListFor("estadoCivil", estadosCiviles, 3);
}
