#include <string>
#include <iostream>n
#include "Select.h"
#include "RadioButtonList.h"
#include "InputRadioButton.h"
#include "Input.h"

using namespace UndavRadioButtonList;
using namespace UndavInputRadio;
using namespace UndavInput;
using namespace std;
using UndavOptionItem::OptionItem;

struct RadioButtons {
    UndavInputRadio::RadioButton* radioButton;
    int index;
    RadioButtons* next;
};

struct UndavRadioButtonList::RadioButtonList {
    RadioButtons* radioButtons;
    string name;
    int radioButtonsCountIndex;
};

UndavInputRadio::RadioButton* LoadRadioButton(string name, string value) {
    UndavInputRadio::RadioButton* newRadioButton = UndavInputRadio::CreateRadioButton(name, value);
    return newRadioButton;
}

RadioButtons* CreateRadioButtons() {
    RadioButtons* newRadioButton = new RadioButtons;
    newRadioButton->radioButton = NULL;
    newRadioButton->next = NULL;
    return newRadioButton;
}

RadioButtonList* UndavRadioButtonList::CreateRadioButtonList(string name) {
    RadioButtonList* newRadioButtonList = new RadioButtonList;
    newRadioButtonList->name = name;
    newRadioButtonList->radioButtonsCountIndex = 0;
    newRadioButtonList->radioButtons = NULL;
    return newRadioButtonList;
}

RadioButtons* ParserCharRadioButtons(char radioButtons[], string name) {
    char endOfChar = '\0';
    int index = 0;
    string value;
    while (radioButtons[index] != endOfChar) {
        value = value + radioButtons[index];
        index++;
    }
    RadioButtons* newRadioButtons = CreateRadioButtons();
    newRadioButtons->radioButton = LoadRadioButton(name, value);
    return newRadioButtons;
}

RadioButtonList* UndavRadioButtonList::CreateRadioButtonListFor(string name, char *radioButtons[], int radioButtonsCount) {
    RadioButtonList* radioButtonList = CreateRadioButtonList(name);
    if (radioButtonsCount > 0) {
        RadioButtons* newRadioButtons = ParserCharRadioButtons(radioButtons[0], name);
        radioButtonList->radioButtonsCountIndex = radioButtonsCount;
        radioButtonList->radioButtons = newRadioButtons;
        radioButtonList->radioButtons->index = 0;
        radioButtonList->name = name;
        if (radioButtonsCount > 1) {
            for (int i = 1; i < radioButtonsCount; i++) {
                newRadioButtons = ParserCharRadioButtons(radioButtons[i], name);
                newRadioButtons->next = radioButtonList->radioButtons;
                newRadioButtons->index = i;
                radioButtonList->radioButtons = newRadioButtons;
            }
        }
    }
    return radioButtonList;
}

UndavInputRadio::RadioButton* UndavRadioButtonList::GetRadioButton(RadioButtonList* radioButtons, int radioButtonIndex) {
    if (radioButtonIndex <= radioButtons->radioButtonsCountIndex){
        RadioButtons* auxRadioButtons = radioButtons->radioButtons;
        while (auxRadioButtons->next != NULL && auxRadioButtons->index != radioButtonIndex) {
            auxRadioButtons = auxRadioButtons->next;
        }
        if (auxRadioButtons->index == radioButtonIndex)
            return auxRadioButtons->radioButton;
    }
    return NULL;
}

UndavInputRadio::RadioButton* UndavRadioButtonList::GetSelectedRadioButton(RadioButtonList* radioButtons) {
    RadioButtons* auxRadioButtons = radioButtons->radioButtons;

    while (auxRadioButtons->next != NULL && !UndavInputRadio::IsChecked(auxRadioButtons->radioButton)) {
        auxRadioButtons = auxRadioButtons->next;
    }

    if (UndavInputRadio::IsChecked(auxRadioButtons->radioButton))
        return auxRadioButtons->radioButton;

    return NULL;

}

void UndavRadioButtonList::AddRadioButton(RadioButtonList* radioButtons, UndavInputRadio::RadioButton* newRadioButton) {
    RadioButtons* auxRadioButtons = radioButtons->radioButtons;
    if (auxRadioButtons != NULL && auxRadioButtons != 0){
        Input* dataInputRadioButtons = UndavInputRadio::GetInputElement(auxRadioButtons->radioButton);
        Input* dataInputNewRadioButton = UndavInputRadio::GetInputElement(newRadioButton);

        while (UndavInput::GetValue(dataInputRadioButtons) != UndavInput::GetValue(dataInputNewRadioButton) && auxRadioButtons->next != NULL) {
            auxRadioButtons = auxRadioButtons->next;
            dataInputRadioButtons = UndavInputRadio::GetInputElement(auxRadioButtons->radioButton);
        }
    }
     else {
        radioButtons->radioButtons = CreateRadioButtons();
        radioButtons->radioButtonsCountIndex++;
        radioButtons->radioButtons->index = radioButtons->radioButtonsCountIndex;
        radioButtons->radioButtons->radioButton = newRadioButton;
        radioButtons->radioButtons->next = NULL;
    }
}

void DestroyRadioButtons(RadioButtons* radioButtons) {
    UndavInputRadio::DestroyRadioButton(radioButtons->radioButton);
    delete radioButtons;
}

void RemoveRadioButton(RadioButtonList* radioButtons, string value) {
    RadioButtons* actualRadioButtons = radioButtons->radioButtons;
    RadioButtons* previusRadioButtons = actualRadioButtons;
    Input* dataInput = UndavInputRadio::GetInputElement(radioButtons->radioButtons->radioButton);

    while (UndavInput::GetValue(dataInput) != value && actualRadioButtons->next != NULL) {
        previusRadioButtons = actualRadioButtons;
        actualRadioButtons = actualRadioButtons->next;
        dataInput = UndavInputRadio::GetInputElement(actualRadioButtons->radioButton);
    }
    if (UndavInput::GetValue(dataInput) == value) {
        previusRadioButtons->next = actualRadioButtons->next;
        DestroyRadioButtons(actualRadioButtons);
    }
}

int UndavRadioButtonList::Count(RadioButtonList* radioButtons) {
    RadioButtons* auxRadioButtons = radioButtons->radioButtons;
    int index = 1;
    while (auxRadioButtons->next != NULL) {
        auxRadioButtons = auxRadioButtons->next;
        index++;
    }
    return index;
}

void UndavRadioButtonList::DestroyRadioButtonList(RadioButtonList* radioButtons) {
    delete radioButtons;
}
