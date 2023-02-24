#include<MainMenu.h>

MainMenu::MainMenu(float width,float height)
{
    if(!float.loadFromFile(""))
    {
        cout<<"No font is here";
    }
    //play
    mainMenu[0].setFont(font);
    MainMenu[0].setFillcolor(color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(840,650);
    //Option
    mainMenu[1].setFont(font);
    mainMenu[1].setFillcolor(color::White);
    mainMenu[1].setString("Option");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(840,650);
    //About
    mainMenu[2].setFont(font);
    mainMenu[2].setFillcolor(color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharecterSize(70);
    mainMenu[2].setPosition(840,650);
    //Exit
    mainMenu[3].setFont(font);
    mainMenu[3].setFillcolor(color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(840,650);


    MainMenuSelected = -1;
}
MainMenu::~MainMenu()
{

}
//Draw main menu
void MainMenu::draw(RenderWindow& window){
    for(int i=0;i<Max_main_menu;i++){
        window.draw(mainMenu[i]);
    }
}

//MoveUp
void MainMenu::MoveUp()
{
    if(MainMenuSelected-1>=0){
        mainMenu[MainMenuSelected].setFillcolor(color::White);

        MainMenuSelected--;
        if(MainMenuSelected==-1){
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillcolor(color::Blue);
    }
}
//MOveDown
void MainMenu::MoveDown()
{
    if(MainMenuSelected+1<=Max_main_menu){
        mainMenu[MainMenuSelected].setFillcolor(color::White);
        MainMenuSelected++;
        if(MainMenuSelected == 4){
            MainMenuSelected = 0;
        }
        MainMenu[MainMenuSelected].setFillcolor(color::Blue);

    }
}
