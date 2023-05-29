SFML_ImGui_Dock
=====
### About
SFML_ImGui_Dock is an easy to set-up ImGui to be used in SFML with docking ability. For this project **premake5** is used to set up project and its correct configurations for building.

Main **ImGui** structure (docking branch) is forked from: (https://github.com/ocornut/imgui)<br>
Necessary files for creating the **SFML** backend implementation are forked from: (https://github.com/SFML/imgui-sfml)<br>

### Dependencies
1. **SFML**
2. **Premake**

### Setup
1. Clone this repository to your dependencies/vendor etc. folder
2. Setup your main premake5.lua file:
    - Include SFML_ImGui_Dock project. Let's assume that SFML_ImGui_Dock is located in /vendor/SFML_ImGui_Dock. Put this on a workspace: `include "vendor/SFML_ImGui_Dock"`
    - Add `vendor/SFML_ImGui_Dock`to your project's `includedirs`
    - Add `SFML_ImGui_Dock` to your project's `links`
3. Make a cpp file called ex. "ImGuiBuild" to your project's source.
4. Add only this line to the file: `#include <backends/imgui_impl_sfml.cpp>`

### Usage
Basically you need to include these main 2 header files to get things running:
``` cpp
#include <imgui.h>
#include <backends/imgui_impl_sfml.h>
```

For further details check those original repos.
