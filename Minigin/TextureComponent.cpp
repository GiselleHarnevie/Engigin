#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Texture2D.h"
#include "Renderer.h"

dae::TextureComponent::TextureComponent(Transform& transform)
	:GraphicsComponent(transform)
{
}

dae::TextureComponent::~TextureComponent()
{
}

void dae::TextureComponent::Render() const
{
	const auto& pos = m_Transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

void dae::TextureComponent::SetTexture(const std::string& filename)
{
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

