
//Main Menu source File

#include "PA9.h"
using namespace std;


void display_main_menu(sf::RenderWindow& mainMenuWindow)
{
    //Title
    //Menu choices

}
//Put Sammy's menu code here ^ v
//*Change to mouse click input?
MainMenuOption get_main_menu_option(void)
{

}

void display_instructions(void)
{
    sf::RenderWindow instructionsWindow(...);
    //Adapt from Sammy's menu code

}

void play_game(void)
{
    Game game;

    game.run();
    game.display_results();
}
