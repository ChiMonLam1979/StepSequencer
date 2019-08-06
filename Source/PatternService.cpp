#include "PatternService.h"

PatternService::PatternService
(
	Pattern& pattern,
	NoteHandler& noteHandler,
	NoteLengthHandler& noteLengthHandler,
	VelocityHandler& velocityHandler
):
	pattern(pattern),
	noteHandler(noteHandler),
	noteLengthHandler(noteLengthHandler),
	velocityHandler(velocityHandler)
{
	noteHandler.notes				= pattern.notes;
	noteLengthHandler.noteLengths	= pattern.noteLengths;
	velocityHandler.velocities		= pattern.velocities;
}

PatternService::~PatternService()
{
	
}