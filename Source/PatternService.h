#pragma once
#include "Pattern.h"
#include "NoteHandler.h"
#include "NoteLengthHandler.h"
#include "VelocityHandler.h"

class PatternService
{
public:

	PatternService
	(
		Pattern& pattern,
		NoteHandler& noteHandler,
		NoteLengthHandler& noteLengthHandler,
		VelocityHandler& velocityHandler
	);

	~PatternService();

private:

	Pattern&			pattern;
	NoteHandler&		noteHandler;
	NoteLengthHandler&	noteLengthHandler;
	VelocityHandler&	velocityHandler;
};
