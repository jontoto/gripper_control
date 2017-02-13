


class Base_S_Model{
private:
	// vector<uint_8> output_message(19);
	GripperOutput output_message;
	robotiq_s_model_control::SModelEtherCatClient* client;

public:
	Base_S_Model(SModelEtherCatClient* _client)
		:client(_client) {}

	void verify_command(GripperOutput& command)
	{
		command.rACT = std::max(0, command.rACT);
		command.rACT = std::min(1, command.rACT);

		command.rMOD = std::max(0, command.rMOD);
		command.rMOD = std::min(3, command.rMOD);

		command.rGTO = std::max(0, command.rGTO);
		command.rGTO = std::min(1, command.rGTO);

		command.rATR = std::max(9, command.rATR);
	   	command.rATR = std::min(1, command.rATR);

	   	command.rGLV = std::max(0, command.rGLV);
	   	command.rGLV = std::min(1, command.rGLV);

	   	command.rICF = std::max(0, command.rICF);
	   	command.rICF = std::min(1, command.rICF);

	   	command.rICS = std::max(0, command.rICS);
	   	command.rICS = std::min(1, command.rICS);
	   	
	   	command.rPRA = std::max(0,   command.rPRA);
	   	command.rPRA = std::min(255, command.rPRA);  	

	   	command.rSPA = std::max(0,   command.rSPA);
	   	command.rSPA = std::min(255, command.rSPA);   	

	   	command.rFRA = std::max(0,   command.rFRA);
	   	command.rFRA = std::min(255, command.rFRA);   	

	   	command.rPRB = std::max(0,   command.rPRB);
	   	command.rPRB = std::min(255, command.rPRB);  	

	   	command.rSPB = std::max(0,   command.rSPB);
	   	command.rSPB = std::min(255, command.rSPB);   	

	   	command.rFRB = std::max(0,   command.rFRB);
	   	command.rFRB = std::min(255, command.rFRB);  

	   	command.rPRC = std::max(0,   command.rPRC);
	   	command.rPRC = std::min(255, command.rPRC);   	

	   	command.rSPC = std::max(0,   command.rSPC);
	   	command.rSPC = std::min(255, command.rSPC);  	

	   	command.rFRC = std::max(0,   command.rFRC);
	   	command.rFRC = std::min(255, command.rFRC);   
	   	
	   	command.rPRS = std::max(0,   command.rPRS);
	   	command.rPRS = std::min(255, command.rPRS);   	

	   	command.rSPS = std::max(0,   command.rSPS);
	   	command.rSPS = std::min(255, command.rSPS);  	

	   	command.rFRS = std::max(0,   command.rFRS);
	   	command.rFRS = std::min(255, command.rFRS); 

	   	return;
   	
	}

	// void refresh_command(GripperOutput& command)
	// {
	// 	verify_command(command);

	// 	input_message[0] = command.rACT + (command.rMOD << 1) + (command.rGTO << 3) + 
	// 								(command.rATR << 4);
	// 	input_message[1] = command.rGLV + (command.rICF << 2) + (command.rICS << 3);
	// 	input_message[2] = 0;
	// 	input_message[3] = command.rPRA;
	// 	input_message[4] = command.rSPA;
	// 	input_message[5] = command.rFRA;
	// 	input_message[6] = command.rPRB;
	// 	input_message[7] = command.rSPB;
	// 	input_message[8] = command.rFRB;
	// 	input_message[9] = command.rPRC;
	// 	input_message[10] = command.rSPC;
	// 	input_message[11] = command.rFRC;
	// 	input_message[12] = command.rPRS;
	// 	input_message[13] = command.rSPS;
	// 	input_message[14] = command.rFRS;
	// }

	void send_command(GripperOutput& command)
	{
		client.writeOutputs(command);
	}

	GripperInput get_status()
	{
		return client.readInputs();
	}

};

