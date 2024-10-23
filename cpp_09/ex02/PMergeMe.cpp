#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::~PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe &copy)
{
	*this = copy;
}

PMergeMe & PMergeMe::operator=(const PMergeMe &copy)
{
	(void)copy;
    return *this;
}

void PMergeMe::checkSorted()
{
	bool isVectorSorted = std::is_sorted(_vec.begin(), _vec.end());
	bool isListSorted = std::is_sorted(_list.begin(), _list.end());

	cout << "vector sorted: " << (isVectorSorted ? "true" : "false")
				<< " | list sorted: " << (isListSorted ? "true" : "false") << endl;
}

void PMergeMe::printVec()
{
	for(vector<int>::iterator it = _vec.begin(); it < _vec.end(); it++)
	{
		cout << " " << *it;
	}
}

void PMergeMe::printList()
{
	for(list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		cout << " " << *it;
	}
}

void PMergeMe::insertVec(vector<int> vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		_vec.push_back(*it);
}

void PMergeMe::insertionSortVec(vector<std::pair<int, int> > &vec)
{
	if (vec.size() < 2)
		return ;
	
	vector<std::pair<int, int> >::iterator itMiddle = vec.begin();
	for (int i = 0; i < (int)vec.size() / 2; i++)
		itMiddle++;
	vector<std::pair<int, int> > front(vec.begin(), itMiddle);
	vector<std::pair<int, int> > back(itMiddle, vec.end());

	insertionSortVec(front);
	insertionSortVec(back);

	vec.clear();

	vector<std::pair<int, int> >::iterator itFront = front.begin();
	vector<std::pair<int, int> >::iterator itBack = back.begin();

	while (itFront != front.end() && itBack != back.end())
	{
		if ((*itFront).second < (*itBack).second)
		{
			vec.push_back(*itFront);
			itFront++;
		}
		else
		{
			vec.push_back(*itBack);
			itBack++;
		}
	}

	while (itFront != front.end())
	{
		vec.push_back(*itFront);
		itFront++;
	}
	while (itBack != back.end())
	{
		vec.push_back(*itBack);
		itBack++;
	}
}

int PMergeMe::jacobsthal(int count)
{
	if (count == 0)
		return (0);
	if (count == 1)
		return (1);
	return (jacobsthal(count - 1) + (2 * jacobsthal(count - 2)));
}

void PMergeMe::sortVec()
{
	vector<std::pair<int, int> > pair;
	std::pair<int, int> tmp;

	bool hasStraggler = false;
	int straggler;

	// straggler
	if (_vec.size() <= 1)
		return ;
	if (_vec.size() % 2 == 1)
	{
		hasStraggler = true;
		straggler = *(_vec.end() - 1);
		_vec.pop_back();
	}

	// pairing
	for (vector<int>::iterator it = _vec.begin(); it < _vec.end(); it += 2)
	{
		tmp = std::make_pair(*it, *(it + 1));
		if (tmp.first > tmp.second)
		{
			int swap = tmp.first;
			tmp.first = tmp.second;
			tmp.second = swap;
		}
		pair.push_back(tmp);
	}

	// sorting
	insertionSortVec(pair);

	// extract back into vector<int>
	_vec.clear();
	vector<int> append;
	for (vector<std::pair<int, int> >::iterator it = pair.begin(); it != pair.end(); it++)
	{
		_vec.push_back((*it).second);
		append.push_back((*it).first);
	}

	_vec.insert(_vec.begin(), append.front());
	append.erase(append.begin());

	int count = 2;
	int jacob = 0;
	vector<int>::iterator itAppend = append.begin();
	vector<int>::iterator itTemp;

	// prep insertion sequence
	while (true)
	{
		itTemp = append.begin();
		jacob = jacobsthal(count);
		if (jacob >= (int)append.size())
			break ;
		std::advance(itTemp, jacob - 1);
		append.insert(itAppend, *itTemp);
		append.erase(itTemp + 1);
		++count;
		++itAppend;
	}

	// binary search, insert into append
	for (vector<int>::iterator it = append.begin(); it != append.end(); ++it)
	{
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), *it), *it);
	}

	// add straggler
	if (hasStraggler == true)
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), straggler), straggler);
}




void PMergeMe::insertList(vector<int> vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		_list.push_back(*it);
}

void PMergeMe::insertionSortList(list<std::pair<int, int> > &lst)
{
	if (lst.size() < 2)
		return ;
	
	list<std::pair<int, int> >::iterator itMiddle = lst.begin();
	for (int i = 0; i < (int)lst.size() / 2; i++)
		itMiddle++;
	list<std::pair<int, int> > front(lst.begin(), itMiddle);
	list<std::pair<int, int> > back(itMiddle, lst.end());

	insertionSortList(front);
	insertionSortList(back);

	lst.clear();

	list<std::pair<int, int> >::iterator itFront = front.begin();
	list<std::pair<int, int> >::iterator itBack = back.begin();

	while (itFront != front.end() && itBack != back.end())
	{
		if ((*itFront).second < (*itBack).second)
		{
			lst.push_back(*itFront);
			itFront++;
		}
		else
		{
			lst.push_back(*itBack);
			itBack++;
		}
	}

	while (itFront != front.end())
	{
		lst.push_back(*itFront);
		itFront++;
	}
	while (itBack != back.end())
	{
		lst.push_back(*itBack);
		itBack++;
	}
}

void PMergeMe::sortList()
{
	list<std::pair<int, int> > pair;
	std::pair<int, int> tmp;

	bool hasStraggler = false;
	int straggler;

	// straggler
	if (_list.size() <= 1)
		return ;
	if (_list.size() % 2 == 1)
	{
		hasStraggler = true;
		straggler = *(--_list.end());
		_list.pop_back();
	}

	// pairing
	list<int>::iterator itTmp;
	for (list<int>::iterator it = _list.begin(); it != _list.end(); std::advance(it, 2))
	{
		itTmp = it;
		std::advance(itTmp, 1);
		tmp = std::make_pair(*it, *itTmp);
		if (tmp.first > tmp.second)
		{
			int swap = tmp.first;
			tmp.first = tmp.second;
			tmp.second = swap;
		}
		pair.push_back(tmp);
	}

	// sorting
	insertionSortList(pair);

	// extract back into list<int>
	_list.clear();
	list<int> append;
	for (list<std::pair<int, int> >::iterator it = pair.begin(); it != pair.end(); it++)
	{
		_list.push_back((*it).second);
		append.push_back((*it).first);
	}

	_list.insert(_list.begin(), append.front());
	append.erase(append.begin());

	int count = 2;
	int jacob = 0;
	list<int>::iterator itAppend = append.begin();
	list<int>::iterator itTemp;
	list<int>::iterator itErase;

	// prep insertion sequence
	while (true)
	{
		itTemp = append.begin();
		jacob = jacobsthal(count);
		if (jacob >= (int)append.size())
			break ;
		std::advance(itTemp, jacob - 1);
		append.insert(itAppend, *itTemp);
		itErase = itTemp;
		std::advance(itErase, 1);
		append.erase(itErase);
		++count;
		++itAppend;
	}

	// binary search, insert into append
	for (list<int>::iterator it = append.begin(); it != append.end(); ++it)
	{
		_list.insert(std::lower_bound(_list.begin(), _list.end(), *it), *it);
	}

	// add straggler
	if (hasStraggler == true)
		_list.insert(std::lower_bound(_list.begin(), _list.end(), straggler), straggler);
}