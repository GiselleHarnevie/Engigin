#pragma once
#include <string>
#include <memory>
#include "GraphicsComponent.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextComponent : public GraphicsComponent
	{
	public:
		void Render() const override;
		void Update(float elapsedSec) override;

		void SetText(const std::string& text);
		//void SetPosition(float x, float y);

		TextComponent(const std::string& text, std::shared_ptr<Font> font, Transform& transform);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}
