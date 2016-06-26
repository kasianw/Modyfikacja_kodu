#include "image.h" // do³šczam bibliotekê i klasê image
#include "functions.h"

int main()
{
    bool exit = false;
    cout << "Graphics"<< endl;
	cout << "What do you think about programming?" << endl;
	do
    {

	switch(menu())
      {
		case '1':
			{cout << "Loading file ..." << endl;}
			break; //alternatywa dla wczytania innej grafiki
		case '2':
		{


            switch( submenu() )
            {
                case '1':
                {cout << "Add efekt sepia..." << endl;
                Image* image = new Image("lena.bmp");
                image->to_gray(SEPIA); // zamiana na sepia
                image->print("lena-sepia.bmp");  // zapisanie na dysku
                delete image;
                }
                break;
                case '2':
                {
                cout << "Add efekt gray..." << endl;
                Image* image = new Image("lena.bmp");
                image->to_gray(AVERAGE); // zamiana obrazka na monochromatyczny
                image->print("lena-gray.bmp");  // zapisanie na dysku
                delete image;
                }
                break;
                case '3':
                {
                cout << "Add efekt left eyes..." << endl;
                Image* image = new Image("lena.bmp");
                image->to_gray(LEFT); // zamiana obrazka na oko lewe
                image->print("lena-left.bmp");  // zapisanie na dysku
                delete image;
                }
                break;
                case '4':
                {
                cout << "Add efekt right eyes..." << endl;
                Image* image = new Image("lena.bmp");
                image->to_gray(RIGHT); // zamiana obrazka na oko prawe
                image->print("lena-right.bmp");  // zapisanie na dysku
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
			cout << "Saving ..." << endl;
			// powinna pojawic sie instrukcja zapisująca plik
			 break;
        case '4':
            {
            cout << " Thank you for the use of this program. " << endl;
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
    string menu[MENU_ELEMENTS_NUMBER] = { "load new file", "modify image", "save changes", "exit" };
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















