#pragma once

namespace Enums
{
	enum StepButtonStyle
	{
		Red,
		Green,
		Amber,
		AmberSelect
	};

	enum LEDState
	{
		LEDOff,
		LEDGreen,
		LEDRed
	};

	enum StepButtonType
	{
		NotInUse,
		GateButton,
		RadioButton,
		EncoderSelectorButton,
		ToggleButton,
		IncButton,
		DecButton,
		MasterIncButton,
		MasterDecButton,
		SelectAllToggleButton,
		PatternLengthIncButton,
		PatternLengthDecButton
	};

	enum MouseEventType
	{
		MouseUp,
		MouseDown,
		MouseDrag,
		MouseWheelMove
	};
}