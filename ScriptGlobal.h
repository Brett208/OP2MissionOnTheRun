#pragma once

#include "Outpost2DLL\Outpost2DLL.h"

struct ScriptGlobal
{
	Trigger TrigUnitsCured;

	int StartingUnitCount = 29;
	Unit StartingUnits [29];
	bool StartingUnitCured [29];

	Trigger VictoryTriggerNWLynxMicrowave;
	Trigger VictoryTriggerNWLynxStickyfoam;
	Trigger VictoryTriggerNWLynxRpg;
	Trigger VictoryTriggerNWLynxEmp;
	Trigger VictoryTriggerNWLynxEsg;

	Trigger VictoryTriggerNWPantherMicrowave;
	Trigger VictoryTriggerNWPantherStickyfoam;
	Trigger VictoryTriggerNWPantherRpg;
	Trigger VictoryTriggerNWPantherEmp;
	Trigger VictoryTriggerNWPantherEsg;

	Trigger VictoryTriggerSWLynxMicrowave;
	Trigger VictoryTriggerSWLynxStickyfoam;
	Trigger VictoryTriggerSWLynxRpg;
	Trigger VictoryTriggerSWLynxEmp;
	Trigger VictoryTriggerSWLynxEsg;
	
	Trigger VictoryTriggerSWPantherMicrowave;
	Trigger VictoryTriggerSWPantherStickyfoam;
	Trigger VictoryTriggerSWPantherRpg;
	Trigger VictoryTriggerSWPantherEmp;
	Trigger VictoryTriggerSWPantherEsg;

	Trigger TrigVictoryColonists;
	Trigger TrigGarageBuilt;

	Trigger TrigEscapeRoboDozer;
	Trigger TrigEscapeRoboMiner;
	Trigger TrigEscapeEvacTransports;
	Trigger TrigEscapeRoboSurveyors;
	Trigger TrigEscapeEarthworker;
	Trigger TrigEscapeCCKit;
	Trigger TrigEscapeStructFactoryKit;
	Trigger TrigEscapeCommonSmelterKit;
	Trigger TrigEscapeTokomakKit;
	Trigger TrigEscapeAgridomeKit;
	Trigger TrigEscapeRareStorageKit;
	Trigger TrigEscapeCommonMetals;
	Trigger TrigEscapeRareMetals;
	Trigger TrigEscapeFood;

	Trigger TrigEscapeNWLynxMicrowave;
	Trigger TrigEscapeNWLynxRpg;
	Trigger TrigEscapeNWLynxEmp;
	Trigger TrigEscapeNWLynxEsg;
	Trigger TrigEscapeNWLynxStickyfoam;

	Trigger TrigEscapeNWPantherMicrowave;
	Trigger TrigEscapeNWPantherRpg;
	Trigger TrigEscapeNWPantherEmp;
	Trigger TrigEscapeNWPantherEsg;
	Trigger TrigEscapeNWPantherStickyfoam;

	Trigger TrigEscapeSWScouts;
	Trigger TrigEscapeSWSpiders;

	Trigger TrigEscapeSWLynxMicrowave;
	Trigger TrigEscapeSWLynxRpg;
	Trigger TrigEscapeSWLynxEmp;
	Trigger TrigEscapeSWLynxEsg;
	Trigger TrigEscapeSWLynxStickyfoam;

	Trigger TrigEscapeSWPantherMicrowave;
	Trigger TrigEscapeSWPantherRpg;
	Trigger TrigEscapeSWPantherEmp;
	Trigger TrigEscapeSWPantherEsg;
	Trigger TrigEscapeSWPantherStickyfoam;

	Trigger TrigTimeResearch2706;
	Trigger TrigTimeResearch2707;
	Trigger TrigTimeResearch7102;
	Trigger TrigTimeResearch8203;
	Trigger TrigTimeResearch8306;
	Trigger TrigTimeResearch8309;
	Trigger TrigTimeResearch10303;
	Trigger TrigTimeResearch8320;
	Trigger TrigTimeResearch7212;
	Trigger TrigTimeResearch10306;

	Trigger TrigFailureWaitTime;

	Trigger TrigBaseEstablished;

	Trigger TrigDisaster;

	Trigger TrigScoutGroup;
	Trigger TrigMainTankGroup;

	FightGroup ScoutFightGroup;
	FightGroup MainFightGroup1;
	FightGroup MainFightGroup2;

	bool BaseEstablished;
};

// Global instance of ScriptGlobal
extern ScriptGlobal scriptGlobal;