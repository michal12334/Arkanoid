#include "mapGetter.h"
#include "map1.h"
#include "map2.h"
#include "map3.h"

Map *MapGetter::getMap(int number) {
	switch(number) {
	case 1: return new Map1();
	case 2: return new Map2();
	case 3: return new Map3();
	}
	return NULL;
}

int MapGetter::getNumberOfMaps() {
	return NUMBER_OF_MAPS;
}
