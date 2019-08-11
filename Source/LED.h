#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Enums.h"

class LED : public Component
{
public:

	LED();
	~LED();

	void paint(Graphics& g) override;

	void setState(Enums::LEDState state);

	Image led{};

private:

};