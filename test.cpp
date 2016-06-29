#include <iostream>
#include <string>
#include <fstream> //do wczytywania pliku
using namespace std;


int main ()
{

    fstream reader;
    reader.open ("napis.txt", ios::in);
    if (reader.is_open())
    {
        string line;
        while (getline(reader,line))
        cout<< line<<"\n";
    }
    reader.close();


    fstream writer;
    cout<<endl;
    cout<< "Zapiszê tekst do pliku.\n"<<endl;
    writer.open ("example.txt", ios::out);
    writer<< "Lubiê kwaiatki. \n";
    writer<< "Lubiê bratki.\n";
    writer<< "Nie lubiê marchewki.\n";
    writer.write ( "Kocham s³oñce", 6);  // zapisze 10 znaków,
                                         // gdy wezniemy wiêksz¹ liczbe ni¿ mamy znaków
                                         // to pociagnie kolejne znaki, które ma w pamiêci
    writer<< "\n";
    writer.close();

    fstream apper;
    cout<< "Dopiszê tekst do pliku.\n"<<endl;
    apper.open ("example.txt", ios::out | ios::app);
    apper<< "Dopisa³em to zdanie do pliku.\n";
    apper.close();

    fstream reader1;
    cout<<endl;
    cout<< "Zawartoœæ pliku:\n"<<endl;
    reader1.open ("example.txt", ios::in);
    if (reader1.is_open())
    {
        string line;                    //char c;
        while (getline(reader1,line))   //while (reader1.get(c))
        cout<< line<<"\n";              //cout << c;
    }
    reader1.close();
    return 0;
}
