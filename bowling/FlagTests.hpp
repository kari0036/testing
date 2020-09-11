#pragma once
#include <iostream>
#include <string>

const std::string helpMessage = "Użycie: ./bowling [opcje] folderWejściowy [PlikZapisu]\n\nOpcje:\n-h \t\t Wyświetla pomoc.\n\nfolderWejściowy - Folder w którym zapisane dą dotychczasowe gry.\nPlikZapisu - Plik do którego zostaną wpisane dane z gry. Domyślnie jest to ekran";

void printOutHelp(std::ostream& output);