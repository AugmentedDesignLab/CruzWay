#pragma once
#include "calcForkingPoints.h"

calcForkingPoints::calcForkingPoints(UfileParser* param_intersection): intersection(param_intersection){

}

calcForkingPoints::~calcForkingPoints(){

}

int32 calcForkingPoints::calculateForkingPointsCount(splineCont* splineContainer) {
	for (const TPair<FString, SimpleSplinePtr>& pair : splineContainer->SplineMap) {
		int32 numberOfConnectedSplines = pair.Value->SplineActor->ConnectedSpline.Num();
		if (numberOfConnectedSplines >= 2) //Def. of forking point
			numberOfForkingPoints += 1;
	}
	return numberOfForkingPoints;
}




