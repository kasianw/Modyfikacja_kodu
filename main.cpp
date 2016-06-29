#include "image.h" // do³šczam bibliotekê i klasê image
#include "functions.h"
#include "text.h"


int main()
{
    //string nazwa_pliku;
    //cout<< "Write filepath:";
    //getline(cin,nazwa_pliku);

    fstream reader;
    reader.open ("napis.txt", ios::in);
    if (reader.is_open())
    {
        string line;
        while (getline(reader,line))
        cout<< line<<"\n";
    }
    reader.close();

// 9 w/w linijek służy do wczytania pliku tekstowego i wyświetlenia jego zawartości na konsoli



    bool exit = false;
    cout << "Graphics"<< endl;
	cout << "What do you think about programming?" << endl;
	do
    {

	switch(menu())
      {

        Image* image;
		case '1':
			{
            string nazwa_pliku;
            cout << "Write filepath image: ";
            getline(cin,nazwa_pliku);

            fstream writer;
            writer.open ("plik_pomocniczy.txt", ios::out);
            writer<<nazwa_pliku;
            writer.close();

             }
			break;
		case '2':
		{
            string nazwa_pliku;
            fstream opener;
            opener.open ("plik_pomocniczy.txt", ios::in);
            if (opener.is_open())
            getline(opener,nazwa_pliku);

            fstream reader;
            reader.open (nazwa_pliku.c_str(), ios::in);
            reader.close();
            opener.close();


            switch( submenu() )
            {
                case '1':
                {cout << "Add efekt sepia..." << endl;
                Image* image = new Image(nazwa_pliku);
                image->to_gray(SEPIA); // zamiana na sepia
                image->print("pomocniczy.bmp");  // zapisanie na dysku
                delete image;
                }
                break;
                case '2':
                {
                cout << "Add efekt gray..." << endl;
                Image* image = new Image(nazwa_pliku);
                image->to_gray(AVERAGE); // zamiana obrazka na monochromatyczny
                image->print("pomocniczy.bmp");  // zapisanie na dysku
                delete image;
                }
                break;
                case '3':
                {
                cout << "Add efekt left eyes..." << endl;
                Image* image = new Image(nazwa_pliku);
                image->to_gray(LEFT); // zamiana obrazka na oko lewe
                image->print("pomocniczy.bmp");  // zapisanie na dysku
                delete image;
                }
                break;
                case '4':
                {
                cout << "Add efekt right eyes..." << endl;
                Image* image = new Image(nazwa_pliku);
                image->to_gray(RIGHT); // zamiana obrazka na oko prawe
                image->print("pomocniczy.bmp");  // zapisanie na dysku
                 delete image;
                }
                break;
                case '5':
                break;
                default: //else
                cout << "Try one more time" << endl;
            }
            break;
		}
		case '3':
			{cout << "Write filepath where saving changes: " << endl;
            string nazwa;
            cin>>nazwa;
            Image* image = new Image("pomocniczy.bmp");
            image->print(nazwa);
            cout << "Saving.." << endl;
            }
			 break;
        case '4':
            {
            cout << "Thank you for the use of this program. " << endl;
			exit = true;
			break;
            }
		default: // else
			cout << "Try one more time" << endl; break;
       }
    } while (exit == false);
	return 0;

}

void line()
{
   cout << "-------------------------------------"<<endl;
};

char menu()
{
    line();
    string menu[MENU_ELEMENTS_NUMBER] = { "read image", "modify image", "save changes", "exit" };
	for ( int i = 0; i < MENU_ELEMENTS_NUMBER; i++ )
		cout << i+1 << ". " << menu[i] << endl;
    line();
    char decision=getch();
    return decision;
};

char submenu()
{
    string submenu[] = { "sepia", "gray", "left eyes", "right eyes", "back to options"};
    int submenu_elements = sizeof(submenu)/sizeof(submenu[0]);
    for ( int j = 0; j < submenu_elements; )
    	cout << j<< ". " << submenu[j++] << endl;
    line();
	char decision=getch();
    return decision;
};















