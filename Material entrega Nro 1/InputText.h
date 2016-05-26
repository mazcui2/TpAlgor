#ifndef INPUTTEXT_H_
#define INPUTTEXT_H_

#include "Input.h"
#include <string>

using std::string;
using UndavInput::Input;

namespace UndavInputTextBox{
	struct TextBox;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Input, que representa un input de tipo Text
	 * Esta instancia tiene valores vacios en los atributos: Value y Name
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputTextBox.
	 * Parametros:
	 * 		@return: Instancia valida de TextBox
	 */
	TextBox* CreateTextBox();

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Input, que representa un input de tipo Text
	 * Esta instancia tiene como atributo name el valor especificado en @name.
	 * Esta instancia tiene valor vacio en el atributo value.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputTextBox.
	 * Parametros:
	 * 		@name: Valor que se desea asignar en el atributo "name" del TextBox
	 * 		@return: Instancia valida de TextBox
	 */
	TextBox* CreateTextBox(string name);

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Input, que representa un input de tipo Text
	 * Esta instancia tiene como atributo name el valor especificado en @name.
	 * Esta instancia tiene como atributo value el valor especificado en @defaultValue.
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInputTextBox.
	 * Parametros:
	 * 		@name: Valor que se desea asignar en el atributo "name" del TextBox
	 * 		@defaultValue: Valor que se desea asignar por defecto en el texto (atributo value del input)
	 * 		@return: Instancia valida de TextBox
	 */
	TextBox* CreateTextBox(string name, string defaultValue);

	/*
	 * Precondicion: @textBox fue creado por la primitiva CreateTextBox
	 * Postcondicion: Devuelve el Input que representa @textBox
	 * Parametros:
	 * 		@textBox: Instancia de TextBox de la cual se desea consultar su representacion en Input
	 * 		@return: Input que representa a @textBox
	 */
	Input* GetInputElement(TextBox* textBox);

	/*
	 * Precondicion: @textBox fue construido con la primitiva CreateTextBox
	 * Postcondicion: Libera todos los recursos de @textBox
	 */
	void DestroyTextBox(TextBox* textBox);
}

#endif
