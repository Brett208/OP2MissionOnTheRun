#include "VictoryConditions.h"

namespace VictoryConditions
{
	UnitHelper::VehicleCounter vehicleCounter;

	MAP_RECT evacuateArea(LOCATION(1 + X_, 1 + Y_), LOCATION(20 + X_, 20 + Y_));
	//MAP_RECT evacuateArea(LOCATION(104 + X_, 82 + Y_), LOCATION(124 + X_, 102 + Y_));
	MAP_RECT fightStageArea(LOCATION(1 + X_, 108 + Y_), LOCATION(20 + X_, 128 + Y_));

	int EscapeTime = 5;

	void CreateCountVictoryTrigger(Trigger& trigger, map_id unit, map_id cargo, int minCount, char* missionObjective)
	{
		trigger = CreateCountTrigger(true, false, Player0, unit, cargo, minCount, compare_mode::cmpGreaterEqual, "NoResponseToTrigger");
		CreateVictoryCondition(true, false, trigger, missionObjective);
	}

	void CreateCountVictoryTrigger(Trigger& trigger, map_id unit, int minCount, char* missionObjective)
	{
		CreateCountVictoryTrigger(trigger, unit, map_id::mapNone, minCount, missionObjective);
	}

	void CreateResearchVictoryTrigger(Trigger& trigger, int techID, char* missionObjective)
	{
		trigger = CreateTimeTrigger(false, true, 100, "NoResponseToTrigger");
		//NOTE: CreateResearchTrigger seems to be broken in the SDK. Using TimeTrigger hack instead.
		//trigger = CreateResearchTrigger(true, true, techID, Player0, "CriticalResearchComplete");
		CreateVictoryCondition(true, true, trigger, missionObjective);
	}

	void CreateEscapeVictoryCondition(Trigger& trigger, MAP_RECT rect, int unitCount, map_id unitType, int cargoType, int cargoAmount, char* missionObjective)
	{
		trigger = CreateEscapeTrigger(true, false, Player0, rect.x1, rect.y1, rect.Width(), rect.Height(), unitCount, unitType, cargoType, cargoAmount, "NoResponseToTrigger");
		CreateVictoryCondition(true, false, trigger, missionObjective);
	}

	void CreateTimeVictoryCondition(Trigger& trigger, Trigger& victoryTrigger, int time, char* missionObjective)
	{
		trigger = CreateTimeTrigger(false, false, time, "NoResponseToTrigger");
		victoryTrigger = CreateVictoryCondition(true, false, trigger, missionObjective);
	}

	void CreateNWLynxMicrowaveVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWLynxMicrowave, scriptGlobal.VictoryTriggerNWLynxMicrowave, EscapeTime, "Stage 2 Microwave Lynx to the Northwest.");
	}

	void CreateNWLynxStickyfoamVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWLynxStickyfoam, scriptGlobal.VictoryTriggerNWLynxStickyfoam, EscapeTime, "Stage 2 Stickyfoam Lynx to the Northwest.");
	}

	void CreateNWLynxRpgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWLynxRpg, scriptGlobal.VictoryTriggerNWLynxRpg, EscapeTime, "Stage 2 RPG Lynx to the Northwest.");
	}

	void CreateNWLynxEmpVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWLynxEmp, scriptGlobal.VictoryTriggerNWLynxEmp, EscapeTime, "Stage 2 EMP Lynx to the Northwest.");
	}

	void CreateNWLynxEsgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWLynxEsg, scriptGlobal.VictoryTriggerNWLynxEsg, EscapeTime, "Stage 2 ESG Lynx to the Northwest.");
	}

	void CreateNWPantherMicrowaveVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWPantherMicrowave, scriptGlobal.VictoryTriggerNWPantherMicrowave, EscapeTime, "Stage 1 Microwave Panther to the Northwest.");
	}

	void CreateNWPantherStickyfoamVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWPantherStickyfoam, scriptGlobal.VictoryTriggerNWPantherStickyfoam, EscapeTime, "Stage 1 Stickyfoam Panther to the Northwest.");
	}

	void CreateNWPantherRpgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWPantherRpg, scriptGlobal.VictoryTriggerNWPantherRpg, EscapeTime, "Stage 1 RPG Panther to the Northwest.");
	}

	void CreateNWPantherEmpVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWPantherEmp, scriptGlobal.VictoryTriggerNWPantherEmp, EscapeTime, "Stage 1 EMP Panther to the Northwest.");
	}

	void CreateNWPantherEsgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeNWPantherEsg, scriptGlobal.VictoryTriggerNWPantherEsg, EscapeTime, "Stage 1 ESG Panther to the Northwest.");
	}

	void CreateSWLynxMicrowaveVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWLynxMicrowave, scriptGlobal.VictoryTriggerSWLynxMicrowave, EscapeTime, "Stage 4 Microwave Lynx to the Southwest.");
	}

	void CreateSWLynxStickyfoamVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWLynxStickyfoam, scriptGlobal.VictoryTriggerSWLynxStickyfoam, EscapeTime, "Stage 4 Stickyfoam Lynx to the Southwest.");
	}

	void CreateSWLynxRpgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWLynxRpg, scriptGlobal.VictoryTriggerSWLynxRpg, EscapeTime, "Stage 4 RPG Lynx to the Southwest.");
	}

	void CreateSWLynxEmpVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWLynxEmp, scriptGlobal.VictoryTriggerSWLynxEmp, EscapeTime, "Stage 4 EMP Lynx to the Southwest.");
	}

	void CreateSWLynxEsgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWLynxEsg, scriptGlobal.VictoryTriggerSWLynxEsg, EscapeTime, "Stage 4 ESG Lynx to the Southwest.");
	}

	void CreateSWPantherMicrowaveVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWPantherMicrowave, scriptGlobal.VictoryTriggerSWPantherMicrowave, EscapeTime, "Stage 3 Microwave Panthers to the Southwest.");
	}

	void CreateSWPantherStickyfoamVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWPantherStickyfoam, scriptGlobal.VictoryTriggerSWPantherStickyfoam, EscapeTime, "Stage 3 Stickyfoam Panthers to the Southwest.");
	}

	void CreateSWPantherRpgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWPantherRpg, scriptGlobal.VictoryTriggerSWPantherRpg, EscapeTime, "Stage 3 RPG Panthers to the Southwest.");
	}

	void CreateSWPantherEmpVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWPantherEmp, scriptGlobal.VictoryTriggerSWPantherEmp, EscapeTime, "Stage 3 EMP Panthers to the Southwest.");
	}

	void CreateSWPantherEsgVictoryCondition()
	{
		CreateTimeVictoryCondition(scriptGlobal.TrigEscapeSWPantherEsg, scriptGlobal.VictoryTriggerSWPantherEsg, EscapeTime, "Stage 3 ESG Panthers to the Southwest.");
	}

	void InitializeVictoryConditions()
	{
		scriptGlobal.TrigVictoryColonists = CreateResourceTrigger(true, false, trig_res::resColonists, 80, Player0, compare_mode::cmpGreaterEqual, "NoResponseToTrigger");
		CreateVictoryCondition(true, false, scriptGlobal.TrigVictoryColonists, "Have 80 or more colonists.");

		//CreateResearchVictoryTrigger(trigVictory, 8319, "Spider Maintenance Software Revision");
		//CreateEvacTrigger(true, true, Player0, "Have Enough Evacuation Transports for your colonists.");

		CreateNWPantherEsgVictoryCondition();
		CreateNWPantherEmpVictoryCondition();
		CreateNWPantherRpgVictoryCondition();
		CreateNWPantherStickyfoamVictoryCondition();
		CreateNWPantherMicrowaveVictoryCondition();

		CreateNWLynxEsgVictoryCondition();
		CreateNWLynxEmpVictoryCondition();
		CreateNWLynxRpgVictoryCondition();
		CreateNWLynxStickyfoamVictoryCondition();
		CreateNWLynxMicrowaveVictoryCondition();

		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeFood, evacuateArea, 3, map_id::mapCargoTruck, (map_id)truckFood, 3000, "Stage 3,000 units of Food to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeRareMetals, evacuateArea, 2, map_id::mapCargoTruck, (map_id)truckRareMetal, 2000, "Stage 2,000 units of Rare Metals to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeCommonMetals, evacuateArea, 4, map_id::mapCargoTruck, (map_id)truckCommonMetal, 4000, "Stage 4,000 units of Common Metals to the Northwest.");

		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeEvacTransports, evacuateArea, 4, map_id::mapEvacuationTransport, map_id::mapAny, 0, "Stage 4 Evac Transports to the Nortwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeRoboDozer, evacuateArea, 1, map_id::mapRoboDozer, map_id::mapAny, 0, "Stage 1 RoboDozer to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeEarthworker, evacuateArea, 1, map_id::mapEarthworker, map_id::mapAny, 0, "Stage 1 Earthworker to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeRoboMiner, evacuateArea, 2, map_id::mapRoboMiner, map_id::mapAny, 0, "Stage 2 Robo-Miners to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeRoboSurveyors, evacuateArea, 2, map_id::mapRoboSurveyor, map_id::mapAny, 0, "Stage 2 Robo-Surveyors to the Northwest.");

		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeRareStorageKit, evacuateArea, 1, map_id::mapConVec, map_id::mapRareStorage, 1, "Stage ConVec with a Rare Metals Storage to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeAgridomeKit, evacuateArea, 1, map_id::mapConVec, map_id::mapAgridome, 1, "Stage ConVec with an Agridome to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeTokomakKit, evacuateArea, 1, map_id::mapConVec, map_id::mapTokamak, 1, "Stage ConVec with a Tokamak to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeCommonSmelterKit, evacuateArea, 1, map_id::mapConVec, map_id::mapCommonOreSmelter, 1, "Stage ConVec with a Common Ore Smelter to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeStructFactoryKit, evacuateArea, 1, map_id::mapConVec, map_id::mapStructureFactory, 1, "Stage ConVec with a Structure Factory to the Northwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeCCKit, evacuateArea, 1, map_id::mapConVec, map_id::mapCommandCenter, 1, "Stage ConVec with a Command Center to the Northwest.");

		//CreateEscapeVictoryCondition(trigVictory, evacuateArea, 6, map_id::mapPanther, map_id::mapAny, 0, "Stage 6 Panthers to the Northwest.");
		//CreateEscapeVictoryCondition(trigVictory, evacuateArea, 9, map_id::mapLynx, map_id::mapAny, 0, "Stage 9 Lynx to the Northwest.");

		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeSWSpiders, fightStageArea, 6, map_id::mapSpider, map_id::mapAny, 0, "Stage 6 Spiders to the Southwest.");
		CreateEscapeVictoryCondition(scriptGlobal.TrigEscapeSWScouts, fightStageArea, 2, map_id::mapScout, map_id::mapAny, 0, "Stage 2 Scouts to the Southwest.");
		//CreateEscapeVictoryCondition(trigVictory, fightStageArea, 9, map_id::mapPanther, map_id::mapAny, 0, "Stage 12 Panthers to the Southwest.");
		//CreateEscapeVictoryCondition(trigVictory, fightStageArea, 12, map_id::mapLynx, map_id::mapAny, 0, "Stage 15 Lynx to the Southwest.");

		CreateSWPantherEsgVictoryCondition();
		CreateSWPantherEmpVictoryCondition();
		CreateSWPantherRpgVictoryCondition();
		CreateSWPantherStickyfoamVictoryCondition();
		CreateSWPantherMicrowaveVictoryCondition();

		CreateSWLynxEsgVictoryCondition();
		CreateSWLynxEmpVictoryCondition();
		CreateSWLynxRpgVictoryCondition();
		CreateSWLynxStickyfoamVictoryCondition();
		CreateSWLynxMicrowaveVictoryCondition();

		Trigger victoryTrigger;
		CreateTimeVictoryCondition(scriptGlobal.TrigUnitsCured, victoryTrigger, 5, "Refit all starting vehicle receivers by sending them to the garage.");
		CreateCountVictoryTrigger(scriptGlobal.TrigGarageBuilt, map_id::mapGarage, 1, "Construct a Garage.");

		if (Player[0].Difficulty() == PlayerDifficulty::DiffHard)
		{
			CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch10306, 10306, "Research Grenade Loading Mechanism.");
			CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch7212, 7212, "Research Extended-Range Projectile Launcher.");
			CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch8320, 8320, "Research Reduced Foam Evaporation.");
		}

		if (Player[0].Difficulty() == PlayerDifficulty::DiffNormal ||
			Player[0].Difficulty() == PlayerDifficulty::DiffHard)
		{
			CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch8309, 8309, "Research Reinforced Panther Construction.");
			CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch10303, 10303, "Research Advanced Armoring Systems.");
			CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch8306, 8306, "Research Enhanced Defensive Fortifications.");
		}

		CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch8203, 8203, "Research High-Powered Explosives.");
		CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch7102, 7102, "Research Explosive Charges.");
		CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch2707, 2707, "Research Vehicle Encryption Patch from the Standard Lab.");
		CreateResearchVictoryTrigger(scriptGlobal.TrigTimeResearch2706, 2706, "Research Cryptology from the Standard Lab.");
	}

	void checkCombatUnitVictoryCondition(std::function<void()> victoryConditionInitializer, 
		Trigger &timeTrigger, Trigger &victoryTrigger, map_id vehicleType, map_id turretType, MAP_RECT mapRect, int unitCount)
	{
		if (vehicleCounter.GetVehicleCount(vehicleType, turretType) >= unitCount)
		{
			if (!timeTrigger.IsEnabled())
			{ 
				timeTrigger.Enable();
			}
		}
		else
		{
			if (timeTrigger.HasFired(Player0))
			{
				timeTrigger.Destroy();
				victoryTrigger.Destroy();

				victoryConditionInitializer();
			}
		}
	}

	void CheckNWCombatUnitVictoryConditions()
	{
		vehicleCounter.PullVehiclesFromRectangle(Player0, InRectEnumerator(evacuateArea));

		int lynxNWCount = 2;
		int pantherNWCount = 1;

		checkCombatUnitVictoryCondition(CreateNWLynxMicrowaveVictoryCondition,
			scriptGlobal.TrigEscapeNWLynxMicrowave, scriptGlobal.VictoryTriggerNWLynxMicrowave, map_id::mapLynx, map_id::mapMicrowave, evacuateArea, lynxNWCount);

		checkCombatUnitVictoryCondition(CreateNWLynxStickyfoamVictoryCondition,
			scriptGlobal.TrigEscapeNWLynxStickyfoam, scriptGlobal.VictoryTriggerNWLynxStickyfoam, map_id::mapLynx, map_id::mapStickyfoam, evacuateArea, lynxNWCount);

		checkCombatUnitVictoryCondition(CreateNWLynxRpgVictoryCondition,
			scriptGlobal.TrigEscapeNWLynxRpg, scriptGlobal.VictoryTriggerNWLynxRpg, map_id::mapLynx, map_id::mapRPG, evacuateArea, lynxNWCount);

		checkCombatUnitVictoryCondition(CreateNWLynxEmpVictoryCondition,
			scriptGlobal.TrigEscapeNWLynxEmp, scriptGlobal.VictoryTriggerNWLynxEmp, map_id::mapLynx, map_id::mapEMP, evacuateArea, lynxNWCount);

		checkCombatUnitVictoryCondition(CreateNWLynxEsgVictoryCondition,
			scriptGlobal.TrigEscapeNWLynxEsg, scriptGlobal.VictoryTriggerNWLynxEsg, map_id::mapLynx, map_id::mapESG, evacuateArea, lynxNWCount);

		checkCombatUnitVictoryCondition(CreateNWPantherMicrowaveVictoryCondition,
			scriptGlobal.TrigEscapeNWPantherMicrowave, scriptGlobal.VictoryTriggerNWPantherMicrowave, map_id::mapPanther, map_id::mapMicrowave, evacuateArea, pantherNWCount);

		checkCombatUnitVictoryCondition(CreateNWPantherStickyfoamVictoryCondition,
			scriptGlobal.TrigEscapeNWPantherStickyfoam, scriptGlobal.VictoryTriggerNWPantherStickyfoam, map_id::mapPanther, map_id::mapStickyfoam, evacuateArea, pantherNWCount);

		checkCombatUnitVictoryCondition(CreateNWPantherRpgVictoryCondition,
			scriptGlobal.TrigEscapeNWPantherRpg, scriptGlobal.VictoryTriggerNWPantherRpg, map_id::mapPanther, map_id::mapRPG, evacuateArea, pantherNWCount);

		checkCombatUnitVictoryCondition(CreateNWPantherEmpVictoryCondition,
			scriptGlobal.TrigEscapeNWPantherEmp, scriptGlobal.VictoryTriggerNWPantherEmp, map_id::mapPanther, map_id::mapEMP, evacuateArea, pantherNWCount);

		checkCombatUnitVictoryCondition(CreateNWPantherEsgVictoryCondition,
			scriptGlobal.TrigEscapeNWPantherEsg, scriptGlobal.VictoryTriggerNWPantherEsg, map_id::mapPanther, map_id::mapESG, evacuateArea, pantherNWCount);
	}

	void CheckSWCombatUnitVictoryConditions()
	{
		vehicleCounter.PullVehiclesFromRectangle(Player0, InRectEnumerator(fightStageArea));

		int lynxSWCount = 4;
		int pantherSWCount = 3;

		checkCombatUnitVictoryCondition(CreateSWLynxMicrowaveVictoryCondition,
			scriptGlobal.TrigEscapeSWLynxMicrowave, scriptGlobal.VictoryTriggerSWLynxMicrowave, map_id::mapLynx, map_id::mapMicrowave, fightStageArea, lynxSWCount);

		checkCombatUnitVictoryCondition(CreateSWLynxStickyfoamVictoryCondition,
			scriptGlobal.TrigEscapeSWLynxStickyfoam, scriptGlobal.VictoryTriggerSWLynxStickyfoam, map_id::mapLynx, map_id::mapStickyfoam, fightStageArea, lynxSWCount);

		checkCombatUnitVictoryCondition(CreateSWLynxRpgVictoryCondition,
			scriptGlobal.TrigEscapeSWLynxRpg, scriptGlobal.VictoryTriggerSWLynxRpg, map_id::mapLynx, map_id::mapRPG, fightStageArea, lynxSWCount);

		checkCombatUnitVictoryCondition(CreateSWLynxEmpVictoryCondition,
			scriptGlobal.TrigEscapeSWLynxEmp, scriptGlobal.VictoryTriggerSWLynxEmp, map_id::mapLynx, map_id::mapEMP, fightStageArea, lynxSWCount);

		checkCombatUnitVictoryCondition(CreateSWLynxEsgVictoryCondition,
			scriptGlobal.TrigEscapeSWLynxEsg, scriptGlobal.VictoryTriggerSWLynxEsg, map_id::mapLynx, map_id::mapESG, fightStageArea, lynxSWCount);

		checkCombatUnitVictoryCondition(CreateSWPantherMicrowaveVictoryCondition,
			scriptGlobal.TrigEscapeSWPantherMicrowave, scriptGlobal.VictoryTriggerSWPantherMicrowave, map_id::mapPanther, map_id::mapMicrowave, fightStageArea, pantherSWCount);

		checkCombatUnitVictoryCondition(CreateSWPantherStickyfoamVictoryCondition,
			scriptGlobal.TrigEscapeSWPantherStickyfoam, scriptGlobal.VictoryTriggerSWPantherStickyfoam, map_id::mapPanther, map_id::mapStickyfoam, fightStageArea, pantherSWCount);

		checkCombatUnitVictoryCondition(CreateSWPantherRpgVictoryCondition,
			scriptGlobal.TrigEscapeSWPantherRpg, scriptGlobal.VictoryTriggerSWPantherRpg, map_id::mapPanther, map_id::mapRPG, fightStageArea, pantherSWCount);

		checkCombatUnitVictoryCondition(CreateSWPantherEmpVictoryCondition,
			scriptGlobal.TrigEscapeSWPantherEmp, scriptGlobal.VictoryTriggerSWPantherEmp, map_id::mapPanther, map_id::mapEMP, fightStageArea, pantherSWCount);

		checkCombatUnitVictoryCondition(CreateSWPantherEsgVictoryCondition,
			scriptGlobal.TrigEscapeSWPantherEsg, scriptGlobal.VictoryTriggerSWPantherEsg, map_id::mapPanther, map_id::mapESG, fightStageArea, pantherSWCount);
	}

	void CheckCombatUnitVictoryConditions()
	{
		CheckNWCombatUnitVictoryConditions();
		CheckSWCombatUnitVictoryConditions();
	}
}