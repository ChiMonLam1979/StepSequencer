#include "ParametersFactory.h"
#include "ParameterNames.h"
#include "ParameterIds.h"
#include "DefaulValues.h"
#include "ParameterChoices.h"

ParametersFactory::ParametersFactory()
{
}

ParametersFactory::~ParametersFactory()
{
}

std::vector<std::unique_ptr<RangedAudioParameter>> ParametersFactory::CreateParameters()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> parameters;

	for (auto i = 0; i < 16; i++)
	{
		auto stepEncoderParameter = std::make_unique<AudioParameterInt>(IDs::PitchEncoderIDs[i], ParameterNames::PitchEncoderNames[i], 0, 127, DefaultValues::Pitch);

		parameters.push_back(std::move(stepEncoderParameter));

		auto stepButtonParameter = std::make_unique<AudioParameterBool>(IDs::StepButtonIDs[i], ParameterNames::StepButtonNames[i], DefaultValues::Gate);

		parameters.push_back(std::move(stepButtonParameter));

		auto noteLengthEncoderParameter = std::make_unique<AudioParameterInt>(IDs::NoteLengthEncoderIDs[i], ParameterNames::NoteLengthEncoderNames[i], 0, 127, DefaultValues::NoteLengthValue);

		parameters.push_back(std::move(noteLengthEncoderParameter));

		auto velocityEncoderParameter = std::make_unique<AudioParameterInt>(IDs::VelocityEncoderIDs[i], ParameterNames::VelocityEncoderNames[i], 0, 127, DefaultValues::Velocity);

		parameters.push_back(std::move(velocityEncoderParameter));

		auto selectedEncodersParameter = std::make_unique<AudioParameterBool>(IDs::SelectedEncoderIDs[i], ParameterNames::SelectedEncoderNames[i], DefaultValues::EncoderSelectState);

		parameters.push_back(std::move(selectedEncodersParameter));

		auto incButtonParameter = std::make_unique<AudioParameterBool>(IDs::IncDecButtonsIDs[(i * 2) + 1], ParameterNames::IncDecButtonsNames[(i * 2) + 1], false);

		parameters.push_back(std::move(incButtonParameter));

		auto decButtonParameter = std::make_unique<AudioParameterBool>(IDs::IncDecButtonsIDs[(i * 2)], ParameterNames::IncDecButtonsNames[(i * 2)], false);

		parameters.push_back(std::move(decButtonParameter));
	}

	auto masterIncButtonParameter = std::make_unique<AudioParameterBool>(IDs::MasterIncButtonID, ParameterNames::MasterIncButtonName, false);

	parameters.push_back(std::move(masterIncButtonParameter));

	auto masterDecButtonParameter = std::make_unique<AudioParameterBool>(IDs::MasterDecButtonID, ParameterNames::MasterDecButtonName, false);

	parameters.push_back(std::move(masterDecButtonParameter));

	auto stepChoicesParameter = std::make_unique<AudioParameterChoice>(IDs::StepChoicesID, ParameterNames::StepChoicesName, ParameterChoices::StepChoices, 0);

	parameters.push_back(std::move(stepChoicesParameter));

	auto encodersSelectorParameter = std::make_unique<AudioParameterBool>(IDs::EncodersSelectID, ParameterNames::EncodersSelectName, DefaultValues::EncoderSelectState);

	parameters.push_back(std::move(encodersSelectorParameter));

	auto groupEncoderParameter = std::make_unique<AudioParameterInt>(IDs::GroupEncoderId, ParameterNames::GroupEncoderName, 0, 127, 0);

	parameters.push_back(std::move(groupEncoderParameter));

	auto selectAllButtonParamter = std::make_unique<AudioParameterBool>(IDs::SelectAllButtonID, ParameterNames::SelectAllButtonName, false);

	parameters.push_back(std::move(selectAllButtonParamter));

	return parameters;
}