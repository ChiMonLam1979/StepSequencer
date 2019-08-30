#pragma once
#include "Pattern.h"
#include "NoteHandler.h"
#include "NoteLengthHandler.h"
#include "VelocityHandler.h"
#include "GateHandler.h"


class PatternService
{
public:

	PatternService
	(
		Pattern& pattern,
		NoteHandler& noteHandler,
		NoteLengthHandler& noteLengthHandler,
		VelocityHandler& velocityHandler,
		GateHandler& gateHandler
	);

	~PatternService();

	Pattern GetPattern();

private:

	Pattern&			pattern;
	NoteHandler&		noteHandler;
	NoteLengthHandler&	noteLengthHandler;
	VelocityHandler&	velocityHandler;
	GateHandler&		gateHandler;
};
