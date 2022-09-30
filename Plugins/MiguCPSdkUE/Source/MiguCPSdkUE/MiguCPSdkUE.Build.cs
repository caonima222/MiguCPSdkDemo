// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class MiguCPSdkUE : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/")); }
    }

	public MiguCPSdkUE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				Path.Combine(ModuleDirectory, "Public"),
				//Path.Combine(ThirdPartyPath, "include"),
			}
			);
		
		PrivateIncludePaths.AddRange(
			new string[] {
				Path.Combine(ModuleDirectory, "Private"),
				//Path.Combine(ThirdPartyPath, "include"),
				// ... add other private include paths required here ...
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);



        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
	        string LibraryPath = Path.Combine(ThirdPartyPath, Target.Platform.ToString());
            PublicLibraryPaths.Add(LibraryPath);

            

            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "MiguCpSdk.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "libcrypto-1_1-x64.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "libssl-1_1-x64.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "ucrtbase.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "viumsgsdk.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "zlib1.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(LibraryPath, "libcurl.dll"));
            PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "MiguCpSdk.lib"));



        }
	}
}
