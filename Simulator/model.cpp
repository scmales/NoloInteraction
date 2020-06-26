#include "model.h"
#include "renderer.h"

using namespace NOLOVR;

namespace scmales {
	const vector<string> NoloDeviceType = { "eHmd","eLeftController","eRightController" , "eBaseStation" };
	string getElemTypeName(ENoloDeviceType type)
	{
		int idx = static_cast<int>(type);
		return NoloDeviceType[idx];
	}

	void NOLOEventHandler::OnZMQConnected()
	{
		cout << "connected!" << endl;
	};

	void NOLOEventHandler::OnZMQDisConnected()
	{
		cout << "disconnected!" << endl;
	};

	void NOLOEventHandler::OnKeyDoubleClicked(ENoloDeviceType DevType, UCHAR Keys) 
	{
		cout << "Double Clicked" << getElemTypeName(DevType) << " " << Keys << endl;
	};

	void NOLOEventHandler::OnButtonPressed(ENoloDeviceType device, EControlerButtonType type) 
	{
		cout << "Press" << getElemTypeName(device) << " " << type << endl;
	};

	void NOLOEventHandler::OnButtonRelease(ENoloDeviceType device, EControlerButtonType type)
	{
		cout << "Release" << getElemTypeName(device) << " " << type << endl;
	};

	void NOLOEventHandler::OnNewData(const NOLOData& _noloData) 
	{
		// ��ȡ���ֱ���λ�ú���ת��
		Controller lController = _noloData.leftData;
		m_model->lPosition = lController.Position;
		m_model->lRotation = lController.Rotation;

		// ��ȡ���ֱ���λ�ú���ת��
		auto rController = _noloData.rightData;
		m_model->rPosition = rController.Position;
		m_model->rRotation = rController.Rotation;

		// ��ȡhmd��λ�ú���ת��
		HMD hmd = _noloData.hmdData;
		m_model->hmdPosition = hmd.HMDPosition;
		m_model->hmdRotation = hmd.HMDRotation;

		// std::cout << m_model->hmdPosition.x << " " << m_model->hmdPosition.y << " " << m_model->hmdPosition.z << std::endl;
		//std::cout << m_model->lPosition.x << " " << m_model->lPosition.y << " " << m_model->lPosition.z << std::endl;
	};

	void NOLOEventHandler::OnNoloDevNeedUpdate(int Versions) 
	{
		cout << "Nolo Version: " << Versions << " " << endl;
	};
	
}