#include "MapHelper.h"
#include "UnitHelper.h"
#include "Disasters.h"
#include "ScriptGlobal.h"
#include "VictoryConditions.h"
#include <OP2Helper/OP2Helper.h>
#include <Outpost2DLL/Outpost2DLL.h>

// Required data exports  (Description, Map, TechTree, GameType, NumPlayers)
ExportLevelDetails("Campaign - Ply, Pursued, Ep 2 - On the Run", "OnTheRun.map", "PursuedTechTree.txt", MissionTypes::Colony, 2);

UnitHelper::VehicleBuilder vehicleBuilderAI;

extern void ShowBriefing();
extern SongIds PlayList[]; 
ScriptGlobal scriptGlobal;

ExportSaveLoadData(scriptGlobal);

void InitializeAIHelperClasses() 
{
	vehicleBuilderAI.SetPlayer(Player0);
	vehicleBuilderAI.SetVehicleDirection(UnitDirection::West);
}

void initializeStartingUnits()
{
	std::vector<Unit> units;

	//These commented out vehicles are for testing victory conditions.
	//std::vector<map_id> turrets{ map_id::mapMicrowave, map_id::mapStickyfoam, map_id::mapRPG, map_id::mapEMP, map_id::mapESG };
	//vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(), UnitDirection::South, 1, map_id::mapLynx, turrets);
	//vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(), UnitDirection::South, 1, map_id::mapPanther, turrets);

	//Use to test sending units to the garage.
	//Unit building;
	//TethysGame::CreateUnit(building, map_id::mapCommandCenter, LOCATION(113 + X_, 64 + Y_), Player0, map_id::mapNone, 0);
	//TethysGame::CreateUnit(building, map_id::mapGarage, LOCATION(113 + X_, 67 + Y_), Player0, map_id::mapNone, 0);
	//TethysGame::CreateUnit(building, map_id::mapAgridome, LOCATION(113 + X_, 70 + Y_), Player0, map_id::mapNone, 0);
	//TethysGame::CreateUnit(building, map_id::mapVehicleFactory, LOCATION(113 + X_, 72 + Y_), Player0, map_id::mapNone, 0);
	//TethysGame::CreateUnit(building, map_id::mapCommonOreSmelter, LOCATION(113 + X_, 76 + Y_), Player0, map_id::mapNone, 0);
	//TethysGame::CreateUnit(building, map_id::mapTokamak, LOCATION(113 + X_, 75 + Y_), Player0, map_id::mapNone, 0);

	//Spiders cannot be loaded into a garage.
	//vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(117 + X_, 63 + Y_), UnitDirection::South, 2,
	//	std::vector<map_id> { map_id::mapSpider, map_id::mapSpider, map_id::mapScout });

	//vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	//units.clear();

	vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(119 + X_, 63 + Y_), UnitDirection::South, 2, map_id::mapLynx,
		std::vector<map_id> { map_id::mapMicrowave, map_id::mapEMP, map_id::mapStickyfoam, map_id::mapEMP, map_id::mapESG, map_id::mapESG });

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(121 + X_, 63 + Y_), UnitDirection::South, 2, map_id::mapPanther,
		std::vector<map_id> { map_id::mapRPG, map_id::mapRPG, map_id::mapStickyfoam, map_id::mapEMP});

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	if (Player[0].Difficulty() != PlayerDifficulty::DiffHard)
	{
		vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(121 + X_, 71 + Y_), UnitDirection::South, 2, map_id::mapPanther,
			std::vector<map_id>{map_id::mapESG});
	}

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(121 + X_, 73 + Y_), UnitDirection::South, 2,
		std::vector<map_id>{map_id::mapRoboSurveyor});

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(123 + X_, 63 + Y_), UnitDirection::South, 2,
		std::vector<map_id>{map_id::mapEvacuationTransport, map_id::mapEvacuationTransport, map_id::mapEvacuationTransport,
		map_id::mapRoboMiner, map_id::mapRoboDozer, map_id::mapEarthworker});

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	vehicleBuilderAI.CreateLineOfVehicles(units, LOCATION(125 + X_, 63 + Y_), UnitDirection::South, 2, map_id::mapConVec,
		std::vector<map_id> { map_id::mapCommandCenter, map_id::mapStructureFactory, map_id::mapCommonOreSmelter,
		map_id::mapTokamak, map_id::mapAgridome, map_id::mapRareStorage });

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	vehicleBuilderAI.CreateLineOfTrucksWithCargo(units, LOCATION(127 + X_, 63 + Y_), UnitDirection::South, 2,
		std::vector<Truck_Cargo> { Truck_Cargo::truckCommonMetal, Truck_Cargo::truckCommonMetal, Truck_Cargo::truckCommonMetal,
		Truck_Cargo::truckRareMetal, Truck_Cargo::truckFood, Truck_Cargo::truckFood });

	vehicleBuilderAI.MoveRelativeAmount(units, LOCATION(-3, 0));
	units.clear();

	vehicleBuilderAI.CauseRandomDamage(PlayerVehicleEnum(Player0), 40, 20, 60);

	PlayerVehicleEnum playerVehicleEnum = PlayerVehicleEnum(Player0);

	Unit unit;
	int index = 0;
	while (playerVehicleEnum.GetNext(unit))
	{
		//NOTE: Unit.IsLive() does not display a RoboMiner as dead if it builds a COMMON ore mine...
		if (unit.GetType() == map_id::mapRoboMiner)
		{
			continue;
		}

		scriptGlobal.StartingUnits[index] = unit;
		scriptGlobal.StartingUnitCured[index] = false;
		index++;
	}
}

