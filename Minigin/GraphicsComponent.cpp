#include "GraphicsComponent.h"
#include "ResourceManager.h"

dae::GraphicsComponent::GraphicsComponent(GameObject* gameobject)
	: Component(gameobject)
{

}

void dae::GraphicsComponent::Update(float /*elapsedSec*/)
{
}

void dae::GraphicsComponent::Render() const
{
	
}

void dae::GraphicsComponent::FixedUpdate(const float /*fixedTimeStep*/)
{
}
