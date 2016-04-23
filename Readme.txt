*** Plymouth Campaign Pursued - Scenario 2: On the Run

A new Plymouth Land Rush into Evacuation Campaign Scenario for Outpost 2 programmed by Vagabond in Apr of 2016. The
scenario is compatible with Windows and WINE, although I only test scenarios on Windows before releasing. 

*** Install Directions

 * Place the .map, .dll, and research tree (other .txt file) in your root Outpost 2 install directory. 
   Some scenarios share maps (.map) and research trees (.txt). You should not need to install over already 
   downloaded versions of maps and tech trees unless the map or tech tree is being patched for all scenarios
   using it.
 * Open Outpost 2 and search for the new scenario with the other colony games.
 * Good luck, and have fun!

*** Source Code

Scenario 2: On the Run was built using C++ in Visual Studio 2015 using the Visual Studio 2015 Build Tools. 
C++11 and the C++ Standard Library are both used. If you want to load the scenario into a different IDE, 
a C++11 compliant IDE is required. Your IDE will also need support for the windows API and the Outpost 2 SDK ver 2.1.

Post Build Events: 3 post build events are remarked out (rem) to prevent them from copying 
files on another person's computer without their knowledge. Remove the rem from the 3 lines to
enable them.

If you need help troubleshooting the compiled scenario or the source code, use the OutpostUniverse forums.

** Bugs

 * Minor: You do not have to actually load the vehicles in into a garage to patch them. The game will patch
   the vehicles when they roll over the garage docking port. I could not find a way through the SDK to 
   detect which specific vehicles were loaded into a garage bay. You should still load each vehicle into the
   garage to simulate game intent, but nothing will stop you from shortcutting here :).

 * Minor: The starting RoboMiner is considered patched from the communication virus at scenario start.
   There is a bug in the SDK where if a roboMiner builds a common ore mine, calling the function
   IsLive still returns true. Likely, the player cannot advance until they use the starting RoboMiner, 
   so it shouldn't be noticiable by the player.

** Credits

  * SirBomber - For making great tutorials that without I probably wouldn't have been able to learn the SDK.
  * Hooman - For providing technical help, especially for re-creating the Plymouth Starship II colony game. 
    This provided a lot of insight on using the SDK. Also, for solving the victory conditions/Saving bug.