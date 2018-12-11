local ROOT_PATH = path.getabsolute("..")

function winSdkVersion()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
    if sdk_version ~= nil then return sdk_version end
end

workspace "SCI_GE_Framework"
    configurations {
        "Debug",
        "Release",
    }
    location (ROOT_PATH .. "/_output/build/")

project "GameEngine"
    kind "ConsoleApp"
    language "C"
    architecture "x86"
    targetdir (ROOT_PATH .. "/_output/bin/%{cfg.buildcfg}/")
    systemversion(winSdkVersion() .. ".0")

    files {
        ROOT_PATH .. "/source/**.hpp",
        ROOT_PATH .. "/source/**.cpp",
    }
    
    includedirs {
        ROOT_PATH .. "/source/",
        ROOT_PATH .. "/third_party/SDL2-2.0.9/include/",
        ROOT_PATH .. "/third_party/glew-2.1.0/include/",
        ROOT_PATH .. "/third_party/glm-0.9.9.3/include/",
    }

    libdirs {
        ROOT_PATH .. "/third_party/SDL2-2.0.9/lib/x86/",
        ROOT_PATH .. "/third_party/glew-2.1.0/lib/x86/",
    }

    links {
        "SDL2.lib",
        "SDL2main.lib",
        "glew32.lib",
        "opengl32.lib"
    }

    postbuildcommands {
        "{COPY} " .. ROOT_PATH .. "/third_party/SDL2-2.0.9/bin/x86/SDL2.dll %{cfg.targetdir}",
        "{COPY} " .. ROOT_PATH .. "/third_party/glew-2.1.0/bin/x86/glew32.dll %{cfg.targetdir}",
    }

    filter "configurations:Debug"
        defines {
            "DEBUG",
        }
        symbols "On"

    filter "configurations:Release"
        defines {
            "NDEBUG",
        }
        optimize "On"
