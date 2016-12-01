#pragma once
#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

class RPD : public aie::Application
{
	// Inherited via Application
	virtual bool startup() override
	{


	}

	virtual void shutdown() override;

	virtual void update(float deltaTime) override;

	virtual void draw() override;

};