#pragma once
#include <memory>
#include "GraphicsComponent.h"
#include <string>


namespace dae
{
	class Texture2D;
	class TextureComponent :public GraphicsComponent
	{
	public:
		TextureComponent(Transform& transform);
		~TextureComponent();
		void Render() const override;

		void SetTexture(const std::string& filename);
	private:
		std::shared_ptr<Texture2D> m_Texture{};

	};
}

