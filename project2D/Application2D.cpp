#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	
	m_texture = new aie::Texture("/textures/Fallout.jpg");
	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_grassTexture = new aie::Texture("./textures/grass.png");
	m_Bullet = new aie::Texture("./textures/bullet.png");
	

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}



void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	if (m_ShipY <= 500) + (m_circleX < m_circleY);

	
	// use W,S,A,D keys to move Ship
	if (input->isKeyDown(aie::INPUT_KEY_W))
		m_ShipY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_S))
		m_ShipY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_ShipX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_ShipX += 500.0f * deltaTime;

	if (m_ShipX, m_ShipY == m_circleX, m_circleY)
	{
		void end();
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	
		//m_shipTexture +=  * deltaTime;*/

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && m_ShipY < 580)

	//// example of audio
	//if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	//	m_audio->play();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	//set background color
	/*setBackgroundColour(0.65f, -0.8, -0.8, 1);*/
	m_2dRenderer->setUVRect(1, 1, 2, 3);
	m_2dRenderer->drawSprite(m_texture, 1280, 720, 0);

	// wipe the screen to the background colour
	clearScreen();


	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate animation
	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_shipTexture, m_ShipX, m_ShipY, 0, 0, 0);

	// draw a moving white circle
	m_2dRenderer->setRenderColour(0.6, 7, 4, 6);
	m_2dRenderer->drawCircle(sin(m_timer) * 1250 + 525, 950, 50);
	// draw a Bullet
	m_2dRenderer->drawBullet(m_Bullet, m_ShipX, m_ShipY, 0, 0, 0);
	m_2dRenderer->drawSprite(m_Bullet, 30, 5, 0, 0, 0);
	
	//Draw Grass/Line Texture
	m_2dRenderer->setRenderColour(0,0,0,1);
	m_2dRenderer->drawSprite(m_grassTexture, 680, 1025, 5000);

	//Draw Second Grass/Line Texture
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawSprite(m_grassTexture, 580, 525, 5000);

	m_2dRenderer->setRenderColour(0, 0, 0, 1);
	m_2dRenderer->drawSprite(m_grassTexture, 680, 880, 5000);

	m_2dRenderer->setRenderColour(0, 0, 0, 1);
	m_2dRenderer->drawSprite(m_grassTexture, 580, 425, 300);

	m_2dRenderer->setRenderColour(0, 0, 0, 1);
	m_2dRenderer->drawSprite(m_grassTexture, 580, 325, 300);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space To Shoot!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}