void SetMultipleResearchedTechs(int playerNumb, std::vector<int> completedResearch)
{
	for (int techID : completedResearch)
	{
		Player[0].MarkResearchComplete(techID);
	}
}

void SetResearchedTech()
{
	//3401 Removed (cybernetic teleoperation).
	//05052 Removed (Garage)
	SetMultipleResearchedTechs(0, std::vector<int> { 2701, 2702, 2703, 2704, 2705, 3406, 3301, 3408, 7206, 7103, 8307, 5305,
		3303, 3402, 3405, 3302, 3304, 3305, 3201, 3202, 3901, 3306, 3851, 5110, 5201, 5202, 5111, 5317, 5508, 5116, 5599, 5307 });
}

void InitializeMiningBeacons()
{
	MAP_RECT beaconRect = MAP_RECT(115 + X_, 108 + Y_, 127 + X_, 120 + Y_);
	MapHelper::CreateBeaconInRegion(beaconRect, BeaconTypes::OreTypeCommon, Yield::Bar1, Variant::Variant1);

	beaconRect = MAP_RECT(21 + X_, 30 + Y_, 30 + X_, 55 + Y_);
	MapHelper::CreateBeaconInRegion(beaconRect, BeaconTypes::OreTypeCommon, Yield::Bar2, Variant::Variant2);

	MapHelper::CreateBeaconInRegion(MAP_RECT(51 + X_, 105 + Y_, 66 + X_, 109 + Y_),
		BeaconTypes::OreTypeCommon, Yield::Bar2, Variant::Variant2);

	beaconRect = MAP_RECT(LOCATION(113 + X_, 16 + Y_), LOCATION(127 + X_, 29 + Y_));
	MapHelper::CreateBeaconInRegion(beaconRect, BeaconTypes::OreTypeRare, Yield::BarRandom, Variant::VariantRandom);

	std::vector<Yield> yields{ Yield::Bar1, Yield::Bar2 };
	int firstYieldIndex = TethysGame::GetRand(1);
	Yield firstRareYield = yields[firstYieldIndex];
	yields.erase(yields.begin() + firstYieldIndex);
	Yield secondRareYield = yields[0];

	std::vector<LOCATION> possBeaconLocs{ LOCATION(21 + X_, 81 + Y_), LOCATION(22 + X_, 74 + Y_) };
	MapHelper::CreateBeaconFromRandomLocs(possBeaconLocs, BeaconTypes::OreTypeRare, firstRareYield, Variant::Variant2);

	possBeaconLocs = { LOCATION(40 + X_, 3 + Y_), LOCATION(60 + X_, 8 + Y_) };
	MapHelper::CreateBeaconFromRandomLocs(possBeaconLocs, BeaconTypes::OreTypeRare, secondRareYield, Variant::Variant2);
}

