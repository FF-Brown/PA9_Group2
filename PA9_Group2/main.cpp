
//Main File

#include "PA9.h"
using namespace std;


int main(void)
{
    sf::RenderWindow mainMenuWindow(sf::VideoMode(500, 500), "Menu Window");
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
    mainMenuWindow.setPosition(centerWindow);
    Menu menu(500, 500);
    MainMenuOption option;
    do
    {
        menu.display_main_menu(mainMenuWindow);
        option = menu.get_Selected_Index();

        switch (option)
        {
        case INSTRUCTIONS:
            display_instructions();
            break;

        case PLAY_GAME:
            play_game();
            break;

        case EXIT:
            mainMenuWindow.close();
            break;
        }
    } while (option != EXIT);

    return 0;
}
