#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class Surround : public Plugin
{
public:
	Surround() : Plugin(0, 0, 0)
	{
	}

	~Surround() override
	{
	}

protected:
	const char* getLabel() const override
	{
		return "Surround";
	}

	const char* getDescription() const override
	{
		return "Surround effect";
	}

	const char* getMaker() const override
	{
		return "vanheusden.com";
	}

	const char* getHomePage() const override
	{
		return "https://vanheusden.com/disthro/surround";
	}

	const char* getLicense() const override
	{
		return "Apache License v2.0";
	}

	uint32_t getVersion() const override
	{
		return d_version(1, 0, 0);
	}

	int64_t getUniqueId() const override
	{
		return d_cconst('F', 'v', 'H', '3');
	}

	void initAudioPort(bool input, uint32_t index, AudioPort& port) override
	{
		if (input) {
			switch (index) {
				case 0:
					port.name    = "left in";
					port.symbol  = "in_left";
					return;
				case 1:
					port.name    = "right in";
					port.symbol  = "in_right";
					return;
				case 2:
					port.name    = "center in";
					port.symbol  = "in_center";
					return;
				case 3:
					port.name    = "back in";
					port.symbol  = "in_back";
					return;
			}
		}
		else {
			switch (index) {
				case 0:
					port.name    = "left out";
					port.symbol  = "out_left";
					return;
				case 1:
					port.name    = "right out";
					port.symbol  = "out_right";
					return;
			}
		}

		Plugin::initAudioPort(input, index, port);
	}

	void initParameter(uint32_t index, Parameter& parameter) override
	{
	}

	float getParameterValue(uint32_t index) const override
	{
		return 0.0f;
	}

	void setParameterValue(uint32_t index, float value) override
	{
	}

	void run(const float **inputs, float **outputs, uint32_t frames) override
	{
		for(uint32_t i=0; i<frames; i++) {
			float left = inputs[0][i];
			float right = inputs[1][i];
			float center = inputs[2][i];
			float back = inputs[3][i];

			// TODO: apply filtering etc to 'back'
			outputs[0][i] = left + center + back;
			outputs[1][i] = right + center - back;
		}
	}

	void sampleRateChanged(double newSampleRate) override
	{
	}

private:
	DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Surround)
};


Plugin* createPlugin()
{
	return new Surround();
}

END_NAMESPACE_DISTRHO
