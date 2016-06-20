#include <string>
#include<iostream>
#include "Select.h"
#include "OptionItem.h"

using namespace std;
using namespace UndavSelect;

struct Options {
    UndavOptionItem::OptionItem* optionItem;
    Options* next;
};

struct UndavSelect::Select {
    string name;
    Options* options;
    int cant;
};

Options* CreateOptions() {
    Options* newOptions = new Options;
    newOptions->next=NULL;
    return newOptions;
}

UndavSelect::Select* UndavSelect::CreateSelect(string name) {
    Select* newSelect = new Select;
    newSelect->options = CreateOptions();
    newSelect->name = name;
    return newSelect;
}

Options* ParseOptions(char options[]) {
    Options* newOptions = CreateOptions();
    int index = 0;
    char divisor = ',';
    char endString = '\0';
    string value, text;

    while (options[index] != divisor) {
        value = value + options[index];
        index++;
    }
    index++;
    while (options[index] != endString) {
        text = text + options[index];
        index++;
    }
    newOptions->optionItem=UndavOptionItem::CreateOptionItem(text,value);
    return newOptions;
}

UndavSelect::Select* UndavSelect::CreateSelectFor(string name, char *options[], int optionsCount) {
    Select* newSelect = CreateSelect(name);
    try
    {
        if (optionsCount > 0) {

            Options* newOptions = ParseOptions(options[0]);
            newSelect->cant = optionsCount;
            newSelect->name = name;
            newSelect->options = newOptions;
            if (optionsCount > 1) {
                for (int i = 1; i < optionsCount; i++) {
                    newOptions = ParseOptions(options[i]);
                    newOptions->next = newSelect->options;
                    newSelect->options = newOptions;
                }
            }
        }
    }
    catch(string e){
    }
    return newSelect;
}

void UndavSelect::SelectItem(Select* select, int optionIndex) {
    int optionsCounter = 1;
    Options* auxOptions = select->options;
    if (optionIndex < select->cant) {
        while (auxOptions->next != NULL) {
            if (optionsCounter != optionIndex) {
                UndavOptionItem::Unselect(auxOptions->optionItem);
            } else {
                UndavOptionItem::Select(auxOptions->optionItem);
            }
            auxOptions = auxOptions->next;
            optionsCounter++;
        }
    }
}

UndavOptionItem::OptionItem* UndavSelect::GetSelectedItem(Select* select) {
    Options* auxOptions = select->options;
    while (auxOptions->next != NULL && !UndavOptionItem::IsSelected(auxOptions->optionItem)) {
        auxOptions = auxOptions->next;
    }

    if (UndavOptionItem::IsSelected(auxOptions->optionItem))
        return auxOptions->optionItem;

    return NULL;
}

void UndavSelect::AddOption(Select* select, UndavOptionItem::OptionItem* newOption) {
    Options* auxOptions = select->options;
    while (auxOptions ->next != NULL ) {
            auxOptions  = auxOptions ->next;
    }

    if (auxOptions ->next == NULL) {
        Options* newOptions = CreateOptions();
        newOptions->optionItem = newOption;
        newOptions->next = newOptions;
        select->cant++;
    }
}

void DestroyOptions(Options* options) {
    UndavOptionItem::DestroyOptionItem(options->optionItem);
    delete options;
}

void UndavSelect::RemoveOption(Select* select, int optionIndex) {
    if (optionIndex < select->cant) {
        Options* auxOptions = select->options;
        int indiceOptions = 1;
        while (indiceOptions + 1 != optionIndex) {
            auxOptions = auxOptions->next;
            indiceOptions++;
        }
        Options* optionsDestroy = auxOptions->next;
        auxOptions->next = auxOptions->next->next;
        DestroyOptions(optionsDestroy);
        select->cant--;
    }

}

void UndavSelect::RemoveOption(Select* select, UndavOptionItem::OptionItem* option) {
    Options* auxOptions = select->options;
    while (auxOptions->optionItem != option) {
        auxOptions = auxOptions->next;
    }
    DestroyOptions(auxOptions);
}

string UndavSelect::GetHtmlText(Select* select) {
    string html;
    Options* auxOptions = select->options;
    html = "<select name=\"" + select->name + "\">\n";
    while (auxOptions != NULL) {
        html = html + UndavOptionItem::GetHtmlText(auxOptions->optionItem) + "\n";
        auxOptions = auxOptions->next;
    }
    html = html + "</select>\n";
    return html;
}

int UndavSelect::CountOptions(Select* select) {
    return select->cant;
}

void UndavSelect::DestroySelect(Select* select) {
    Options* optionsToDestroy;
    Options* auxOptions = select->options;
    while (auxOptions->next != NULL) {
        optionsToDestroy = auxOptions->next;
        auxOptions->next = auxOptions->next->next;
        DestroyOptions(optionsToDestroy);
    }
    DestroyOptions(auxOptions);
    delete select;
}
