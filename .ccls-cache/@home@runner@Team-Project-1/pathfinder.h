#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include "stack.h"
#include <cmath>
#include <unordered_map>
#include "city.h"
#include "system_data.h"

#pragma once
//Holds the pm level and index of city
typedef std::pair<long double, int> pii;
class PathFinder
{
public:
	long double toRadians(long double);
	long double calculateDistance(coord, coord);
	void dijkstra(int, long double);
	void printShortestPath(int);

	void CreatePaths();

	PathFinder();

private:
	// Why not just use an array?
	// std::unordered_map<std::string,int> roster2;
	std::vector<pii> adjList[101];
	long double dist[101];
	int pre[101];
};