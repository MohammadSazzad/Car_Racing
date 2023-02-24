#include <iostream>
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//Init game const
const double SCREEN_WIDTH = 800;
const double SCREEN_HEIGH = 600;
const int borderLeft = 140;
const int borderRight = 660;
const int racerWidth = 40;
const int racerHeight = 70;
string stringscore = "";
int score = 0;
double gameSpeed = 0.3;


//Create Main Windows
RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGH), "Car Racing");

int getRandomNumber(int a, int b)
{
	static bool first = true; if (first) { srand(time(NULL)); first = false; }
	int result = a + rand() % ((b + 1) - a);
	result = (result / 10) * 10;
	return result;
}


int gameOver()
{
	Texture gameover, troll;
	if (!gameover.loadFromFile("over.png")) { cout << "over\n"; }
	if (!troll.loadFromFile("troll.png")) { cout << "troll\n"; }
	Sprite Gameover(gameover);
	Sprite Troll(troll);
	Troll.setPosition(10, 350);

	//sound
	SoundBuffer gameOver;
	gameOver.loadFromFile("crash.wav");
	Sound GameOver;
	GameOver.setBuffer(gameOver);

	GameOver.play();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		Font myfont;
		myfont.loadFromFile("xirod.ttf");
		stringscore = "YOUR SCORE:" + to_string(score);
		Text text(stringscore, myfont, 30);
		text.setPosition(210, 450);
		window.clear();
		window.draw(Gameover);
		window.draw(text);
		window.draw(Troll);
		window.display();
	}
	return 0;
}


int main()
{
	//window size
	sf::RenderWindow window(sf::VideoMode(800, 600), "CAR GAME");


	//Init game music
	SoundBuffer gameSoundBuffer;
	gameSoundBuffer.loadFromFile("game.wav");
	Sound GameSound;
	GameSound.setBuffer(gameSoundBuffer);


	//image lode
	sf::Texture background, racer, obs1, obs2, obs3, obs4, gameover;

	// font
	Font myfont;
	myfont.loadFromFile("xirod.ttf");

	if (!background.loadFromFile("background.png")){cout << "background loding error!";}
	if (!racer.loadFromFile("racer.png")) {cout << "racer loding error!";}
	if (!obs1.loadFromFile("obs1.png"))   {cout << "obs1 loding error!";}
	if (!obs2.loadFromFile("obs2.png"))   {cout << "obs2 loding error!";}
	if (!obs3.loadFromFile("obs3.png"))   {	cout << "obs3 loding error!";}
	if (!obs4.loadFromFile("obs4.png")) { cout << "obs4 loding error!"; }

	sf::Sprite Background(background), Background1(background), Racer(racer), Obs1(obs1), Obs2(obs2), Obs3(obs3), Obs4(obs4);
	double RacerX, RacerY, Obs1X, Obs1Y, Obs2X, Obs2Y, Obs3X, Obs3Y, Obs4X, Obs4Y;

	//Set racer and Obs pos
	RacerX = SCREEN_WIDTH / 2;
	RacerY = SCREEN_HEIGH - racerHeight;
	Obs1X = getRandomNumber(borderLeft, borderRight);
	Obs2X = getRandomNumber(borderLeft, borderRight);
	Obs3X = getRandomNumber(borderLeft, borderRight);
	Obs4X = getRandomNumber(borderLeft, borderRight);
	Obs1Y = 0, Obs2Y = -100, Obs3Y = -200, Obs4Y = -300;
	double BackgroundY1 = 0;
	double BackgroundY2 = -600;

	GameSound.play();
	GameSound.setLoop(true);

	Racer.setPosition(sf::Vector2f(395, 520));




	//loop for game

	while (window.isOpen())
	{

		//Init and count score
		stringscore = "SCORE:" + to_string(score);
		Text text(stringscore, myfont, 15);
		text.setPosition(5, 0);

		//Set car position
		Racer.setPosition(RacerX, RacerY);
		Obs1.setPosition(Obs1X, Obs1Y);
		Obs2.setPosition(Obs2X, Obs2Y);
		Obs3.setPosition(Obs3X, Obs3Y);
		Obs4.setPosition(Obs4X, Obs4Y);



		//Creat scrolling background
		Background.setPosition(0, BackgroundY1);
		Background1.setPosition(0, BackgroundY2);
		if (BackgroundY2 > 0)
		{
			BackgroundY1 = 0;
			BackgroundY2 = BackgroundY1 - 500;
		}
		BackgroundY1 += 0.2;
		BackgroundY2 += 0.2;

		//Set Obs LOOP
		if (Obs1Y > SCREEN_HEIGH)
		{
			Obs1Y = 0; Obs1X = getRandomNumber(borderLeft, borderRight); score++;
		}
		else { Obs1Y = Obs1Y + gameSpeed; }
		if (Obs2Y > SCREEN_HEIGH)
		{
			Obs2Y = 0; Obs2X = getRandomNumber(borderLeft, borderRight); score++;
		}
		else { Obs2Y = Obs2Y + gameSpeed; }
		if (Obs3Y > SCREEN_HEIGH)
		{
			Obs3Y = 0; Obs3X = getRandomNumber(borderLeft, borderRight); score++;
		}
		else { Obs3Y = Obs3Y + gameSpeed; }
		if (Obs4Y > SCREEN_HEIGH)
		{
			Obs4Y = 0; Obs4X = getRandomNumber(borderLeft, borderRight); score++;
		}
		else { Obs4Y = Obs4Y + gameSpeed; }


		//Game level
		if (score > 50 && score < 100) { gameSpeed = 0.4; }
		if (score > 100 && score < 150) { gameSpeed =0.5; }
		if (score > 150&& score < 200) { gameSpeed  =0.6; }

		//Cre;ate event to handle input from keyboard
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					if (RacerX > borderLeft) { RacerX = RacerX - 30; }
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					if (RacerX < borderRight) { RacerX = RacerX + 30; }
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					if (RacerY > 0) { RacerY = RacerY - 30; }
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (RacerY < SCREEN_HEIGH - 70) { RacerY = RacerY + 0; }
				}
			}
		}

		//Check if accident happen
		if (((RacerX >= (Obs1X - 30)) && (RacerX <= (Obs1X + 30))) && ((RacerY >= (Obs1Y - 30)) && (RacerY) <= (Obs1Y + 30)))
		{
			GameSound.stop(); gameOver();
		};
		if (((RacerX >= (Obs2X - 30)) && (RacerX <= (Obs2X + 30))) && ((RacerY >= (Obs2Y - 30)) && (RacerY) <= (Obs2Y + 30)))
		{
			GameSound.stop(); gameOver();
		};
		if (((RacerX >= (Obs3X - 30)) && (RacerX <= (Obs3X + 30))) && ((RacerY >= (Obs3Y - 30)) && (RacerY) <= (Obs3Y + 30)))
		{
			GameSound.stop(); gameOver();
		};
		if (((RacerX >= (Obs4X - 30)) && (RacerX <= (Obs4X + 30))) && ((RacerY >= (Obs4Y - 30)) && (RacerY) <= (Obs4Y + 30)))
		{
			GameSound.stop(); gameOver();
		};




		window.clear();
		window.draw(Background);
		window.draw(Background1);
		window.draw(Racer);
		window.draw(Obs1);
		window.draw(Obs2);
		window.draw(Obs3);
		window.draw(Obs4);
		window.draw(text);
		window.display();

	}

}
