#pragma once
#include <sstream>
#include <memory>

#include "SFML\Graphics.hpp"
#include "ObjectFactory.h"
#include "ObjectLogic.h"

class Game
{
private:
	/*State related variables*/
	enum class State
	{
		SPLASH, MENU, PLAYING, HELP
	};
	
	State state;
	bool debugModeActive;

	/*Video related variables*/
	Vector2f videoResolution;

	//Background
	VertexArray background;
	Vector2f backgroundPosition;
	Texture backgroundTexture;
	Sprite backgroundSprite;

	//Splashscreen
	Texture splashscreenTexture;
	Sprite splashscreenSprite;

	int alpha = 0;
	float filterTimer = 0.f;
	float filterDelay = 0.005;
	bool fadein = true;
	bool fadeout = false;

	//Menu
	bool backgroundObjectsCleared = false;

	//Help
	Texture helpTexture;
	Sprite helpSprite;
	Text thanksText;

	/*Object related variables*/
	//Herbivore
	Vector2f herbivorePosition;
	Texture herbivoreTexture;

	//Carnivore
	Vector2f carnivorePosition;
	Texture carnivoreTexture;

	//Water
	Vector2f waterPosition;
	Texture waterTexture;
	Sprite waterSprite;

	//Plant
	Vector2f plantPosition;
	Texture plantTexture;
	Sprite plantSprite;

	//Meat
	Vector2f meatPosition;
	Texture meatTexture;
	Sprite meatSprite;

	//Vectors
	std::vector<std::shared_ptr<Entity> > entityVector;
	std::vector<std::shared_ptr<Resource>> resourceVector;

	//Needs symbols
	Texture needsTexture;
	Sprite dangerSprite;
	Sprite hungrySprite;
	Sprite thirstySprite;
	Sprite matingSprite;

	/*Text related variables*/
	//Debug
	Font debugFont;
	Text debugText;
	Text fpsText;

	//Menu
	Font menuFont;
	Text titleText;
	Text playText;
	Text helpText;
	Text exitText;

	/*Event and clock related variables*/
	Event inputEvent;
	Clock clock;
	Time dt;
	float gameSpeed;

	/*Various objects*/
	ObjectFactory factory;
	ObjectLogic logic;

	//Vector size variable
	unsigned int eVectorSize;
	unsigned int rVectorSize;

public:
	RenderWindow gameWindow;

	Game();
	~Game();

	void initialiseVariables();
	void handleInput();
	void updateScene();
	void drawScene();

	bool isPointOverText(const sf::Vector2f Position, const Text &Text);
};

