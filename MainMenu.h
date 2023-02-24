#progma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4
class MainMenu
{
    //public means that it can be accessed outside the class.
public:
    MainMenu(float width,float height);
    void draw(RenderWindow& window);
    void MoveUp();

    int MainMenuPressed(){
        return MainMenuSelected;
    }
    ~MainMenu()
    //private means that  it can only used by the class internally and cannot be accessed outside of the said class.
private:
    int MainMenuSelected;
    Font font ;
    Text mainMenu[Max_main_menu];
};
