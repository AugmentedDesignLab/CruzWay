# CruzWay
CruzWay comes with the capability of using behavior tree based NPC vehicle agent for simulation.   
## Folder Structure:
- Binaries
- Config
- Content (contains Behavior Tree and Blackboard asset)
- Intermediate
- Resources
- Source/BT_Plugin (C++ files)
- BT_Plugin.uplugin
## Dependency
- ParseXML (ParseXML provides the WayPoints what is required for the BT agent to run)
## How to create custom vehicle agent in UE4
- Import necessary skeletal mesh with appropriate materials. Unreal marketplace provides several free assets for vehicles especially cars.  
- Find the WheeledVehicleObject class in the editor and right-click on it to create a custom blueprint based on WheeledVehicleObject (IMAGE). 
- Select VehicleController as AI Controller class
- Select appropriate skeletal mesh in the "mesh component" of the newly created vehicle blueprint.  
- Put the bone names from the physics asset in exact order to vehicle setup of Vehicle Movement component. Select proper wheel class that comes with the vehicle asset. 
- compile and save
## How to create scenario with the BT based agents:
The current scenario generator is able to spawn BT based vehicle on a specific WayPoint. Current behavior tree capabilities are: Lane Folloow and Stop sign behavior. To spawn custom vehicle, first run the ParseXML plugin to create roads. This will also provide road structures through WayPoints. Put the actor SceneGen in the map. Select the type of vehicle, WayPoint and corresponding Behavior tree asset. 