void InitializeFumarolesAndVents()
{
	MapHelper::CreateFumaroleInRegion(MAP_RECT(LOCATION(5 + X_, 103 + Y_), LOCATION(33 + X_, 126 + Y_)));
	MapHelper::CreateFumaroleInRegion(MAP_RECT(LOCATION(2 + X_, 2 + Y_), LOCATION(31 + X_, 11 + Y_)));

	MapHelper::CreateMagmaWellInRegion(MAP_RECT(LOCATION(58 + X_, 68 + Y_), LOCATION(81 + X_, 81 + Y_)));
	MapHelper::CreateMagmaWellInRegion(MAP_RECT(LOCATION(74 + X_, 2 + Y_), LOCATION(89 + X_, 9 + Y_)));
	MapHelper::CreateMagmaWellInRegion(MAP_RECT(LOCATION(2 + X_, 37 + Y_), LOCATION(11 + X_, 44 + Y_)));
}

void InitializeDisasterTrigger()
{
	int disasterTimeMin = 2500;
	int disasterTimeMax = 6500;

	if (Player[0].Difficulty() == 1)
	{
		disasterTimeMin = 2000;
		disasterTimeMax = 6000;
	}
	else if (Player[0].Difficulty() == 2)
	{
		disasterTimeMin = 1500;
		disasterTimeMax = 5500;
	}

	scriptGlobal.TrigDisaster = CreateTimeTrigger(true, false, disasterTimeMin, disasterTimeMax, "InitializeRandomDisaster");
}

void InitializeAttackTriggers()
{
	int marksUntilAttacked = 890;
	if (Player[0].Difficulty() == PlayerDifficulty::DiffNormal)
	{
		marksUntilAttacked = 840;
	}
	else if (Player[0].Difficulty() == PlayerDifficulty::DiffHard)
	{
		marksUntilAttacked = 770;
	}

	scriptGlobal.TrigScoutGroup = CreateTimeTrigger(true, true, (marksUntilAttacked + TethysGame::GetRand(20)) * 100, "CreateScoutFightGroup");
	scriptGlobal.TrigMainTankGroup = CreateTimeTrigger(false, false, 100 * 100, 150 * 100, "CreateMainFightGroups");
}

Export int InitProc()
{
	ShowBriefing();

	TethysGame::SetDaylightEverywhere(false); 
	TethysGame::SetDaylightMoves(true);
	GameMap::SetInitialLightLevel(TethysGame::GetRand(128));

	Player[0].CenterViewOn(113 + X_, 69 + Y_);

	Player[0].GoPlymouth();
	Player[0].SetColorNumber(PlayerColor::PlayerRed);
	Player[0].GoHuman();
	Player[0].SetKids(17);
	Player[0].SetWorkers(27);
	Player[0].SetScientists(12);
	Player[0].SetFoodStored(500);
	TethysGame::ForceMoraleGood(Player0);
	TethysGame::ForceMoraleGood(Player0);
	SetResearchedTech();

	if (Player[0].Difficulty() == PlayerDifficulty::DiffEasy)
	{
		TethysGame::ForceMoraleGreat(Player0);
		TethysGame::ForceMoraleGreat(Player0);
		Player[0].SetWorkers(37);
	}
	else if (Player[0].Difficulty() == PlayerDifficulty::DiffNormal)
	{
		Player[0].SetWorkers(30);
	}


	Player[1].GoEden();
	Player[1].SetColorNumber(PlayerColor::PlayerBlue);
	Player[1].GoAI();
	TethysGame::ForceMoraleGood(Player1);

	InitializeMiningBeacons();

	InitializeFumarolesAndVents();

	InitializeDisasterTrigger();

	VictoryConditions::InitializeVictoryConditions();
	
	InitializeAIHelperClasses();

	scriptGlobal.TrigFailureWaitTime = CreateTimeTrigger(false, false, 90, "NoResponseToTrigger");
	CreateFailureCondition(true, true, scriptGlobal.TrigFailureWaitTime, "Ignored");

	initializeStartingUnits();

	scriptGlobal.TrigBaseEstablished = CreateOperationalTrigger(
		true, true, Player0, map_id::mapCommandCenter, 1, compare_mode::cmpGreaterEqual, "BaseEstablished");

	InitializeAttackTriggers();

	TethysGame::SetMusicPlayList(5, 2, PlayList);

	Unit marker;
	TethysGame::PlaceMarker(marker, 6 + X_, 6 + Y_, MarkerTypes::Circle);
	TethysGame::PlaceMarker(marker, 6 + X_, 122 + Y_, MarkerTypes::Circle);

	return true;
}

