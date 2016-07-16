

#include "OpenGLExampleBrowser.h"

#include "Bullet3Common/b3CommandLineArgs.h"
#include "../Utils/b3Clock.h"

#include "ExampleEntries.h"
#include "Bullet3Common/b3Logging.h"

#include "../Importers/ImportObjDemo/ImportObjExample.h"
#include "../Importers/ImportBsp/ImportBspExample.h"
#include "../Importers/ImportColladaDemo/ImportColladaSetup.h"
#include "../Importers/ImportSTLDemo/ImportSTLSetup.h"
#include "../Importers/ImportURDFDemo/ImportURDFSetup.h"
#include "../Importers/ImportSDFDemo/ImportSDFSetup.h"
#include "../Importers/ImportSTLDemo/ImportSTLSetup.h"



int main(int argc, char* argv[])
{
	{
		b3CommandLineArgs args(argc, argv);
		b3Clock clock;


		ExampleEntriesAll examples;
		examples.initExampleEntries();

		OpenGLExampleBrowser* exampleBrowser = new OpenGLExampleBrowser(&examples);
		bool init = exampleBrowser->init(argc, argv);
		exampleBrowser->registerFileImporter(".urdf", ImportURDFCreateFunc);
		exampleBrowser->registerFileImporter(".sdf", ImportSDFCreateFunc);
		exampleBrowser->registerFileImporter(".obj", ImportObjCreateFunc);
		exampleBrowser->registerFileImporter(".stl", ImportSTLCreateFunc);

		clock.reset();
		if (init)
		{
			do
			{
				float deltaTimeInSeconds = clock.getTimeMicroseconds() / 1000000.f;
				clock.reset();
				exampleBrowser->update(deltaTimeInSeconds);

			} while (!exampleBrowser->requestedExit());
		}
		delete exampleBrowser;

	}
	return 0;
}
