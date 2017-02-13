#ifndef BASE_S_MODEL_H
#define BASE_S_MODEL_H

#include <robotiq_s_model_control/SModel_robot_input.h>
#include <robotiq_s_model_control/SModel_robot_output.h>
#include <robotiq_s_model_control/s_model_ethercat_client.h>

namespace robotiq_s_model_control
{


class Base_S_Model{
private:
	// vector<uint_8> output_message(19);
	GripperOutput output_message;
	SModelEtherCatClient* client;
public:
	Base_S_Model(SModelEtherCatClient* _client);

	void verify_command(GripperOutput& command);

	void send_command(GripperOutput& command);

	GripperInput get_status();
};

}