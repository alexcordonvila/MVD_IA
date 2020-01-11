#pragma once
#include "ScriptSystem.h"
#include "PaddleAI.h"
#include "extern.h"
#include <ft2build.h>
#include <freetype/freetype.h>
#include FT_FREETYPE_H
#include <time.h> 


class BallMovement :
	public Script
{
public:
	FT_Library ft;
	FT_Face	face;
	BallMovement(int owner) : Script(owner) {}
	void update(float dt);
	void init(PaddleAI* paddleAI);
	void ShowText();
	//add whatever custom funcitons and properties here!
	void reset(Transform* transform);
	float  PI = 3.141f;  /* pi */
	Transform* transform = &ECS.getComponentFromEntity<Transform>(owner_);
	float segment3 = 0.8;
	float segment2 = 0.5;
	float segment1 = 0.2;
	float segment0 = 0.0;
	float angle;
	int dir = 1;
	float y_pos = 3.0f ;
	float xspeed = 4.0f;
	float yspeed = 4.0f;
	bool hitFlag = true;
	int CPUscore = 0;
	int Playerscore = 0;
	float timeleft = 1.0f;
	float initialTimeleft = 1.0;
	bool startCanMove = false;
	bool canMove = true; //makes the ball stop until "timeleft" 
	PaddleAI* paddleai_;
	
	
	
};

