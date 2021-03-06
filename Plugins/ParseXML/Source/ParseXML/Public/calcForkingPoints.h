#pragma once
#include "fileParser.h"
#include <nlohmann/json.hpp>

class calcForkingPoints {
public:
	calcForkingPoints(UfileParser*);
	virtual ~calcForkingPoints();

	UfileParser* intersection;
	int32 calculateForkingPointsCount(splineCont*);
	int32 numberOfForkingPoints = 0;
};
