
//Main File

#include "PA9.h"
using namespace std;


int main(void)
{
    sf::RenderWindow mainMenuWindow(...);

    MainMenuOption option;
    do
    {
        display_main_menu(mainMenuWindow);
        option = get_main_menu_option();

        switch (option)
        {
        case INSTRUCTIONS:
            display_instructions();
            break;

        case PLAY_GAME:
            play_game();
            break;

        case EXIT:
            break;
        }
    } while (option != EXIT);

    return 0;
}
