#include "Component.h"
#include "GameObject.h"


dae::Component::Component(GameObject* pOwner)
	: m_pOwner{pOwner}
{

}

void dae::Component::FixedUpdate(const float /*fixedTimeStep*/)
{
}

void dae::Component::Update(float /*elapsedSec*/)
{
}

dae::GameObject* dae::Component::GetOwner() const
{
	return m_pOwner;
}