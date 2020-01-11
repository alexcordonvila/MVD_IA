#include "BallMovement.h"
#include "extern.h"
#include <Windows.h>
#include <ft2build.h>
#include <freetype/freetype.h>
#include FT_FREETYPE_H
//Ball movement script and score control

void BallMovement::update(float dt)
{
	
	initialTimeleft = initialTimeleft - dt;
	//ShowText();
//	debug_system_toggleimGUI();
	if (initialTimeleft < 0) {
		(xspeed > 0) ? dir = 1 : dir = -1;
		this->paddleai_->ball_direction = dir;
		startCanMove = true;
	}
	//printf("Time Left = %f \n", initialTimeleft);
	Collider& collider_paddle = ECS.getComponentFromEntity<Collider>(owner_);
	Transform* transform;
	transform = &ECS.getComponentFromEntity<Transform>(owner_);
	float y_coll_point = collider_paddle.collision_point.y; //hit point bwteen paddles and puck
	y_pos = transform->position().y; //ball y position
	if(canMove && startCanMove){
		transform->translate(xspeed * dt, yspeed * dt, 0); //Ball movement
	}
	this->paddleai_->ypos = transform->position().y; //AI paddle needs this variable

	//if (input_->GetKey(GLFW_KEY_Z))
	//	transform->translate(-1 * dt, 0, 0);
	//if (input_->GetKey(GLFW_KEY_X))
	//	transform->translate(1 * dt, 0, 0);

	//if the ball puck with the paddle at certain distance
	if (collider_paddle.collision_distance < 0.3f && hitFlag == true) {
		float diff = y_pos - y_coll_point;
		 dir; //set puck direction positive or negative
		int angledir = 1; //set angle positive or negative
		
		//std::cout << "DIFF : " << diff << "\n";
		(xspeed > 0) ? dir = -1 : dir = 1;
		this->paddleai_->ball_direction = dir;
		(diff > 0) ? angledir = 1 : angledir = -1;

		if (abs(diff) >= segment2 && abs(diff) <= segment3) {
			float angle = (angledir * 45 * PI) / 180;
			xspeed = dir * 6 * cos(angle);
			yspeed = dir * 6 * sin(angle);
		}
		if (abs(diff) >= segment1 && abs(diff) < segment2) {
			float angle = (angledir * 30 * PI) / 180;
			xspeed = dir * 7 * cos(angle);
			yspeed = dir * 7 * sin(angle);
		}
		if (abs(diff) >= segment0 && abs(diff) < segment1) {
			float angle = (angledir * 0 * PI) / 180;
			xspeed = dir * 8 * cos(angle);
			yspeed = dir * 8 * sin(angle);
		}
		hitFlag = false;
	}
	else {
		//printf("No puck Collision!! \n");
	}
	// When the ball passes through the center zone we reset the hitflag
	if (transform->position().x > -4 && transform->position().x < 0) {
		hitFlag = true;
	}
	if (canMove == false || (transform->position().x >3 || transform->position().x < -7)) {
		//xspeed = xspeed * -1;
		if (transform->position().x > 3) Playerscore++;
		if (transform->position().x < -7) CPUscore++;
		canMove = false;
		timeleft = timeleft - dt;
		//printf("Time Left = %f \n" , timeleft);
		transform->position(-2.0f, 3.0f, -10.0f);
		this->paddleai_->reset = true;
		
		if (timeleft<0) {
			reset(transform);
		}
		
	}
	//Check ceiling and floor collision
	if (transform->position().y > 7 || transform->position().y < 1) {
		yspeed = yspeed * -1;
	}

	
}
//Returns the puck back to the center
//TODO: BALL ALWAYS STARTS IN A POSITIVE Y DIRECTON
void BallMovement::reset(Transform* transform) {
	//We generate random values 
	canMove = true;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) angle = (float)rand() / RAND_MAX; 
	//cout << (float)rand() / RAND_MAX << endl;
	
	if (angle >0.5f) {
		xspeed = -7 * cos(angle * (PI / 4));
		yspeed = 3 * sin(angle * ((PI) / 4));
	}
	else {
		xspeed = 7 * cos(angle * (PI / 4));
		yspeed = 3 * sin(angle * ((PI) / 4));
	}
	dir = dir * -1;
	timeleft = 1.0f;
	std::cout << "Player Score : " << Playerscore << "\n";
	std::cout << "CPU Score : " << CPUscore << "\n";
	transform->position(-2.0f, 3.0f, -10.0f);
}
void BallMovement::ShowText() {
	
	
	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
	if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
	FT_Set_Pixel_Sizes(face, 0, 48);
	if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
		std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	struct Character {
		GLuint     TextureID;  // ID handle of the glyph texture
		glm::ivec2 Size;       // Size of glyph
		glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
		GLuint     Advance;    // Offset to advance to next glyph
	};

}

void BallMovement::init(PaddleAI* paddleai_)
{
	this->paddleai_ = paddleai_;
}