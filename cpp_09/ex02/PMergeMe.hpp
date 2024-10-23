# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <sys/time.h>

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::list;

class PMergeMe
{
	public:
		PMergeMe();
		~PMergeMe();
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator=(const PMergeMe &copy);

		int jacobsthal(int count);

		void checkSorted();
		void insertionSortVec(vector<std::pair<int, int> > &vec);
		void insertVec(vector<int> vec);
		void sortVec();
	
		void insertionSortList(list<std::pair<int, int> > &lst);
		void insertList(vector<int> vec);
		void sortList();
		
		void printVec();
		void printList();

	private:
		list<int> _list;
		vector<int> _vec;
};

# endif