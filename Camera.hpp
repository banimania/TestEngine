#pragma once

class Camera {
	public:
		float x, y, z, x_rot, y_rot, z_rot, mov_speed, rot_speed;
		void handleCameraMovement(float dt, float windowWidth, float windowHeight);
		Camera(float x, float y, float z, float x_rot, float y_rot, float z_rot, float mov_speed, float rot_speed);
};