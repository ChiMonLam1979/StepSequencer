#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new StepSequencerEngine();
}
