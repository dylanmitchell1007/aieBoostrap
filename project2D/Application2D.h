#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "MathLibrary.h"


class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();
	virtual bool startup();
	virtual void shutdown();

	

	virtual void update(float deltaTime); 
	virtual void draw();

	Vector2 m_BulletPOS; //Bullets X, Y positions at start
	Vector2 m_ShipPOS; //Ships X, Y positions at start.

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_grassTexture;
	aie::Texture*		m_BulletTexture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	float m_cameraX, m_cameraY; //Cameras X, and Y positions.
	float m_timer;
	
	
	float m_circleX = 200; //Circles X, positions at start.
	float m_circleY = 200; //Circles Y, positions at start.
	float m_collisionX; //Barriers on X axis.
	float m_collisionY; //Barriers on Y axis.
	


};