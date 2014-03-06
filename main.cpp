#include <iostream>
#include "map_avl.hpp"

using namespace std;


int main()
{
		map<int, int> h, h1;
		map<int, int> :: iterator it, it1;
		pair< map<int, int> :: iterator, bool> ap;
		int n, opt, j, m;
		
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
				j = rand()%3000;
				m = rand()%3000;
				h.insert(pair<int, int>(j, j));
				h1.insert(pair<int, int>(m, m));
		}
		
	map<int, int> :: value_type val(*h.begin());
	
	
		map<int, int> h2(h1);
	
		
		cout << "first map\n";
		for (it = h.begin(); it != h.end(); ++it) 
				cout << it->first <<  "->" << it->second << " ";
		cout << endl;		
		cout << "second map\n";
		for (it = h2.begin(); it != h2.end(); ++it) 
				cout << it->first <<  "->" << it->second << " ";
		cout << endl;
		
		cout << "< comparison result= " << (h < h2) << endl;		
		cout << "> comparison result= " << (h > h2) << endl;		
		cout << "<= comparison result= " << (h <= h2) << endl;		
		cout << ">= comparison result= " << (h >= h2) << endl;		
		cout << "== comparison result= " << (h == h2) << endl;		
		cout << "!= comparison result= " << (h != h2) << endl;		

	cout << "option\n";
	
	do {
	cout << "1.find\n2.erase by key\n3.print\n4.insert\\change by []\n5.insert by insert\n6.erase by iterator\n7.print lower elements\n8.print upper element\n9.size\n10.count\n11.exit\n";		
	cin >> opt;
	switch(opt)
	{
		case 1:
		cout << "enter key\n";
			cin >> n;
			it = h.find(n);
			if (it != h.end())
				cout << "found\n";	
			else
				cout << "not found\n";	
			break;
		case 2:
		cout << "enter key\n";
			cin >> n;
			h.erase(n);
			break;
		case 3:
		for (it = h.begin(); it != h.end(); ++it) 
				cout << (*it).first <<  "->" << (*it).second << " ";
		cout << endl;		
			break;
		case 4:
		cout << "enter key and value\n";
			cin >> n >> m;
			h[n] = m;
			break;
		case 5:
		cout << "enter key and value\n";
			cin >> n >> m;
			ap = h.insert(pair<int,int> (n,m));
			if (ap.second == false)
				cout << "already inserted\n";
			else 
				cout << "inserted\n";
			break;
		case 6:
		cout << "enter key\n";
			cin >> n;
			it = h.find(n);
			h.erase(n);
			break;
		case 7:
		cout << "enter key\n";
			cin >> n;
			it = h.find(n);
			for (it1 = it; it1 != h.begin(); --it1)
				cout << it1->first << "->" << it1->second << " ";
			cout << it1->first << "->" << it1->second << endl;
			break;			
		case 8:
		cout << "enter key\n";
			cin >> n;
			it = h.find(n);
			for (it1 = it; it1 != h.end(); ++it1)
				cout << it1->first << "->" << it1->second << " ";
			cout << endl;	
			break;	
		case 9:
			cout << h.size() << endl;	
			break;
		case 10:
			cout << "enter key\n";
			cin >> n;
			cout <<  h.count(n) << endl;
			break;	
	default:
			break;
	};
	}while (opt != 11);					
	
		return 0;
}


