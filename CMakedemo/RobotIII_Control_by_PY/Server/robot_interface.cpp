﻿#include "robot_interface.h"

int ROBOT_STATE_MACHINE::stateMachine[ROBOT_CMD_COUNT][ROBOT_STATE_COUNT]={-1};

/*
enum ROBOT_STATE
{
	DISABLED,
	ENABLED,
	ENABLED1_HOMED2,
	ENABLED1_STARTED2,
	HOMED1_ENABLED2,
	HOMED1_STARTED2,
	STARTED1_ENABLED2,
	STARTED1_HOMED2,
	STARTED,

	ROBOT_STATE_COUNT
};

enum ROBOT_CMD
{
	ENABLE,
	DISABLE,
	HOME_1,
	HOME_2,
	HOME2START_1,
	HOME2START_2,
	MV_FORWARD,
	MV_BACKWARD,
	TURN_LEFT,
	TURN_RIGHT,

	ROBOT_CMD_COUNT
};*/

ROBOT_STATE_MACHINE::ROBOT_STATE_MACHINE()
{
	ROBOT_STATE_MACHINE::stateMachine[DISABLED][ENABLE]=ENABLED;

	ROBOT_STATE_MACHINE::stateMachine[ENABLED][DISABLE]=DISABLED;
	ROBOT_STATE_MACHINE::stateMachine[ENABLED][HOME_1]=HOMED1_ENABLED2;
	ROBOT_STATE_MACHINE::stateMachine[ENABLED][HOME_2]=ENABLED1_HOMED2;

	ROBOT_STATE_MACHINE::stateMachine[ENABLED1_HOMED2][HOME2START_2]=ENABLED1_STARTED2;

	ROBOT_STATE_MACHINE::stateMachine[ENABLED1_STARTED2][HOME_1]=HOMED1_STARTED2;

	ROBOT_STATE_MACHINE::stateMachine[HOMED1_ENABLED2][HOME2START_1]=STARTED1_ENABLED2;

	ROBOT_STATE_MACHINE::stateMachine[HOMED1_STARTED2][HOME2START_1]=STARTED;

	ROBOT_STATE_MACHINE::stateMachine[STARTED1_ENABLED2][HOME_2]=STARTED1_HOMED2;

	ROBOT_STATE_MACHINE::stateMachine[STARTED1_HOMED2][HOME2START_2]=STARTED;

}




Aris::Core::CONN control_interface;
Aris::Core::CONN visual_interface;
Aris::Core::CONN data_interface;
