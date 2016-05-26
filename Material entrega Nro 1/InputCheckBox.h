#ifndef INPUTCHECKBOX_H_
#define INPUTCHECKBOX_H_

#include "Input.h"
#include <string>

using std::string;
using UndavInput::Input;

namespace UndavInputCheckBox{
	struct CheckBox;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de CheckBox, que representa input de tipo checkbox
	 * Esta instancia tiene valores vacios en los atributos: Value y Name
	 * Esta instancia tiene el checkbox unchecked.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputCheckBox.
	 * Parametros:
	 * 		@return: Instancia valida de CheckBox
	 */
	CheckBox* CreateCheckBox();

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de CheckBox, que representa un input de tipo checkbox
	 * Esta instancia tiene como atributo name el valor especificado en @name.
	 * Esta instancia tiene como atributo value el valor especificado en @value.
	 * Esta instancia tiene el checkbox unchecked.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputCheckBox.
	 * Parametros:
	 * 		@name: Valor que se desea asignar en el atributo "name" del CheckBox
	 * 		@value: Valor que se desea asignar en el atributo "value" del CheckBox
	 * 		@return: Instancia valida de CheckBox
	 */
	CheckBox* CreateCheckBox(string name, string value);

	/*
	 * Precondicion: @checkBox fue creado por la primitiva CreateCheckBox
	 * Postcondicion: Devuelve el Input que representa @checkBox
	 * Parametros:
	 * 		@checkBox: Instancia de CheckBox de la cual se desea consultar su representacion en Input
	 * 		@return: Input que representa a @checkBox
	 */
	Input* GetInputElement(CheckBox* checkBox);

	/*
	 * Precondicion: @checkBox fue creado por la primitiva CreateCheckBox
	 * Postcondicion: Establece como chequeado a @checkBox
	 * Parametros:
	 * 		@checkBox: Instancia de CheckBox a la cual se desea hacer un check
	 */
	void Check(CheckBox* checkBox);

	/*
	 * Precondicion: @checkBox fue creado por la primitiva CreateCheckBox
	 * Postcondicion: Establece como no chequeado a @checkBox
	 * Parametros:
	 * 		@checkBox: Instancia de CheckBox a la cual se desea hacer el un-check
	 */
	void Uncheck(CheckBox* checkBox);

	/*
	 * Precondicion: @checkBox fue creado por la primitiva CreateCheckBox
	 * Postcondicion: Devuelve true si @checkBox esta chequeado. Caso contrario devuelve false
	 * Parametros:
	 * 		@checkBox: Instancia de CheckBox a la cual se desea saber si esta checkeado
	 * 		@return: Valor que determina si @checkBox esta chequeado o no
	 */
	bool IsChecked(CheckBox* checkBox);

	/*
	 * Precondicion: @checkBox fue construido con la primitiva CreateCheckBox
	 * Postcondicion: Libera todos los recursos de @checkBox
	 */
	void DestroyCheckBox(CheckBox* checkBox);
}

#endif
