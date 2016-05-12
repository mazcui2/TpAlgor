#ifndef INPUTBUTTON_H_
#define INPUTBUTTON_H_

#include "Input.h"
#include <string>

using std::string;
using UndavInput::Input;

namespace UndavInputButton{
	struct Button;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Button, que representa un input de tipo button submit
	 * Esta instancia tiene como atributo value el valor especificado en @value.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputButton.
	 * Parametros:
	 * 		@value: Valor que se desea asignar en el atributo "value" del Button
	 * 		@return: Instancia valida de Button
	 */
	Button* CreateButton(string name);

	/*
	 * Precondicion: @button fue creado por la primitiva CreateButton
	 * Postcondicion: Devuelve el Input que representa @button
	 * Parametros:
	 * 		@button: Instancia de Button de la cual se desea consultar su representacion en Input
	 * 		@return: Input que representa a @button
	 */
	Input* GetInputElement(Button* button);

	/*
	 * Precondicion: @button fue construido con la primitiva CreateButton
	 * Postcondicion: Libera todos los recursos de @button
	 */
	void DestroyButton(Button* button);
}

#endif
