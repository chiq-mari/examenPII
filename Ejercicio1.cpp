#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

struct personaInfo{
    string id;
    string firstName;
    string email;
    string gender;
    string location;
    string finalNote;
};


int main(){

    string lineInfo; //to store data line by line
    personaInfo lista[1000];
    ifstream inputFirstE("dataExamen.csv");
    int counter=-1;

    //cant por genero
    int female=0;
    int male=0;
    int agender=0;
    int transgender=0;
    int nonbinary=0;

    //Gente por localidad

    int americaPeople=0;

    int africaPeople=0;

    int asiaPeople=0;

    int europePeople=0;

    int oceaniaPeople=0;
    
    // start of the program 

    if(!inputFirstE.is_open()){
        cout<<"The file did not open"<<endl;
    }

    while(!inputFirstE.eof()){

        getline(inputFirstE, lineInfo);
        if(!isdigit(lineInfo[0])){       //skips first line
            continue;
        }
        // takes data for each person

        stringstream s(lineInfo);  //data for one person as a line
        personaInfo sujeto;        //structured datatype for info

        getline(s, sujeto.id, ',');
        getline(s, sujeto.firstName, ',');
        getline(s, sujeto.email, ',');
        getline(s, sujeto.gender, ',');
        getline(s, sujeto.location, ',');
        getline(s, sujeto.finalNote, ',');

        counter++;
        
        lista[counter]=sujeto;

    }

    /*Inciso 1
    contar la cantidad de personas por genero y mostrar su proporcion 
    en la poblacion*/

    for (int i=0; i<1000; i++){
        if (lista[i].gender=="female"){
            female++;
        }else if (lista[i].gender=="male"){
            male++;
        }else if (lista[i].gender=="transgender"){
            transgender++;
        }else if (lista[i].gender=="agender"){
            agender++;
        }else if (lista[i].gender=="non-binary"){
            nonbinary++;
        }else{
            continue;
        }
    }

    cout<<"El numero de personas con genero female is: "<<female<<". Su porcentaje es "<<(female/1000.0)*100.0<<"%."<<endl;
    cout<<"El numero de personas con genero male is: "<<male<<". Su porcentaje es "<<(male/1000.0)*100.0<<"%."<<endl;
    cout<<"El numero de personas con genero transgender is: "<<transgender<<". Su porcentaje es "<<(transgender/1000.0)*100.0<<"%."<<endl;
    cout<<"El numero de personas con genero agender is: "<<agender<<". Su porcentaje es "<<(agender/1000.0)*100.0<<"%."<<endl;
    cout<<"El numero de personas con genero nonbinary is: "<<nonbinary<<". Su porcentaje es "<<(nonbinary/1000.0)*100.0<<"%."<<endl;

    /*Inciso 2
    Separar en diferentes archivos a las personas por su localidad*/

    ofstream america;
    america.open("fromAmerica.txt");
    america<<"id,first_name,email,gender,location,final_note"<<endl;

    ofstream asia;
    asia.open("fromAsia.txt");
    asia<<"id,first_name,email,gender,location,final_note"<<endl;

    ofstream africa;
    africa.open("fromAfrica.txt");
    africa<<"id,first_name,email,gender,location,final_note"<<endl;

    ofstream europe;
    europe.open("fromEurope.txt");
    europe<<"id,first_name,email,gender,location,final_note"<<endl;

    ofstream oceania;
    oceania.open("fromOceania.txt");
    oceania<<"id,first_name,email,gender,location,final_note"<<endl;

    //outputs them

    for(int i=0; i<1000; i++){

        if(lista[i].location=="america"){
            america<<lista[i].id<<','<<lista[i].firstName<<','<<lista[i].email<<','<<lista[i].gender<<','<<lista[i].location<<','<<lista[i].finalNote<<endl;

        }else if(lista[i].location=="asia"){
            asia<<lista[i].id<<','<<lista[i].firstName<<','<<lista[i].email<<','<<lista[i].gender<<','<<lista[i].location<<','<<lista[i].finalNote<<endl;

        }else if(lista[i].location=="africa"){
            africa<<lista[i].id<<','<<lista[i].firstName<<','<<lista[i].email<<','<<lista[i].gender<<','<<lista[i].location<<','<<lista[i].finalNote<<endl;
            
        }else if(lista[i].location=="oceania"){
            oceania<<lista[i].id<<','<<lista[i].firstName<<','<<lista[i].email<<','<<lista[i].gender<<','<<lista[i].location<<','<<lista[i].finalNote<<endl;
            
        }else if(lista[i].location=="europe"){
            europe<<lista[i].id<<','<<lista[i].firstName<<','<<lista[i].email<<','<<lista[i].gender<<','<<lista[i].location<<','<<lista[i].finalNote<<endl;
        }else{
            continue;
        }
    }

    /*Inciso 3
    Mostrar cuantas personas hay por localidad que sean hombres y mujeres*/

    cout<<endl;

    for(int i=0; i<1000; i++){

        if(lista[i].location=="america"){
            if(lista[i].gender=="female" || lista[i].gender=="male"){
                americaPeople++;
            }else{
                continue;
            }

        }else if(lista[i].location=="asia"){
            if(lista[i].gender=="female" || lista[i].gender=="male"){
                asiaPeople++;
            }else{
                continue;
            }

        }else if(lista[i].location=="africa"){
            if(lista[i].gender=="female" || lista[i].gender=="male"){
                africaPeople++;
            }else{
                continue;
            }
        }else if(lista[i].location=="oceania"){
            if(lista[i].gender=="female" || lista[i].gender=="male"){
                oceaniaPeople++;
            }else{
                continue;
            }
        }else if(lista[i].location=="europe"){
            if(lista[i].gender=="female" || lista[i].gender=="male"){
                europePeople++;
            }else{
                continue;
            }
        }else{
            continue;
        }
    }

    cout<<"Hay "<<americaPeople<<" personas que son female or male en America"<<endl;
    cout<<"Hay "<<asiaPeople<<" personas que son female or male en Asia"<<endl;
    cout<<"Hay "<<africaPeople<<" personas que son female or male en Africa"<<endl;
    cout<<"Hay "<<europePeople<<" personas que son female or male en Europa"<<endl;
    cout<<"Hay "<<oceaniaPeople<<" personas que son female or male en Oceania"<<endl;

}
