#ifndef INPUTRADIOBUTTON_H_
#define INPUTRADIOBUTTON_H_

#include "Input.h"
#include <string>

using std::string;
using UndavInput::Input;

namespace UndavInputRadio{
	struct RadioButton;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de RadioButton, que representa input de tipo radio
	 * Esta instancia tiene valores vacios en los atributos: Value y Name
	 * Esta instancia tiene el radio button unchecked.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputRadio.
	 * Parametros:
	 * 		@return: Instancia valida de RadioButton
	 */
	RadioButton* CreateRadioButton();

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de RadioButton, que representa un input de tipo radio
	 * Esta instancia tiene como atributo name el valor especificado en @name.
	 * Esta instancia tiene como atributo value el valor especificado en @value.
	 * Esta instancia tiene el radio button.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputRadio.
	 * Parametros:
	 * 		@name: Valor que se desea asignar en el atributo "name" del RadioButton
	 * 		@value: Valor que se desea asignar en el atributo "value" del RadioButton
	 * 		@return: Instancia valida de RadioButton
	 */
	RadioButton* CreateRadioButton(string name, string value);

	/*
	 * Precondicion: @radioButton fue creado por la primitiva CreateRadioButton
	 * Postcondicion: Devuelve el Input que representa @radioButton
	 * Parametros:
	 * 		@radioButton: Instancia de RadioButton de la cual se desea consultar su representacion en Input
	 * 		@return: Input que representa a @radioButton
	 */
	Input* GetInputElement(RadioButton* radioButton);

	/*
	 * Precondicion: @radioButton fue creado por la primitiva CreateRadioButton
	 * Postcondicion: Establece como chequeado a @radioButton
	 * Parametros:
	 * 		@radioButton: Instancia de RadioButton a la cual se desea hacer un check
	 */
	void Check(RadioButton* radioButton);

	/*
	 * Precondicion: @radioButton fue creado por la primitiva CreateRadioButton
	 * Postcondicion: Establece como no chequeado a @radioButton
	 * Parametros:
	 * 		@radioButton: Instancia de RadioButton a la cual se desea hacer el un-check
	 */
	void Uncheck(RadioButton* radioButton);

	/*
	 * Precondicion: @radioButton fue creado por la primitiva CreateRadioButton
	 * Postcondicion: Devuelve true si @radioButton esta chequeado. Caso contrario devuelve false
	 * Parametros:
	 * 		@radioButton: Instancia de RadioButton a la cual se desea saber si esta checkeado
	 * 		@return: Valor que determina si @radioButton esta chequeado o no
	 */
	bool IsChecked(RadioButton* radioButton);


	/*
	 * Precondicion: @radioButton fue construido con la primitiva CreateRadioButton
	 * Postcondicion: Libera todos los recursos de @radioButton
	 */
	void DestroyRadioButton(RadioButton* radioButton);
}

#endif
