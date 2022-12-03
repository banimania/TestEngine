#pragma once

class Vec3 {
	public:
		float x, y, z;
		Vec3(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vec3() {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
		}

		Vec3 substract(Vec3 v) { // u - v
			return Vec3(x - v.x, y - v.y, z - v.z);
		}

		float dotProduct(Vec3 v) { // u * v
			return x * v.x + y * v.y + z * v.z;
		}
};