bool CheckIfGameFailed()
{
	Player[0].resetChecks();

	if (Player[0].Workers() < 8)
	{
		return true;
	}
	else if (Player[0].Scientists() < 3)
	{
		return true;
	}
	else if (!UnitHelper::BuildingOrKitAvailable(Player0, map_id::mapCommandCenter))
	{
		return true;
	}
	else if (!UnitHelper::BuildingOrKitAvailable(Player0, map_id::mapStructureFactory))
	{
		return true;
	}

	return false;
}

void CheckIfCriticalResearchComplete(int techID, Trigger &researchTimeTrigger)
{
	if (!researchTimeTrigger.IsEnabled() && 
		!researchTimeTrigger.HasFired(Player0) && 
		Player[0].HasTechnology(techID))
	{
		researchTimeTrigger.Enable();

		PlayerBuildingEnum playerBuildingEnum(Player0, map_id::mapStandardLab);
		
		Unit building;
		while (playerBuildingEnum.GetNext(building))
		{
			if (building.GetType() == map_id::mapStandardLab)
			{
				break;
			}
		}
		
		TethysGame::AddMessage(building, "Critical Research Complete.", Player0, SoundID::sndBeep9);
	}
}

void CheckCriticalResearch()
{
	CheckIfCriticalResearchComplete(2706, scriptGlobal.TrigTimeResearch2706);
	CheckIfCriticalResearchComplete(2707, scriptGlobal.TrigTimeResearch2707);
	CheckIfCriticalResearchComplete(7102, scriptGlobal.TrigTimeResearch7102);
	CheckIfCriticalResearchComplete(8203, scriptGlobal.TrigTimeResearch8203);

	if (Player[0].Difficulty() == PlayerDifficulty::DiffNormal ||
		Player[0].Difficulty() == PlayerDifficulty::DiffHard)
	{
		CheckIfCriticalResearchComplete(8306, scriptGlobal.TrigTimeResearch8306);
		CheckIfCriticalResearchComplete(8309, scriptGlobal.TrigTimeResearch8309);
		CheckIfCriticalResearchComplete(10303, scriptGlobal.TrigTimeResearch10303);
	}

	if (Player[0].Difficulty() == PlayerDifficulty::DiffHard)
	{
		CheckIfCriticalResearchComplete(8320, scriptGlobal.TrigTimeResearch8320);
		CheckIfCriticalResearchComplete(7212, scriptGlobal.TrigTimeResearch7212);
		CheckIfCriticalResearchComplete(10306, scriptGlobal.TrigTimeResearch10306);
	}
}

void SetFoodDuringLandRush()
{
	if (scriptGlobal.BaseEstablished)
	{
		return;
	}

	int startingFood = 1500;

	if (Player[0].Difficulty() == PlayerDifficulty::DiffNormal)
	{
		startingFood = 1000;
	}
	else if (Player[0].Difficulty() == PlayerDifficulty::DiffHard)
	{
		startingFood = 500;
	}

	//Note: Starting Food amount is required in this check. Otherwise, you will dump your food in the
	//      Agridome before the CC is constructed, and it will disappear. 
	if (Player[0].FoodStored() < startingFood)
	{
		Player[0].SetFoodStored(startingFood);
	}
}

