#include <string.h>
#include "InputText.h"
#include "InputCheckBox.h"
#include "Select.h"
#include "RadioButtonList.h"
#include "InputButton.h"
#include<iostream>

#include "Form.h"
using namespace std;

using std::string;
using UndavInputTextBox::TextBox;
using UndavInputCheckBox::CheckBox;
using UndavSelect::Select;
using UndavRadioButtonList::RadioButtonList;
using UndavInputButton::Button;

    enum  elementsHtmlType{
        Input,
        Select,
        RadioButtonList,
        InputButton,
        SubmitButton
    };

    struct Elements{
            elementsHtmlType Type;
            void* elements;
            string name;
            Elements* next;
    };

	struct UndavForm::Form{
        OnFormSubmitted submitFunction; //Contiene la funcion que se ejecuta cunado se hace el submit del form.
        bool hasSubmitButton;
        Elements* elements;
	};

	typedef void (*OnFormSubmitted)(UndavForm::Form* form);


	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Form, que representa un formulario vacio de elementos.
	 * Parametros:
	 * 		@onSubmitted: Funcion que será invocada al invocar la primitiva Form::Submit si el formulario tiene un elemento Button
	 * 		@return: Instancia valida de Form, que representa  un formulario vacio
	 */
	UndavForm::Form* UndavForm::CreateForm(OnFormSubmitted onSubmitted){
        Form* form = new Form;
        form->elements = new Elements;
        form->submitFunction = onSubmitted;
        form->hasSubmitButton = false;
        return form;
	}

	Elements* CreateElement(string fieldName, elementsHtmlType elementType, void* element){
        Elements* elements = new Elements;
        elements->name = fieldName;
        elements->Type = elementType;
        elements->elements = element;

        return elements;
	}

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega un nuevo campo al formulario de tipo Input con @fieldName como nombre asociado.
	 * Si el input es de tipo SubmitButton no realiza ninguna accion. Para agregar un button submit se debe
	 * usar la primitiva AddSubmitButton.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el nuevo campo
	 * 		@fieldName: Nombre del campo asociado al elemento del formulario html @input
	 * 		@input: Elemento de formulario html Input que se desea agregar como campo en @form
	 */
	void UndavForm::AddField(Form* form, string fieldName, UndavInput::Input* input){
        if (!form->hasSubmitButton){
            Elements* auxElement = form->elements;
            auxElement = CreateElement(fieldName, Input, input);

            //Ojo con esto!
            if  (form->elements != NULL){
                while(auxElement->next != NULL ){
                    auxElement = auxElement->next;
                    cout<<1<<endl;
                }
            }
            //Ojo con esto!

        }
	}

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega un nuevo campo al formulario de tipo Select con @fieldName como nombre asociado
	 * al mismo.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el nuevo campo
	 * 		@fieldName: Nombre del campo asociado al elemento del formulario html @checkBox
	 * 		@checkBox: Elemento de formulario html que se desea agregar como campo en @form
	 */
	void UndavForm::AddField(Form* form, string fieldName, UndavSelect::Select* select){
        if (!form->hasSubmitButton){
            Elements* auxElement = form->elements;
            auxElement = CreateElement(fieldName, Select, select);

            //Ojo con esto!
            if  (form->elements != NULL){
                while(auxElement->next != NULL){
                    auxElement = auxElement->next;
                }
            }
            //Ojo con esto!
        }
	}

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega un nuevo campo al formulario de tipo Select con @fieldName como nombre asociado
	 * al mismo.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el nuevo campo
	 * 		@fieldName: Nombre del campo asociado al elemento del formulario html @radioButtons
	 * 		@radioButtons: Elemento de formulario html que se desea agregar como campo en @form
	 */
	void UndavForm::AddField(UndavForm::Form* form, string fieldName, UndavRadioButtonList::RadioButtonList* radioButtons){
         if (!form->hasSubmitButton){
            Elements* auxElement = form->elements;
            auxElement = CreateElement(fieldName, RadioButtonList, radioButtons);

            //Ojo con esto!
            if  (form->elements != NULL){
                while(auxElement->next != NULL){
                    auxElement = auxElement->next;
                }
            }
            //Ojo con esto!
        }
	}

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega el elemento de formulario Html que representa el boton que permite confirmar el formulario.
	 * Un formulario solo puede tener un unico submit button por lo tanto si el formulario ya tenia un submit button
	 * lo reemplaza por @submitButton
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el submit button
	 * 		@submitButton: Button submit que se desea establecer al formulario
	 */
	void UndavForm::SetSubmitButton(Form* form, UndavInputButton::Button* submitButton){
            Elements* auxElement = form->elements;

            //Ojo con esto!
            if  (form->elements != NULL){
                while(auxElement->next != NULL && auxElement->Type == SubmitButton){
                    auxElement = auxElement->next;
                }
            }
            //Ojo con esto!

            if (form->hasSubmitButton)
                auxElement->elements = submitButton;
            else
                auxElement->elements =  CreateElement("NULL", SubmitButton, submitButton);

	}

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Si el formulario posee un submit button invoca a la funcion indicada en la primitiva CreateForm pasandole
	 * como parametro @form. Si no posee un submit button no realiza accion alguna.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea realizar la confirmacion (submit) de que fue completado
	 */
	void UndavForm::Submit(Form* form){
        if (form->hasSubmitButton)
            form->submitFunction(form);
	}



	 string CreateLabel(string name) {
        string htmlText;
        htmlText = "<label>" + name + "</label>\n</br>\n";
        return htmlText;
     }

    string CreateHtmlRadioButtonList(UndavRadioButtonList::RadioButtonList* radioButtons) {
        string htmlText = "";
        int index;
        int countElements = UndavRadioButtonList::Count(radioButtons);
        while (index <= countElements) {
            htmlText = htmlText + UndavInput::GetHtmlText(UndavInputRadio::GetInputElement(UndavRadioButtonList::GetRadioButton(radioButtons, index)));
            if (index % 3 == 0) {
                htmlText = htmlText + "\n";
            }
            index++;
        }
        htmlText = htmlText + "</br>\n";

        return htmlText;
    }
	string UndavForm::GetHtmlText(Form* form){
        Elements* auxElement = form->elements;
        Elements* saveInputButton;
        string html = "<form>\n";
        while (auxElement != NULL) {
            switch(auxElement->Type){
                case Input:
                        if (auxElement->name != "NULL") {

                            html = html + CreateLabel(auxElement->name);
                        }
                        html = html + UndavInput::GetHtmlText((UndavInput::Input*)auxElement->elements);
                    break;
                case RadioButtonList:
                    html = html + CreateLabel(auxElement->name) + CreateHtmlRadioButtonList((UndavRadioButtonList::RadioButtonList*)auxElement->elements);
                    break;
                case Select:
                    html = html + CreateLabel(auxElement->name) + UndavSelect::GetHtmlText((UndavSelect::Select*)auxElement->elements) + "</br>\n";
                    break;
                case InputButton:
                    saveInputButton = auxElement;
                    break;
                default:
                  break;
            }
        }
        auxElement = auxElement->next;
	}


	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Obtiene un string que equivale a la concatenacion de la secuencia name=value separados por  el caracter &, donde name
	 * es el valor del atributo name del elemento y value es el valor del atributo value del elemento. Concatena todos los elementos de formulario, excepto
	 * el submit button del formulario.
	 * Parametros:
	 * 		@form: Instancia del formulario de la cual se desea obtener el string que lo representa
	 * 		@return: Representacion del formulario que permite enviarse en peticiones HTTP Post por query string
	 * 	Ejemplos:
	 *
	 * 	(1)Si el formulario solo tiene un input (de cualquier tipo): <input type="noImportaElTipo" name="email" value="ejemplo@gmail.com">
	 * 	Se obtiene: email=ejemplo@gmail
	 *
	 * 	(2)Si el formulario solo tiene un input (de cualquier tipo) el cual no tiene atributo name o esta vacio: <input type="noImportaElTipo" name="" value="ejemplo@gmail.com">
	 * 	Se obtiene un string vacio: email=ejemplo@gmail
	 *
	 * 	(3)Si el formulario solo tiene un input (de cualquier tipo) el cual tiene atributo name pero no tiene value o esta vacio el value: <input type="noImportaElTipo" name="email" value="">
	 * 	Se obtiene el siguiente string: email=
	 *
	 * 	(4)Si el formulairo solo tiene un select: <select name="mascota"><option value="perro">Tengo un perro</option><option value="gato">Tengo un gato</option><option selected value="canario">Tengo un canario</option></select>
	 * 	Se obtiene el siguiente string: mascota=canario
	 * 	Notar que  se obtiene el elemento seleccionado solamente. Si el select no tiene elemento seleccionado se obtiene un string vacio
	 *
	 * 	(5)Si el formulario solo tiene un radio button list: <input type="radio" name="subscripccion" value="diaria"> <input selected type="radio" name="subscripccion" value="semanal"> <input type="radio" name="subscripccion" value="quincenal"> <input type="radio" name="subscripccion" value="mensual">
	 * 	Se obtiene el siguiente string: subscripcion=semanal
	 * 	Notar que se obtiene el elemento seleccionado solamente. Si el radio button list no tiene elemento seleccionado se obtiene un string vacio
	 *
	 * 	(6) Si el formulario tiene  los elementos del ejemplo 1, 4 y 5 se obtiene el siguiente string: email=ejemplo@gmail&mascota=canario&subscripcion=semanal
	 *
	 */
	string UndavForm::Serialize(UndavForm::Form* form){
	string serialize = "";
    UndavInputRadio::RadioButton* radioButtonToCheck;
    UndavOptionItem::OptionItem* optionItemToCheck;
    Elements* auxElement = form->elements;
    while (auxElement != NULL) {
        switch (auxElement->Type) {
            case Input:
                if (UndavInput::GetName((UndavInput::Input*)auxElement->elements) != "") {
                    serialize = serialize + UndavInput::GetName((UndavInput::Input*)auxElement->elements) + "=" + UndavInput::GetValue((UndavInput::Input*)auxElement->elements);
                    if (auxElement->next != NULL) {
                        serialize = serialize + "&";
                    }
                }
                break;

            case RadioButtonList:
                radioButtonToCheck = UndavRadioButtonList::GetSelectedRadioButton((UndavRadioButtonList::RadioButtonList*)auxElement->elements);
                if (radioButtonToCheck != NULL) {
                    serialize = serialize + UndavInput::GetName(UndavInputRadio::GetInputElement(radioButtonToCheck)) + "=" + UndavInput::GetValue(UndavInputRadio::GetInputElement(radioButtonToCheck));
                    if (auxElement->next != NULL) {
                        serialize = serialize + "&";
                    }
                }
                break;

            case Select:
                optionItemToCheck = UndavSelect::GetSelectedItem((UndavSelect::Select*)auxElement->elements);
                if (optionItemToCheck != NULL) {
                    serialize = serialize + UndavOptionItem::GetText(optionItemToCheck) + "=" + UndavOptionItem::GetValue(optionItemToCheck);
                    if (auxElement->next != NULL) {
                        serialize = serialize + "&";
                    }
                }
                break;

        }
        auxElement = auxElement->next;
    }
    return serialize;
	}

	/*
	 * Precondicion: @form fue construido con la primitiva CreateForm
	 * Postcondicion: Libera todos los recursos de @form
	 */
	void UndavForm::DestroyForm(UndavForm::Form* form){
        Elements* auxElement = form->elements;
        Elements* toDestroy;
        while (auxElement != NULL) {
            switch (auxElement->Type) {

                case Input:
                    UndavInput::DestroyInput((UndavInput::Input*)auxElement->elements);
                    break;

                case RadioButtonList:
                    UndavRadioButtonList::DestroyRadioButtonList((UndavRadioButtonList::RadioButtonList*)auxElement->elements);
                    break;

                case Select:
                    UndavSelect::DestroySelect((UndavSelect::Select*)auxElement->elements);
                    break;
                case InputButton:
                    UndavInputButton::DestroyButton((UndavInputButton::Button*)auxElement->elements);
                    break;
            }
            toDestroy = auxElement;
            auxElement = auxElement->next;
            delete toDestroy;
        }
        delete auxElement;
        delete form;
    }



