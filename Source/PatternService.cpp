#include "PatternService.h"

PatternService::PatternService
(
	Pattern& pattern,
	NoteHandler& noteHandler,
	NoteLengthHandler& noteLengthHandler,
	VelocityHandler& velocityHandler,
	StepHandler& stephandler
):
	pattern(pattern),
	noteHandler(noteHandler),
	noteLengthHandler(noteLengthHandler),
	velocityHandler(velocityHandler),
	stepHandler(stephandler)
{
	noteHandler.notes				= pattern.notes;
	noteLengthHandler.noteLengths	= pattern.noteLengths;
	velocityHandler.velocities		= pattern.velocities;
	stephandler.gates				= pattern.gates;
}

PatternService::~PatternService()
{
	
}

Pattern PatternService::GetPattern()
{
	return pattern;
}