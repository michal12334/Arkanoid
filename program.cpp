#include "program.h"

float Program::getDeltaTime() {
	return 1.0 / Program::frameRateLimit;
}
