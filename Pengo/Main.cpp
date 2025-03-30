#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include <string>
#include "GameObject.h"
#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "Scene.h"
#include "TextureComponent.h"
#include "FPSComponent.h"
#include "RotatorComponent.h"
#include "ThrashTheCache.h"
#include "HealthComponent.h"
#include "Observer.h"
#include "Achievement.h"
#include "InputManager.h"
#include "InputComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto bigFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto smallFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 15);


	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextureComponent>("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextureComponent>("logo.tga");
	go->SetLocalPosition(glm::vec3{ 216,180,0 });
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextComponent>("Programming 4 Assignment", bigFont);
	go->SetLocalPosition(glm::vec3{ 80,20,0 });
	scene.Add(go);

	/*go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextComponent>("(Not Working) Use the D-Pad to move, X to inflict damage, A and B to pick up pellets", smallFont);
	go->SetLocalPosition(glm::vec3{ 10,100,0 });
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextComponent>("(Only WASD Working) Use the WASD to move, C to inflict damage, Z and X to pick up pellets", smallFont);
	go->SetLocalPosition(glm::vec3{ 10,120,0 });
	scene.Add(go);*/

	//fps
	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextComponent>("FPS", bigFont);
	go->AddComponent<dae::FPSComponent>();
	go->SetLocalPosition(glm::vec3{ 10,60,0 });
	scene.Add(go);

	//pengo rotate
	/*auto pivot = std::make_shared<dae::GameObject>();
	pivot->SetLocalPosition(glm::vec3{ 200,200,0 });
	scene.Add(pivot);

	auto pengo = std::make_shared<dae::GameObject>();
	pengo->SetParent(pivot.get(), false);
	pengo->AddComponent<dae::TextureComponent>("JustPengo.png");
	pengo->AddComponent<dae::RotatorComponent>(5.f, 30.f);
	scene.Add(pengo);

	auto child = std::make_shared<dae::GameObject>();
	child->AddComponent<dae::TextureComponent>("JustPengo.png");
	child->AddComponent<dae::RotatorComponent>(-5.f, 50.f);
	child->SetParent(pengo.get(), false);
	scene.Add(child);*/

	////thrash the cache
	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::ThrashTheCache>();
	//scene.Add(go);

	//auto observer = std::make_unique<dae::Achievement>();
	/////Player 1
	//auto playerOne = std::make_shared<dae::GameObject>();
	//playerOne->AddComponent< dae::TextureComponent>("JustPengo.png");
	//auto& test{ playerOne->AddComponent<dae::InputComponent>() };
	//test.HandleBinds();
	//playerOne->SetLocalPosition(glm::vec3{ 150,100,0 });
	//auto& health = playerOne->AddComponent<dae::HealthComponent>();

	//health.RegisterOnHealthChange(observer.get());
	////health.RegisterOnPlayerDeath(observer.get());
	//scene.Add(playerOne);


	///Player 2
	/*auto playerTwo = std::make_shared<dae::GameObject>();
	playerTwo->AddComponent< dae::TextureComponent>("JustPengo.png");
	playerTwo->SetLocalPosition(glm::vec3{ 170,100,0 });
	auto& playerTwoHealth = playerTwo->AddComponent<dae::HealthComponent>();
	playerTwoHealth.RegisterOnPlayerDeath(observer.get());
	playerTwoHealth.RegisterOnHealthChange(observer.get());
	scene.Add(playerTwo);*/

	/*///P1 displays
	auto UI = std::make_shared<dae::GameObject>();
	UI->SetLocalPosition(glm::vec3{ 10,150,0 });
	UI->AddComponent<dae::TextComponent>("# lives: ", smallFont);
	scene.Add(UI);

	UI = std::make_shared<dae::GameObject>();
	UI->SetLocalPosition(glm::vec3{ 10,170,0 });
	UI->AddComponent<dae::TextComponent>("Score: ", smallFont);
	scene.Add(UI);

	///P2 displays
	UI = std::make_shared<dae::GameObject>();
	UI->SetLocalPosition(glm::vec3{ 10,190,0 });
	UI->AddComponent<dae::TextComponent>("# lives: ", smallFont);
	scene.Add(UI);

	UI = std::make_shared<dae::GameObject>();
	UI->SetLocalPosition(glm::vec3{ 10,210,0 });
	UI->AddComponent<dae::TextComponent>("Score: ", smallFont);
	scene.Add(UI);*/
}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}