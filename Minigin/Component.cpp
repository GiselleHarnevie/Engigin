#include "Component.h"



dae::Component::Component(ComponentTypes type, Transform& transform)

	: m_ComponentType{ type },
	  m_Transform{ transform }
{

}

dae::Component::~Component()
{
}

void dae::Component::FixedUpdate(const float /*fixedTimeStep*/)
{
}

void dae::Component::Update(float /*elapsedSec*/)
{
}

dae::ComponentTypes dae::Component::GetComponentType()
{
	return m_ComponentType;
}
