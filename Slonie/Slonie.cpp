// Slonie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdlib>

uint32_t constexpr MaxWeight = 6500;
uint32_t constexpr MinVertexes = 2;
uint32_t constexpr MaxVertexes = 1000000;

struct ObjectCollection
{
	size_t count = 0;
	std::vector<uint32_t> weights;
	std::vector<size_t> startingOrder;
	std::vector<size_t> endingOrder;
	uint32_t minWeight = MaxWeight;
};

std::size_t readValue(std::istringstream& iss)
{
	std::size_t value;
	iss >> value;
	if (!iss)
		throw std::runtime_error("Invalid input.");

	return value;
}

std::istringstream readLine(std::istream& stream)
{
	std::string line;
	std::getline(stream, line);
	if (line.empty()) throw std::runtime_error("Invalid input");
	return std::istringstream(line);
}

std::vector<size_t> readOrder(std::istringstream iss, size_t const objectCount)
{
	std::vector<size_t> v;
	v.reserve(objectCount);

	int i = 1;
	while (!iss.eof() && i <= objectCount)
	{
		size_t orderNumber = readValue(iss);
		if (orderNumber > objectCount)
		{
			throw std::runtime_error("Too high index in order");
		}
		v.push_back(orderNumber - 1);
		++i;
	}
	if (v.size() != objectCount) throw std::runtime_error("Too few values in line");
	return v;
}

void readWeightsAndSetMinWeight(std::istringstream iss, ObjectCollection& objects)
{
	objects.weights.reserve(objects.count);
	int i = 1;
	while (!iss.eof() && i <= objects.count)
	{
		uint32_t weight = static_cast<uint32_t>(readValue(iss));
		if (weight > MaxWeight)
		{
			throw std::runtime_error("Too high weight");
		}

		objects.weights.push_back(weight);
		objects.minWeight = std::min(objects.minWeight, weight);
		++i;
	}
	if (objects.weights.size() != objects.count)
		throw std::runtime_error("Too few values in line");
}


ObjectCollection readFromFile(std::istream& stream)
{
	ObjectCollection objects;

	if (!std::cin.good())
		throw std::exception("Unable to read values");

	readLine(stream) >> objects.count;
	if (objects.count<MinVertexes || objects.count>MaxVertexes)
	{
		throw std::exception("Invalid amount of vertexes");
	}

	readWeightsAndSetMinWeight(readLine(stream), objects);
	objects.startingOrder = readOrder(readLine(stream), objects.count);
	objects.endingOrder = readOrder(readLine(stream), objects.count);

	return objects;
}

uint64_t calculateLowestCostOfWork(ObjectCollection const& objects)
{
	size_t n = objects.count;
	std::vector<size_t> permutation(n);

	//constructing permutation
	for (size_t i = 0; i < n; ++i)
	{
		permutation[objects.endingOrder[i]] = objects.startingOrder[i];
	}

	uint64_t result = 0;
	std::vector<bool> visitedVertexes(n);

	for (int i = 0; i < n; ++i)
	{
		if (visitedVertexes[i])
			continue;

		size_t cycleSize = 0;
		uint32_t cycleMinWeight = MaxWeight;
		long long cycleSumOfWeights = 0;

		size_t vertexToVisit = i;
		//decomposition for simple cycles and calculating parameters for each cycle
		while (!visitedVertexes[vertexToVisit])
		{
			visitedVertexes[vertexToVisit] = true;
			cycleSize++;
			vertexToVisit = permutation[vertexToVisit];
			cycleSumOfWeights += objects.weights[vertexToVisit];
			cycleMinWeight = std::min(cycleMinWeight, objects.weights[vertexToVisit]);
		}
		//calculating lowest cost for each cycle
		uint64_t swappingWithMinWeightInCycle = cycleSumOfWeights + (static_cast<uint64_t>(cycleSize) - 2) * static_cast<uint64_t>(cycleMinWeight);
		uint64_t swappingWithMinWeight = cycleSumOfWeights + cycleMinWeight + (static_cast<uint64_t>(cycleSize) + 1) * static_cast<uint64_t>(objects.minWeight);
		result += std::min(swappingWithMinWeightInCycle, swappingWithMinWeight);
	}
	return result;
}

int main()
{
	ObjectCollection elephants;
	try
	{
		elephants = readFromFile(std::cin);
		std::cout << calculateLowestCostOfWork(elephants);
	}

	catch (std::exception const& ex)
	{
		std::cerr << "Error: " << ex.what() << "\n";
		return EXIT_FAILURE;
	}

	catch (...)
	{
		std::cerr << "Error unknown \n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}