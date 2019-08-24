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
		IncDecButtons,
		MasterIncDecButtons,
		IncButton,
		DecButton,
		MasterIncButton,
		MasterDecButton
	};

	enum MouseEventType
	{
		MouseUp,
		MouseDown,
		MouseDrag,
		MouseWheelMove
	};
}