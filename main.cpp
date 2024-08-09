#include <iostream>
#include <clocale>
#include <windows.h>
#include <cctype>
#include <array>
#include <string>

using std::string;

void aggiungi(string parole[100], string sinonimi[100], string contrari[100], int& i);
void cerca(string parole[100], string sinonimi[100], string contrari[100], int i);
void modifica(string parole[100], string sinonimi[100], string contrari[100], int i);
void elimina(string parole[100], string sinonimi[100], string contrari[100], int& i);
void visualizza(string parole[100], string sinonimi[100], string contrari[100], int i);

int main() {

    std::setlocale(LC_ALL, "it_IT.utf8");

    string parole[100];
    string sinonimi[100];
    string contrari[100];

    int scelta, i = 0;

    system("cls");

    do { 
        std::cout << "\n Menu \n";
        std::cout << "\n 1) Aggiungi una parola" << std::endl;
        std::cout << "\n 2) Cercare una parola" << std::endl;
        std::cout << "\n 3) Modifica una parola" << std::endl;
        std::cout << "\n 4) Elimina una parola" << std::endl;
        std::cout << "\n 5) Visualizzare il dizionario" << std::endl;
        std::cout << "\n 6) Esci" << std::endl;
        std::cout << "\n Scelta: ";
        std::cin >> scelta;

        if (scelta > 6 || scelta < 1) {
            system("cls");
            std::cout << "\n Scelta non disponibile." << std::endl;
        }

        switch (scelta) {
            case 1:
                system("cls");
                aggiungi(parole, sinonimi, contrari, i);
                Sleep(3000);
                system("cls");
                break;
            case 2:
                system("cls");
                cerca(parole, sinonimi, contrari, i);
                system("cls");
                break;
            case 3:
                system("cls");
                modifica(parole, sinonimi, contrari, i); 
                Sleep(3000);
                system("cls");
                break;
            case 4:
                system("cls");
                elimina(parole, sinonimi, contrari, i);
                Sleep(3000);
                system("cls");
                break;
            case 5:
                system("cls");
                visualizza(parole, sinonimi, contrari, i);
                system("cls");
                break;
        }
    } while (scelta != 6);

    return 0;
}

void aggiungi(string parole[100], string sinonimi[100], string contrari[100], int& i) {

    if (i < 100) {
        string parola, sinonimo, contrario;

        std::cout << "\n Inserisci una parola: ";  
        std::cin >> parola;
        std::cin.ignore();

        for (char& c : parola) { 
            c = tolower(c);
        }

        for (int j = 0; j < i; j++) {
            if (parola == parole[j]) {
                std::cout << "\n La parola '" << parola << "' è già presente nel dizionario.\n";
                return; 
            }
        }

        parole[i] = parola;

        std::cout << "\n Inserisci sinonimi (separati da spazi): ";
        std::getline(std::cin, sinonimo);

        for (char& c : sinonimo) {
            c = tolower(c);
        }
        
        sinonimi[i] = sinonimo;     

        std::cout << "\n Inserisci contrari (separati da spazi): ";
        std::getline(std::cin, contrario);

        for (char& c : contrario) {
            c = tolower(c);
        }

        contrari[i] = contrario;

        std::cout << "\n La parola " << parole[i] << " è stata aggiunta con successo.";

        i++; 
    } else {
        std::cout << "\n Il dizionario è pieno. Non è possibile aggiungere altre parole.";
    }
}

