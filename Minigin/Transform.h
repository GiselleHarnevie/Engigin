#pragma once
#include <glm.hpp>

namespace dae
{	
	class Transform final
	{
	public:
		Transform();

		const glm::vec3& GetLocalPosition() const { return m_LocalPosition; }
		glm::vec3 GetWorldPosition() const;

		void SetLocalPosition(float x, float y, float z);

	private:
		glm::vec3 m_LocalPosition;
		Transform* m_Parent;
	
	};
}
