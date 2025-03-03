#pragma once
#include "Component.h"
#include <vector>

namespace dae
{
class ThrashTheCache :public Component
{
public:
	ThrashTheCache(GameObject* owner);
	virtual ~ThrashTheCache() = default;


	void Update(float elapsedSec) override;
	void FixedUpdate(const float fixedTimeStep) override;

	void ExerciseOne();
	void ExerciseTwo();
	void ExerciseTwoAlt();
	void RenderImGui();
private:
	std::vector<float> exOne;
	std::vector<float> exTwo;
	std::vector<float> exTwoAlt;
	std::vector<float> steps;

	int sampleSize;
	bool rerunTests;
};

struct TransformAlt
{
	float matrix[16] = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1 };
};

class GameObject3D
{
public:
	TransformAlt transform;
	int ID{ 1 };
};

class GameObject3DAlt
{
public:
	TransformAlt* transform{ nullptr };
	int ID{ 1 };
};
}

