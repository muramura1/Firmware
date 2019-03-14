#pragma once

#include "navigator_mode.h"
#include "mission_block.h"
#include <uORB/topics/charging_station_state.h>

class ChargingStation : public MissionBlock
{
public:
	ChargingStation(Navigator *navigator);
	~ChargingStation() override = default;

	void on_activation() override;
	void on_active() override;
	bool is_mission_item_reached();
	void set_params(int id, int action);

private:
	bool in_flight();
	void idle();
	int _charging_station_state_sub{-1};
	int _cmd_ack_sub{-1};
	int _action;
	int _id;
	bool _sent{false};
	bool _complete{false};
	bool _heartbeat_received;
	hrt_abstime _start_time;
};
