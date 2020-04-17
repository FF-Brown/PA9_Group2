
#include "main_menu.h"

bool main_menu(void)
{
    display_main_menu();

    //Get input

    switch (option)
    {
    case INSTRUCTIONS: display_instructions();
                       break;
    case PLAY_GAME:    return false;
    case EXIT:         return true;
    }
}

void display_main_menu(void)
{

}
