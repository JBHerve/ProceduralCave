# Procedural Cave

Procdedural Cave generator, working with a Cellular Automata.

## Getting Started

Once you clone or download the project, you will need Visual Studio with a Visual C++ compiler in order to compile the project. In the latest version, the project use the platform toolset v140.

Please make sure you have SFML 2 install or the .dll in your output's directory.
If you use the `Debug` configuration, you will need the debug .dll (`sfml-mysuperdll-d-2.dll`)

Note that I didn't add the x64 include (for no particular reasons, I don't think you really need it), so do not expect to compile on this platform.

## How does it works

Just run the program, and watch the cave appear as the Cellular Automata iterate (12 times, it may takes approximately 12 seconds).
Whenever you click, it start a new generation with a new seed.

![Alt Text](https://github.com/Zibe/ProceduralCave/Capture.JPG)

## TODO

 - Add the x64 platform.
 - Launch a new generation when the user focus the program's window, not when clicking around.
 - Improve the algorithm.
 
 ### UI
 	Remove the hard-coded value in the code and allow to dynamically change :
 	- Grid size
 	- Seed
 	- Number of iterations