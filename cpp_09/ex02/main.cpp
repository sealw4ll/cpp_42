#include "PMergeMe.hpp"

bool	isNumber(string arv)
{
	if (arv.find_first_not_of("0123456789") == string::npos)
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv)
{
	if (argc == 1){
		cout << "Error: provide list of numbers as seperate arguements" << endl;
		exit (1);
	}
	if (argc == 2){
		cout << "Error: only 1 number" << endl;
		exit (1);
	}

	string	arv;
	vector<int>	ori;	//original order of numbers passed into the program;;

	for	(int i = 1; i < argc; i++){
		arv = argv[i];
		if (isNumber(arv) == true)
			ori.push_back(std::stoi(arv));
		else{
			cout << "Error: invalid arguments" << endl;
			exit (1);
		}
	}

	PMergeMe merge;
	merge.insertVec(ori);
	merge.insertList(ori);

	cout << "before: ";
	merge.printVec();
	cout << endl;

	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long startSec = tv.tv_sec;
	unsigned long startMicro = tv.tv_usec;

	merge.sortVec();

	gettimeofday(&tv, NULL);
	float endSec = tv.tv_sec;
	float endMicro = tv.tv_usec;
	float time = float(endSec - startSec) + (float)((endMicro - startMicro) / 10000);
	cout << "after: ";
	merge.printVec();
	cout << endl;
	cout << "Time to process a range of " << argc - 1 <<  " elements with std::vector : " << time << " µs" << endl;

	gettimeofday(&tv, NULL);
	startSec = tv.tv_sec;
	startMicro = tv.tv_usec;

	merge.sortList();

	gettimeofday(&tv, NULL);
	endSec = tv.tv_sec;
	endMicro = tv.tv_usec;
	time = float(endSec - startSec) + (float)((endMicro - startMicro) / 10000);
	cout << "Time to process a range of " << argc - 1 <<  " elements with std::list : " << time << " µs" << endl;

	merge.checkSorted();
}