#include "ThrashTheCache.h"
#include <imgui.h>
#include <chrono>
#include <iostream>
#include "imgui_plot.h"
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_sdl2.h>

dae::ThrashTheCache::ThrashTheCache(GameObject* owner)
	:Component(owner),
	sampleSize{ 10 },
	rerunTests{ false }
{

}

void dae::ThrashTheCache::Update(float /*elapsedSec*/)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();

	RenderImGui();
}

void dae::ThrashTheCache::FixedUpdate(const float /*fixedTimeStep*/)
{
}

void dae::ThrashTheCache::ExerciseOne()
{
	int length = static_cast<int>(powf(2, 26));
	std::vector<int> arr(length, 1);

	exOne.clear();
	steps.clear();

	for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		steps.push_back(static_cast<float>(stepsize));
		float totalTime = 0.0f;

		for (int sample = 0; sample < sampleSize; sample++)
		{
			auto start = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < length; i += stepsize)
			{
				arr[i] *= 2;
			}

			auto end = std::chrono::high_resolution_clock::now();
			totalTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}

		float avgTime = totalTime / sampleSize;
		exOne.push_back(avgTime);
	}
}


void dae::ThrashTheCache::ExerciseTwo()
{
	int length = static_cast<int>(powf(2, 26));
	std::vector<GameObject3D> arrayr(length);

	exTwo.clear();

	for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		float totalTime = 0.0f;
		for (int sample = 0; sample < sampleSize; sample++)
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < length; i += stepsize)
			{
				arrayr[i].ID *= 2;
			}
			auto end = std::chrono::high_resolution_clock::now();
			totalTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}

		float avgTime = totalTime / sampleSize;
		exTwo.push_back(avgTime);
	}
}

void dae::ThrashTheCache::ExerciseTwoAlt()
{
	int length = static_cast<int>(powf(2, 26));
	std::vector<GameObject3DAlt> gameObjects(length);

	exTwoAlt.clear();

	for (int stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		float totalTime = 0.0f;
		for (int sample = 0; sample < sampleSize; sample++)
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int i = 0; i < length; i += stepsize)
			{
				gameObjects[i].ID *= 2;
			}
			auto end = std::chrono::high_resolution_clock::now();
			totalTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}

		float avgTime = totalTime / sampleSize;
		exTwoAlt.push_back(avgTime);
	}
}

void dae::ThrashTheCache::RenderImGui()
{
	//
	ImGui::Begin("Exercise 1");
	ImGui::Text("Sample Size:");
	ImGui::SameLine();
	ImGui::InputInt("##SampleSize", &sampleSize, 1, 10);

	if (ImGui::Button("Thrash the Cache"))
	{
		exOne.clear();
		ExerciseOne();
		rerunTests = false;
	}

	if (exOne.size() > 0)
	{
		//Exercise 1
		ImGui::PlotConfig conf;
		conf.values.xs = steps.data();
		conf.values.ys = exOne.data();
		conf.values.count = static_cast<int>(exOne.size());
		conf.scale.min = 0;
		conf.scale.max = *std::max_element(exOne.begin(), exOne.end());
		conf.tooltip.show = true;
		conf.tooltip.format = "Step: %g, Time: %.2f ";
		conf.grid_x.show = true;
		conf.grid_y.show = true;
		conf.frame_size = ImVec2(200, 100);
		conf.line_thickness = 2.f;
		ImGui::Plot("Exercise 1", conf);
	}

	ImGui::End();

	//
	ImGui::Begin("Exercise 2");
	ImGui::Text("Sample Size:");
	ImGui::SameLine();
	ImGui::InputInt("##SampleSize", &sampleSize, 1, 10);

	if (ImGui::Button("Thrash the Cache GameObject"))
	{
		exTwo.clear();
		ExerciseTwo();

		rerunTests = false;
	}
	if (exTwo.size() > 0)
	{
		//GameObject3D
		ImGui::PlotConfig conf2;
		conf2.values.xs = steps.data();
		conf2.values.ys = exTwo.data();
		conf2.values.count = static_cast<int>(exTwo.size());
		conf2.scale.min = 0;
		conf2.scale.max = *std::max_element(exTwo.begin(), exTwo.end());
		conf2.tooltip.show = true;
		conf2.tooltip.format = "Step: %g, Time: %.2f ";
		conf2.grid_x.show = true;
		conf2.grid_y.show = true;
		conf2.frame_size = ImVec2(200, 100);
		conf2.line_thickness = 2.f;
		ImGui::Plot("Exercise 2 - GameObject3D", conf2);
	}

	if (ImGui::Button("Thrash the Cache GameObjectAlt"))
	{
		exTwo.clear();
		ExerciseTwo();
		exTwoAlt.clear();
		ExerciseTwoAlt();

		rerunTests = false;
	}

	if (exTwoAlt.size() > 0)
	{
		//GameObject3DAlt
		ImGui::PlotConfig conf3;
		conf3.values.xs = steps.data();
		conf3.values.ys = exTwoAlt.data();
		conf3.values.count = static_cast<int>(exTwoAlt.size());
		conf3.scale.min = 0;
		conf3.scale.max = *std::max_element(exTwoAlt.begin(), exTwoAlt.end());
		conf3.tooltip.show = true;
		conf3.tooltip.format = "Step: %g, Time: %.2f";
		conf3.grid_x.show = true;
		conf3.grid_y.show = true;
		conf3.frame_size = ImVec2(200, 100);
		conf3.line_thickness = 2.f;
		ImGui::Plot("Exercise 2 - GameObject3DAlt", conf3);
	}

	if(exTwo.size() > 0 and exTwoAlt.size() > 0)
	{
		//GameObject3D Combined
		static const float* ys_data[] = { exTwo.data(), exTwoAlt.data() };
		static ImU32 colors[] = { ImColor(0, 255, 0), ImColor(255, 0, 0) }; // Green GameObject3D, Red GameObject3DAlt
		ImGui::PlotConfig confCombined;
		confCombined.values.xs = steps.data();
		confCombined.values.ys_list = ys_data;
		confCombined.values.ys_count = 2;
		confCombined.values.count = static_cast<int>(exTwo.size());
		confCombined.values.colors = colors;
		confCombined.scale.min = 0;
		confCombined.scale.max = std::max(*std::max_element(exTwo.begin(), exTwo.end()), *std::max_element(exTwoAlt.begin(), exTwoAlt.end()));
		confCombined.tooltip.show = true;
		confCombined.tooltip.format = "Step: %g, Time: %.2f";
		confCombined.grid_x.show = true;
		confCombined.grid_y.show = true;
		confCombined.frame_size = ImVec2(200, 100);
		confCombined.line_thickness = 2.f;
		ImGui::Plot("Exercise 2 - GameObject3D vs GameObject3DAlt", confCombined);
	}

	ImGui::End();
}
