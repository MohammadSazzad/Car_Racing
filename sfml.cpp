#include<SFML/Graphics.hpp>
#include<MainMenu.h>

using namespace sf;

void main()
{
    //Make a Main window
    RenderWindow MENU(VideoMode(840,650),"Main Menu",Style::Default);
    MainMenu MainMenu(MENU.getSize().x,MENU.getSize().y);
    //Set background.
    RectangleShape background;
    background.setSize(Vector2f(840,650));
    Texture Maintexture;
    Maintexture.loadFromFile("");
    background.setTexture(&Maintexture);

    //Photo to the game.
    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(840,650));
    Texture back_texture;
    back_texture.loadFromFile("");
    Pbackground.setTexture(&back_texture);

    //Photo to option
    RectangleShape Obackground;
    Obackground.setSize(Vector2f(840,650));
    Texture Optiontexture;
    Optiontexture.loadFromFile("");
    Obackground.setTexture(&Optiontexture);

    //About Geek projects

    RectangleShape ABbackground;
    ABbackground.setSize(Vector2f(840,650));
    Texture Abouttexture;
    Abouttexture.loadFromFile("");
    ABbackground.setTexture(&Abouttexture);

    while(MENU.isOpen())
    {
        Event event;
        while(MENU.pollEvent(event)){
            if(event.type == Event::Closed){
                MENU.close();
            }

            if(event.type == Event::KeyReleased){
                if(event.key.code == Keyboard::Up){
                    MainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard::Down){
                    MainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard::Return){
                    RenderWindow Play(VideoMode(840,650),"Car_Racing");
                    RenderWindow OPTIONS(VideoMode(840,650),"OPTIONS");
                    RenderWindow ABOUT(VideoMode(840,650),"ABOUT");

                    int x=mainMenu.MainMenuPressed();
                    if(x==0)
                    {
                        while(Play.isOpen()){
                            Event aevent;
                            while(Play.pollEvent(aevent)){
                                if(aevent.type==Event::Closed)
                                {
                                    play.close();
                                }
                                if(aevent.type==Event::KeyPressed){
                                    if(aevent.key.code == Keyboard::Escape){
                                        Play.close();
                                    }
                                }
                            }
                            OPTIONS.close();
                            ABOUT.close();
                            Play.clear();
                            Play.draw(Pbackground);
                            Play.display();
                        }
                    }
                    if(x==1){
                        while(OPTIONS.isOpen()){
                            Event aevent;
                            while(OPTIONS.pollEvent(aevent)){
                                if(aevent.type == Event::Closed){
                                    OPTIONS.close();
                                }
                                if(aevent.type == Event::KeyPressed){
                                    if(aevent.key.code == Keyboard::Escape){
                                        OPTIONS.close();
                                    }
                                }
                            }
                            Play.close();
                            OPTIONS.clear();
                            OPTIONS.draw(Obackground);
                            ABOUT.close();

                            OPTIONS.display();
                        }
                    }
                    if(x==2){
                        while(ABOUT.isOpen()){
                            Event aevent;
                            while(ABOUT.pollEvent(aevent)){
                                if(aevent.type == Event::Closed){
                                    ABOUT.close();
                                }
                                if(aevent.type == Event::KeyPressed){
                                    if(aevent.key.code == Keyboard::Escape){
                                        ABOUT.close();
                                    }
                                }
                            }
                            Play.close();
                            OPTIONS.clear();
                            ABOUT.clear();
                            ABOUT.draw(ABbackground);

                            ABOUT.display();
                        }
                    }
                    if(x==3){
                        MENU.close();
                    break;
                    }
                }
            }
            MENU.clear();
            MENU.draw(background);
            MainMenu.draw(MENU);
            MENU.display();

        }
    }
}
