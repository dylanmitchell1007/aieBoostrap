#pragma once
#include "MathLibrary.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();
	virtual bool startup();
	virtual void shutdown();

	

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_grassTexture;
	aie::Texture*		m_BulletTexture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	aie::Texture*		m_Fallout;

	float m_cameraX, m_cameraY;
	float m_timer;
	float m_Bullet = 880;
	float m_Fire = '\0';
	float m_ShipX = 580;
	float m_ShipY = 370;
	float m_circleX = 200;
	float m_circleY = 200;
	float m_collisionX = 1280;
	float m_collisionY = 720;
	

};