#include <iostream>
#include <vector>

using namespace std;

void vozrast(vector<int>& vector)
{
	vector[0] = 1;
	for (int i = 1; i < vector.size(); i++)
	{
		vector[i] = rand() % 10 + vector[i - 1];
	}
}

void vivod(vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << "   ";
	}
}

void itog(vector<int>& third, vector<int> second, vector<int> first)
{
	int k = 0, i = 0, j = 0;

	for (; i < first.size() && j < second.size(); k++)
	{

		if (first[i] <= second[j])
		{
			third[k] = first[i]; i++;
		}
		else
		{
			third[k] = second[j]; j++;
		}
	}
	while (i < first.size())
	{
		third[k++] = first[i++];
	}
	while (j < second.size())
	{
		third[k++] = second[j++];
	}
}

int main()
{
	int a, b, c;
	cout << "Hello: " << endl;
	cout << "Kol elementov pervogo vectora" << endl; cin >> a;
	cout << "Kol elementov vtorogoo vectora" << endl; cin >> b;
	c = a + b;
	cout << "Kol elementov tretiego vectora = " << c << endl;

	vector<int> first(a);
	vector<int> second(b);
	vector<int> third(c);
	vozrast(first);
	vivod(first);	cout << endl;

	vozrast(second);
	vivod(second);	cout << endl;

	itog(third, first, second);
	vivod(third);

    return 0;
}