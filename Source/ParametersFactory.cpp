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

std::vector<std::unique_ptr<RangedAudioParameter>> ParametersFactory::CreateParameters(int numberOfSteps)
{
	std::vector<std::unique_ptr<RangedAudioParameter>> parameters;

	for (auto i = 0; i < numberOfSteps; i++)
	{
		auto number = String(i);

		auto stepEncoderParameter = std::make_unique<AudioParameterInt>(IDs::PitchEncoderID + number, ParameterNames::PitchEncoderName + number, 0, 127, DefaultValues::Pitch);

		parameters.push_back(std::move(stepEncoderParameter));

		auto stepButtonParameter = std::make_unique<AudioParameterBool>(IDs::StepButtonID + number, ParameterNames::StepButtonName + number, DefaultValues::Gate);

		parameters.push_back(std::move(stepButtonParameter));

		auto noteLengthEncoderParameter = std::make_unique<AudioParameterInt>(IDs::NoteLengthEncoderID + number, ParameterNames::NoteLengthEncoderName + number, 0, 127, DefaultValues::NoteLengthValue);

		parameters.push_back(std::move(noteLengthEncoderParameter));

		auto velocityEncoderParameter = std::make_unique<AudioParameterInt>(IDs::VelocityEncoderID + number, ParameterNames::VelocityEncoderName + number, 0, 127, DefaultValues::Velocity);

		parameters.push_back(std::move(velocityEncoderParameter));

		auto selectedEncodersParameter = std::make_unique<AudioParameterBool>(IDs::SelectedEncoderID + number, ParameterNames::SelectedEncoderName + number, DefaultValues::EncoderSelectState);

		parameters.push_back(std::move(selectedEncodersParameter));

		auto incButtonParameter = std::make_unique<AudioParameterBool>(IDs::IncButtonID + number, ParameterNames::IncButtonName + number, false);

		parameters.push_back(std::move(incButtonParameter));

		auto decButtonParameter = std::make_unique<AudioParameterBool>(IDs::DecButtonID + number, ParameterNames::DecButtonName + number, false);

		parameters.push_back(std::move(decButtonParameter));
	}

	auto masterIncButtonParameter = std::make_unique<AudioParameterBool>(IDs::MasterIncButtonID + "1", ParameterNames::MasterIncButtonName, false);

	parameters.push_back(std::move(masterIncButtonParameter));

	auto masterDecButtonParameter = std::make_unique<AudioParameterBool>(IDs::MasterDecButtonID + "0", ParameterNames::MasterDecButtonName, false);

	parameters.push_back(std::move(masterDecButtonParameter));

	auto stepChoicesParameter = std::make_unique<AudioParameterChoice>(IDs::StepChoicesID, ParameterNames::StepChoicesName, ParameterChoices::StepChoices, 0);

	parameters.push_back(std::move(stepChoicesParameter));

	auto encodersSelectorParameter = std::make_unique<AudioParameterBool>(IDs::EncodersSelectID, ParameterNames::EncodersSelectName, DefaultValues::EncoderSelectState);

	parameters.push_back(std::move(encodersSelectorParameter));

	auto groupEncoderParameter = std::make_unique<AudioParameterInt>(IDs::GroupEncoderId, ParameterNames::MasterEncoderName, 0, 127, 0);

	parameters.push_back(std::move(groupEncoderParameter));

	auto selectAllButtonParamter = std::make_unique<AudioParameterBool>(IDs::SelectAllButtonID, ParameterNames::SelectAllButtonName, false);

	parameters.push_back(std::move(selectAllButtonParamter));

	return parameters;
}