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
		TextureComponent(GameObject* gameObject, const std::string& fullpath);
		~TextureComponent() = default;
		void Render() const override;

		void SetTexture(const std::string& filename);
	private:
		std::shared_ptr<Texture2D> m_Texture{};


		// Inherited via GraphicsComponent
		void Update(float elapsedSec) override;

		void FixedUpdate(const float fixedTimeStep) override;

	};
}

