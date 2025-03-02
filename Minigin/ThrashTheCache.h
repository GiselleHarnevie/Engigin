#pragma once
#include "Component.h"

namespace dae
{
class ThrashTheCache :public Component
{
public:
	ThrashTheCache(GameObject* owner);
	virtual ~ThrashTheCache() = default;


private:


	// Inherited via Component
	void Update(float elapsedSec) override;

	void FixedUpdate(const float fixedTimeStep) override;

};
}

