project "SFML_ImGui_Dock"
    kind "StaticLib"
    language "C++"
    
    targetdir("bin/%{cfg.buildcfg}")
    objdir("bin-int/%{cfg.buildcfg}")

    files
	{
        "*.cpp",
        "*.h"
	}

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "on"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "on"