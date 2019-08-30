#include "PatternService.h"

PatternService::PatternService
(
	Pattern& pattern,
	NoteHandler& noteHandler,
	NoteLengthHandler& noteLengthHandler,
	VelocityHandler& velocityHandler,
	GateHandler& gatehandler
):
	pattern(pattern),
	noteHandler(noteHandler),
	noteLengthHandler(noteLengthHandler),
	velocityHandler(velocityHandler),
	gateHandler(gatehandler)
{
	noteHandler.notes				= pattern.notes;
	noteLengthHandler.noteLengths	= pattern.noteLengths;
	velocityHandler.velocities		= pattern.velocities;
	gatehandler.gates				= pattern.gates;
}

PatternService::~PatternService()
{
	
}

Pattern PatternService::GetPattern()
{
	return pattern;
}