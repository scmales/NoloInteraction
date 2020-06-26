#ifndef __MODEL_H__
#define __MODEL_H__
#include "Nolo_Math.h"
#include "Nolo_DeviceType.h"
#include "NoloClientLib.h"
#include <memory>
using namespace NOLOVR;

namespace scmales {
	class Model {
	public:
		typedef shared_ptr<Model> ptr;

		NVector3 lPosition;
		NQuaternion lRotation;
		NVector3 rPosition;
		NQuaternion rRotation;
		NVector3 hmdPosition;
		NQuaternion hmdRotation;
	};


	class NOLOEventHandler :public INOLOZMQEvent
	{
	public:
		// NOLOEventHandler(Model::ptr model) :m_model(model) {};

		void OnZMQConnected();

		void OnZMQDisConnected();

		void OnKeyDoubleClicked(ENoloDeviceType DevType, UCHAR Keys) override;

		void OnButtonPressed(ENoloDeviceType device, EControlerButtonType type) override;

		void OnButtonRelease(ENoloDeviceType device, EControlerButtonType type)override;

		void OnNewData(const NOLOData& _noloData) override;

		void OnNoloDevNeedUpdate(int Versions) override;

		void setModel(Model::ptr model) { m_model = model; };
		Model::ptr getModel() { return m_model; };
	private:
		Model::ptr m_model = nullptr;
	};

}
#endif // !__MODEL_H__
