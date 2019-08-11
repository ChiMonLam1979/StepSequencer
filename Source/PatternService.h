#pragma once
#include "Pattern.h"
#include "NoteHandler.h"
#include "NoteLengthHandler.h"
#include "VelocityHandler.h"
#include "StepHandler.h"

class PatternService
{
public:

	PatternService
	(
		Pattern& pattern,
		NoteHandler& noteHandler,
		NoteLengthHandler& noteLengthHandler,
		VelocityHandler& velocityHandler,
		StepHandler& stepHandler
	);

	~PatternService();

	Pattern GetPattern();

private:

	Pattern&			pattern;
	NoteHandler&		noteHandler;
	NoteLengthHandler&	noteLengthHandler;
	VelocityHandler&	velocityHandler;
	StepHandler&		stepHandler;
};
