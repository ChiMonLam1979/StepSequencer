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
		EncoderGroupSelectorButton,
		ToggleButton,
		IncButton,
		DecButton,
		MasterIncButton,
		MasterDecButton,
		SelectAllToggleButton
	};

	enum MouseEventType
	{
		MouseUp,
		MouseDown,
		MouseDrag,
		MouseWheelMove
	};
}