#include <iostream>
#include "model.h"
#include "renderer.h"

using namespace NOLOVR;
using namespace std;

int main()
{
	scmales::Model::ptr pModel(new scmales::Model());

	OpenNoloZeroMQ();
	cout << "Listen" << endl;

	scmales::NOLOEventHandler* NoloListener = new scmales::NOLOEventHandler();
	NoloListener->setModel(pModel);
	SetEventListener(NoloListener);

	const char* vFileName = "..\\shaders\\VertexShader.vert";
	const char* fFileName = "..\\shaders\\FragmentShader.frag";

	auto render = scmales::Renderer(); // init 
	scmales::Shaders::ptr pShaders(new scmales::Shaders(vFileName, fFileName)); //compile shaders
	render.setShaders(pShaders);  //set shaders
	render.setModel(pModel);
	render.run();	//renderer
}
