#include "Scene.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "Component.h"

#include <algorithm>

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene() = default;

void Scene::Add(std::shared_ptr<GameObject> object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(std::shared_ptr<GameObject> object)
{
	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void dae::Scene::FixedUpdate(float fixedTimeStep)
{
	for (auto& object : m_objects)
	{
		object->FixedUpdate(fixedTimeStep);
	}
}

void Scene::Update(float elapsedSec)
{
	for (auto& object : m_objects)
	{
		object->Update(elapsedSec);
	}
}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		GraphicsComponent* graphicsObject{ object->GetComponent<GraphicsComponent>() };
		if (graphicsObject != nullptr)
		{
			graphicsObject->Render();
		}

	}
}

