#include "FPSComponent.h"


dae::FPSComponent::FPSComponent(Transform& transform, TextComponent& textComponent)
	: Component(dae::ComponentTypes::FPS, transform)
{
}

dae::FPSComponent::~FPSComponent()
{
}

void dae::FPSComponent::Update(float /*elapsedSec*/)
{

}
