#include "GraphicsComponent.h"
#include "ResourceManager.h"

//text ob a type of graphics comp
dae::GraphicsComponent::GraphicsComponent(Transform& transform)
	: Component(dae::ComponentTypes::GRAPHICS, transform)
{

}

dae::GraphicsComponent::~GraphicsComponent()
{

}

void dae::GraphicsComponent::Update(float /*elapsedSec*/)
{
}

void dae::GraphicsComponent::Render() const
{
	
}