void cerca(string parole[100], string sinonimi[100], string contrari[100], int i) {
    string parola;
    bool parolaTrovata = false;

    std::cout << "\n Inserire la parola da cercare: ";
    std::cin >> parola;

    for (char& c : parola) { 
        c = tolower(c);
    }

    for (i = 0; i < 100; i++) {
        if (parola == parole[i]) {
            std::cout << "\n La parola " << parola << " è stata trovata." << std::endl;
            std::cout << "\n I sinonimi di " << parola << " sono " << sinonimi[i];
            std::cout << "\n I contrari di " << parola << " sono " << contrari[i] << std::endl;
            parolaTrovata = true;
            break;  
        }
    }

    if (!parolaTrovata) {
        std::cout << "\n La parola " << parola << " non è presente nel dizionario." << std::endl;
    }

    char risposta;
    std::cout << "\n Vuoi tornare al menu principale? (s/n): ";
    std::cin >> risposta;
    risposta = tolower(risposta);

    if (risposta == 'n') {
        exit(0); 
    }
}


void modifica(string parole[100], string sinonimi[100], string contrari[100], int i) {

    string parola, parola_modificata, sinonimo_modificato, contrario_modificato;
    char risp;

    std::cout << "\n Quale parola vuoi modificare? ";
    std::cin >> parola;

    for (char& c : parola) {
        c = tolower(c);
    }

    for (int j = 0; j < i; j++) {
        if (parola == parole[j]) {
            std::cout << "\n Con che parola la vuoi modificare? ";
            std::cin >> parola_modificata;

            for (char& c : parola_modificata) {
                c = tolower(c);
            }

            parole[j] = parola_modificata;
            std::cout << "\n La parola " << parola << " è stata modificata in " << parola_modificata << "." << std::endl;

            std::cout << "\n Vuoi modificare anche sinonimi e contrari della parola? (s/N): ";
            std::cin >> risp;
            risp = tolower(risp);

            if (risp == 's') {
                std::cout << "\n Sinonimi attuali: " << sinonimi[j] << std::endl;
                std::cout << "\n Contrari attuali: " << contrari[j] << std::endl;

                std::cout << "\n Inserire nuovi sinonimi (separati da spazi): ";
                std::cin.ignore();
                std::getline(std::cin, sinonimo_modificato);
                sinonimi[j] = sinonimo_modificato;

                std::cout << "\n Inserire nuovi contrari (separati da spazi): ";
                std::getline(std::cin, contrario_modificato);
                contrari[j] = contrario_modificato;
            }
            return;
        }
    }
    std::cout << "\n La parola " << parola << " non è presente nel dizionario." << std::endl;
}

void elimina(string parole[100], string sinonimi[100], string contrari[100], int& i) {

    string parola;

    std::cout << "\n Quale parola vuoi rimuovere dal dizionario? ";
    std::cin >> parola;

    for (int j = 0; j < i; j++) {
        if (parola == parole[j]) {
            for (int k = j; k < i - 1; k++) {
                parole[k] = parole[k + 1];
                sinonimi[k] = sinonimi[k + 1];
                contrari[k] = contrari[k + 1];
            }
            
            parole[i - 1] = "";
            sinonimi[i - 1] = "";
            contrari[i - 1] = "";

            i--; 

            std::cout << "\n La parola '" << parola << "' è stata rimossa dal dizionario.\n";
            return;
        }
    }

    std::cout << "\n La parola '" << parola << "' non è presente nel dizionario.\n";
}

void visualizza(string parole[100], string sinonimi[100], string contrari[100], int i) {
    bool dizionarioVuoto = true;

    std::cout << "\n Contenuto del dizionario:\n";

    for (int j = 0; j < i; j++) {
        if (!parole[j].empty()) { 
            std::cout << "\n Parola: " << parole[j] << "\n";
            std::cout << " Sinonimi: " << sinonimi[j] << "\n";
            std::cout << " Contrari: " << contrari[j] << "\n";
            dizionarioVuoto = false;  
        }
    }

    if (dizionarioVuoto) {
        std::cout << "\n Attualmente non è presente nessuna parola nel dizionario.\n";
    }

    char risposta;
    std::cout << "\n Vuoi tornare al menu principale? (s/n): ";
    std::cin >> risposta;
    risposta = tolower(risposta);

    if (risposta == 'n') {
        exit(0);
    }
}
