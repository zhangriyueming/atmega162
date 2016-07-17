#ifndef stepmotor_h
#define stepmotor_h

static const byte clockwises[] = {0x3, 0x9, 0xc, 0x6};
static const byte anticlocks[] = {0x3, 0x6, 0xc, 0x9};

class StepMotor
{
public:
	void pin_hex(byte hex)
	{
		for (int i = 0; i < 4; ++i)
			pin(i, hex & (1 << i));
	}
	
	byte pin_hex()
	{
		byte hex = 0;
		for (int i = 0; i < 4; ++i)
			hex |= pin(i) << i;
		return hex;
	}

	void pin(int id, bool val, bool output = true)
	{
		chip.pd(4 + id, val, output);
	}

	byte pin(int id)
	{
		return chip.pd(4 + id);
	}

	void step(int count, int us, bool clockwise = true)
	{
		for (int i = 0; i < count; ++i)
		{
			pin_hex(0x0);
			pin_hex(clockwise ? clockwises[i % 4] : anticlocks[i % 4]);
//			_delay_us(1500);
//			_delay_ms(2);
			delay_us(us);
		}
	}
};

#endif
