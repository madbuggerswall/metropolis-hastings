#include <iostream>
#include <random>
#include <string>

int main(int argc, char const* argv[]) {
	const int nrolls = 80000; // number of experiments
	const int nstars = 400;	 // maximum number of stars to distribute

	std::default_random_engine generator;
	// distribution(mean, standard_deviation)
	std::normal_distribution<double> distribution(10.0, 4.0);
	double randomNumber = distribution(generator);

	int p[20] = {};

	for (int i = 0; i < nrolls; ++i) {
		double number = distribution(generator);
		if ((number >= 0.0) && (number < 20.0)) ++p[int(number)];
	}

	std::cout << "normal_distribution (10.0,6.0):" << std::endl;

	for (int i = 0; i < 20; ++i) {
		std::cout << i << "-" << (i + 1) << ":\t";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}
	/* code */
	return 0;
}