void VehicleCommandLinkCompromiseEffect()
{
	// Note: Using the Modulus operator to make compromise only occur about every 3-4 marks.
	if (TethysGame::Time() % 75 == 0)
	{
		TethysGame::AddMessage(140 * 32, 1 * 32, "Vehicle Command Link Compromised.", Player0, SoundID::sndBeep9);

		PlayerVehicleEnum playerVehicleEnum = PlayerVehicleEnum(Player0);

		Unit vehicle;
		LOCATION loc;
		while (playerVehicleEnum.GetNext(vehicle))
		{
			loc = LOCATION(TethysGame::GetRand(128) + X_, TethysGame::GetRand(128) + Y_);
			vehicle.DoMove(loc);
		}
	}
}

void MarkDestroyedStartingUnitsAsCured()
{
	for (int i = 0; i < scriptGlobal.StartingUnitCount; ++i)
	{
		if (!scriptGlobal.StartingUnits[i].IsLive()) {
			scriptGlobal.StartingUnitCured[i] = true;
		}
	}
}

bool CheckVehiclesCured()
{
	for (int i = 0; i < scriptGlobal.StartingUnitCount; ++i)
	{
		if (!scriptGlobal.StartingUnitCured[i]) {
			return false;
		}
	}

	return true;
}

void SetCuredVehicles()
{
	PlayerBuildingEnum playerBuildingEnum = PlayerBuildingEnum(PlayerNum::Player0, map_id::mapGarage);
	UnitEx garage;

	while (playerBuildingEnum.GetNext(garage))
	{
		LOCATION dockLoc = garage.GetDockLocation();

		for (int i = 0; i < scriptGlobal.StartingUnitCount; ++i)
		{
			// Checking for tech Vehicle Encryption Patch is not necessary as  
			// it is required before vehicle factories or garages may be built.
			if (!scriptGlobal.StartingUnitCured[i] &&
				scriptGlobal.StartingUnits[i].Location().x == dockLoc.x &&
				scriptGlobal.StartingUnits[i].Location().y == dockLoc.y)
			{
				scriptGlobal.StartingUnitCured[i] = true;
				TethysGame::AddMessage(garage, "Vehicle Receiver Refitted.", Player0, SoundID::sndMessage2);
			}
		}
	}
}

Export void AIProc() 
{
	if (!scriptGlobal.TrigUnitsCured.IsEnabled()) {
		MarkDestroyedStartingUnitsAsCured();
		SetCuredVehicles();
		if(CheckVehiclesCured()) {
			scriptGlobal.TrigUnitsCured.Enable();
		}

	}

	VictoryConditions::CheckCombatUnitVictoryConditions();

	if (scriptGlobal.TrigScoutGroup.HasFired(Player0) && !scriptGlobal.TrigUnitsCured.HasFired(Player0))
	//if (!Player[0].HasTechnology(2707)) //For testing CommandLinkCompromised
	{
		VehicleCommandLinkCompromiseEffect();
	}

	SetFoodDuringLandRush();

	if (CheckIfGameFailed())
	{
		scriptGlobal.TrigFailureWaitTime.Enable();
	}

	CheckCriticalResearch();
}

Export void NoResponseToTrigger() {}

void PopulateFightGroup(FightGroup &fightGroup, const std::vector<Unit> &units)
{
	fightGroup = CreateFightGroup(Player1);

	for (Unit unit : units)
	{
		fightGroup.TakeUnit(unit);
	}

	fightGroup.SetAttackType(map_id::mapCommandCenter);
	fightGroup.DoAttackEnemy();
}

LOCATION GetStartLocation(UnitDirection &lineDirection, UnitDirection &vehicleDirection)
{
	LOCATION startLoc;
	int locSwitch = TethysGame::GetRand(4);

	switch (locSwitch)
	{
	case 0:
		startLoc = LOCATION(107 + X_, 1 + Y_);
		lineDirection = UnitDirection::East;
		vehicleDirection = UnitDirection::South;
		break;
	case 1:
		startLoc = LOCATION(128 + X_, 18 + Y_);
		lineDirection = UnitDirection::South;
		vehicleDirection = UnitDirection::West;
		break;
	case 2:
		startLoc = LOCATION(128 + X_, 103 + Y_);
		lineDirection = UnitDirection::South;
		vehicleDirection = UnitDirection::West;
		break;
	case 3:
		startLoc = LOCATION(101 + X_, 127 + Y_);
		lineDirection = UnitDirection::East;
		vehicleDirection = UnitDirection::North;
		break;
	}

	return startLoc;
}

