using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;
using System.Diagnostics;
#if UE_5_0_OR_LATER
using EpicGames.Core;
#else
using Tools.DotNETCommon;
#endif

public class SubstanceConnector : ModuleRules
{
    public string GetBuildConfig(ReadOnlyTargetRules Target)
	{
		if (Target.Configuration == UnrealTargetConfiguration.Debug)
		{
			if (Target.IsInPlatformGroup(UnrealPlatformGroup.Windows))
			{
				if (Target.bDebugBuildsActuallyUseDebugCRT)
					return "Debug";
			}
			else
			{
				return "Debug";
			}
		}

		return "Release";
	}
    public string GetPlatformConfig(ReadOnlyTargetRules Target)
    {
        return Target.Platform.ToString();
    }

    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string PluginRootPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../")); }
    }
  

    public SubstanceConnector(ReadOnlyTargetRules Target) : base(Target)
	{

        string BuildConfig = GetBuildConfig(Target);
		string PlatformConfig = GetPlatformConfig(Target);
		string SubstanceLibPath = ModuleDirectory + "/../../Libs/" + BuildConfig + "/" + PlatformConfig + "/";

        //PCH file
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivatePCHHeaderFile = "Private/SubstanceConnectorPrivatePCH.h";

        List<string> StaticLibs = new List<string>();

        string LibExtension = "";
		string LibPrefix = "";
		if (Target.IsInPlatformGroup(UnrealPlatformGroup.Windows))
		{
			LibExtension = ".lib";

			StaticLibs.Add("jsoncpp_static");
			StaticLibs.Add("substance_connector");
			StaticLibs.Add("substanceconnector_framework");
		}
		else if (Target.Platform == UnrealTargetPlatform.Mac ||
		         Target.Platform == UnrealTargetPlatform.Linux)
		{
			LibExtension = ".a";
			LibPrefix = "lib";

			StaticLibs.Add("jsoncpp");
			StaticLibs.Add("substance_connector");
			StaticLibs.Add("substanceconnector_framework");
		}
		else
		{
			throw new BuildException("Substance Plugin does not support platform " + Target.Platform.ToString());
		}


        PublicIncludePaths.Add(PluginRootPath + "/include");
        PublicIncludePaths.Add(PluginRootPath + "/Source/SubstanceEditor/Classes");

        //add our static libs
		foreach (string staticlib in StaticLibs)
		{
			string libname = LibPrefix + staticlib + LibExtension;
			PublicAdditionalLibraries.Add(SubstanceLibPath + libname);
		}

        //Module dependencies
        PrivateDependencyModuleNames.AddRange(new string[]
        {
                "Projects",
                "Slate",
                "SlateCore",
                "SubstanceEditor",
                "ContentBrowser",
                "ContentBrowserData"
        });

        PublicDependencyModuleNames.AddRange(new string[]
        {
                "AssetRegistry",
                "Core",
                "CoreUObject",
                "Json",
                "SubstanceEditor",
                "UnrealEd",
                "AssetTools",
                "Settings"
        });
    }
}
