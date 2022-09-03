#include <iostream>
#include <vector>
using namespace std;


class CMyComplexDataStructure
{
	vector<float> m_container;
public:
	void Insert(float fVal) { m_container.push_back(fVal); }
	template <typename objclass>
		void sumone(objclass funobj)
	{
		vector<float>::iterator iter = m_container.begin();
		for (; iter != m_container.end() ; iter++)
			funobj(*iter);
	}
	
	
	void Print(){
		vector<float>::iterator iter = m_container.begin();
		for (; iter != m_container.end() ; iter++)
			cout<<*iter<<"\t";
		cout<<endl;
	}
};




template <typename objclass>
class funcobjclass
{
public:
	void operator ()(objclass& objinstance)
	{
		objinstance++;
	}
};


int main(int argc, char* argv[])
{
	CMyComplexDataStructure ds;
	ds.Insert(1.1);
	ds.Insert(1.2);
	ds.Insert(1.3);
	ds.Insert(1.4);
	ds.Print();
	funcobjclass<float> x;
	ds.sumone(x);
	ds.Print();
	return 0;
}