void CreateGenericFightGroup(FightGroup &fightGroup, map_id tankType, const std::vector<map_id> &turrets)
{
	LOCATION startLoc;
	UnitDirection lineDirection;
	UnitDirection vehicleDirection;

	startLoc = GetStartLocation(lineDirection, vehicleDirection);

	vehicleBuilderAI.SetPlayer(Player1);
	vehicleBuilderAI.SetVehicleDirection(vehicleDirection);

	std::vector<Unit> units;
	vehicleBuilderAI.CreateLineOfVehicles(units, startLoc, lineDirection, 1, tankType, turrets);

	PopulateFightGroup(fightGroup, units);
}

Export void CreateScoutFightGroup()
{
	CreateGenericFightGroup(scriptGlobal.ScoutFightGroup, map_id::mapLynx,
		std::vector<map_id> { map_id::mapEMP, map_id::mapThorsHammer, map_id::mapAcidCloud,
		map_id::mapRailGun, map_id::mapEMP, map_id::mapThorsHammer, map_id::mapAcidCloud, map_id::mapRailGun });

	scriptGlobal.TrigMainTankGroup.Enable();
	scriptGlobal.TrigScoutGroup.Disable();
}

Export void CreateMainFightGroups()
{
	// Panther Squadron
	CreateGenericFightGroup(scriptGlobal.MainFightGroup1, map_id::mapPanther, 
		std::vector<map_id> { map_id::mapEMP, map_id::mapThorsHammer, map_id::mapAcidCloud,
		map_id::mapRailGun, map_id::mapEMP, map_id::mapThorsHammer, map_id::mapAcidCloud, map_id::mapRailGun,
		map_id::mapThorsHammer, map_id::mapThorsHammer, map_id::mapEMP, map_id::mapRailGun });

	// Tiger Squadron
	LOCATION tigerStartLoc = LOCATION(128 + X_, 63 + Y_);
	std::vector<Unit> units;
	vehicleBuilderAI.SetVehicleDirection(UnitDirection::West);

	std::vector<map_id> turrets{ map_id::mapEMP, map_id::mapThorsHammer, map_id::mapAcidCloud,
		map_id::mapRailGun, map_id::mapEMP, map_id::mapThorsHammer, map_id::mapAcidCloud, map_id::mapRailGun,
		map_id::mapThorsHammer, map_id::mapThorsHammer, map_id::mapEMP, map_id::mapRailGun };

	vehicleBuilderAI.CreateLineOfVehicles(units, tigerStartLoc, UnitDirection::South, 1, map_id::mapTiger, turrets);
	vehicleBuilderAI.CreateLineOfVehicles(units, tigerStartLoc + LOCATION(-1, 0), UnitDirection::South, 1, map_id::mapTiger, turrets);

	PopulateFightGroup(scriptGlobal.MainFightGroup2, units);
}

Export void InitializeRandomDisaster()
{
	std::vector<LOCATION> criticalBuildingLocations;

	UnitHelper::FindBuildingLocations(criticalBuildingLocations, Player0,
		std::vector<map_id> { map_id::mapCommandCenter, map_id::mapStructureFactory, map_id::mapCommonOreSmelter });

	CreateRandomDisaster(criticalBuildingLocations);
}

Export void BaseEstablished()
{
	if (!scriptGlobal.BaseEstablished)
	{
		scriptGlobal.BaseEstablished = true;
		scriptGlobal.TrigBaseEstablished.Disable();

		PlayerBuildingEnum playerBuildingEnum = PlayerBuildingEnum(Player0, map_id::mapCommandCenter);

		Unit unit;
		while (playerBuildingEnum.GetNext(unit))
		{
			if (unit.GetType() == map_id::mapCommandCenter)
			{
				TethysGame::AddMessage(unit, "Base Established, Good Luck Commander!", Player0, SoundID::sndMessage2);
				break;
			}
		}

		TethysGame::FreeMoraleLevel(PlayerNum::Player0);
	}
}
