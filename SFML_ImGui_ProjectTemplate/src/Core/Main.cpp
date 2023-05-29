#include "Window.h"
#include "../ImGui/GUI.h"

#include <iostream>

// Main function
int main(int argc, char** argv)
{
	// Declare running variable that indicates the state of program
	bool running = true;

	// Create window
	Window window(sf::Vector2f(1920, 1080), "ProjectTemplate");

	// Initialize ImGui
	GUI gui(window.GetWindow());

	// Clock for deltaTime
	sf::Clock deltaClock;

	// Window flags for "subwindows"
	//ImGuiWindowFlags subWindowFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
	ImGuiWindowFlags subWindowFlags = ImGuiWindowFlags_None;

	while (running)
	{
		// Update ImGui
		gui.Update(deltaClock.restart());

		window.CheckEvent([&](const sf::Event& event)
		{
			// Pass events to ImGui
			gui.ProcessEvent(event);

			// Close window when it is supposed to going to be closed
			if (event.type == sf::Event::Closed)
			{
				window.Close();
				running = false;
			}
		});

		// Create dockspace lambda
		gui.CreateDockspace([&]()
		{		
			ImGui::Begin("Window1", (bool*)true, subWindowFlags);
			ImGui::End();

			// Viewport
			ImGui::Begin("Viewport", (bool*)true, subWindowFlags);

			// Create viewport and draw nodes to it
			gui.CreateViewport([&](float scale, sf::RenderTexture& renderTexture)
			{
				sf::RectangleShape shape;
				shape.setSize({ 100 * scale, 100 * scale });
				shape.setPosition({ 100 * scale, 100 * scale });
				renderTexture.draw(shape);
			});

			ImGui::End();
		});

		// Window update
		window.Update([&]()
		{
			// Draw ImGui
			gui.Render();
		});
	}

	gui.Shutdown();

	return 0;
}