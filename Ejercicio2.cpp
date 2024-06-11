#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string word;

    /*Inciso 1
    Elimminar del archivo todos las palabras que empiezan por 
    un numero*/

    ifstream inputSecondE("dataExamen2.csv");

    if(!inputSecondE.is_open()){
        cout<<"Did not open"<<endl;
    }

    ofstream noDigit;
    noDigit.open("NoDigit.txt");

    while(!inputSecondE.eof()){
        getline(inputSecondE, word);
        if (!isdigit(word[0])){
        noDigit<<word<<endl;
        }
    }

    noDigit.close();
    inputSecondE.close();
    
    /*Inciso 2
    Que separe en dos archivos las palabras una en vocal y la otra en
    consonante*/

    char firstLetter;

    ifstream withoutDigits("NoDigit.txt");

    ofstream withVocals;
    withVocals.open("withVocals.txt");

    ofstream withConsonants;
    withConsonants.open("withConsonants.txt");


    while(!withoutDigits.eof()){
        getline(withoutDigits, word);

        firstLetter=tolower(word[0]);
        
        if(firstLetter=='a' || firstLetter=='e' || firstLetter=='i' || firstLetter=='o' || firstLetter=='u')
        {
            withVocals<<word<<endl;
        }else{
            withConsonants<<word<<endl;

        }
    }

    
}