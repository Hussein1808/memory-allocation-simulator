#include<iostream>
 
using namespace std;
 
void type();

void bestfit()
{
	int fragment[30], BlockS[30], ProcessS[30], noblocks, noprocess, frag = 9999;
	static int Blockarr[30], Processarr[30];

	cout << "\n\t Best Fit\n";

	cout << "Number of blocks ? \n";
	cin >> noblocks;
	cout << "Size of each block ? ";
	for (int BB = 1; BB <= noblocks; BB++)
	{
		cin >> BlockS[BB];
	}

	cout << endl<<" Number of processes ? ";
	cin >> noprocess;
	cout << endl<<" Size of each process ? ";
	for (int BB = 1; BB <= noprocess; BB++)
	{
		cin >> ProcessS[BB];
	}

	int temp;
	for (int BB = 1; BB <= noprocess; BB++)
	{
		for (int PP = 1; PP <= noblocks; PP++)
		{
			if (Blockarr[PP] != 1)
			{
				temp = BlockS[PP] - ProcessS[BB];
				if (temp >= 0)
				{
					if (frag > temp)
					{
						Processarr[BB] = PP;
						frag = temp;
					}
				}
			}
		}

		fragment[BB] = frag;
		Blockarr[Processarr[BB]] = 1;
		frag = 10000;
	}

	cout << endl<<" Process_number \t Process_Size \t Block_no \t Block_size \t Fragment";
	
	for (int BB = 1; BB <= noprocess; BB++)
	{
		if (Processarr[BB] != 0)
		{
			cout << endl << BB << "\t\t\t" << ProcessS[BB] << "\t\t" << Processarr[BB] << "\t\t" << BlockS[Processarr[BB]] << "\t\t" << fragment[BB]<<endl;
		}
		else
		{
			cout << endl << BB << "\t\t\t" << ProcessS[BB] << "\t\t" << "not allocated" << "\t\t" << endl;
		}
	}
	int again;
	cout << "choose" << endl << "1.new place" << endl << "2.end program" << endl;
	cin >> again;
	if (again == 1)
	{
		type();
	}
}

void firstfit()
{
	int BlockS[30], ProcessS[30], noblocks, noprocess, indicator[30], place[30];

	for (int BB = 0; BB < 30; BB++)
	{
		indicator[BB] = 0;
		place[BB] = -1;
	}

	cout << "Number of blocks ? ";
	cin >> noblocks;
	cout << endl<<" Size of each block ? ";
	for (int BB = 0; BB < noblocks; BB++)
	{
		cin >> BlockS[BB];
	}

	cout << endl<<" Number of processes ? ";
	cin >> noprocess;
	cout << endl<<" Size of each process ? ";
	for (int BB = 0; BB < noprocess; BB++)
	{
		cin >> ProcessS[BB];
	}


	for (int BB = 0; BB < noprocess; BB++)
	{
		for (int PP = 0; PP < noblocks; PP++)
		{
			if (indicator[PP] == 0 && BlockS[PP] >= ProcessS[BB])
			{
				place[PP] = BB;
				indicator[PP] = 1;
				break;
			}

		}
	}

	cout << endl<<"Block number\t Size \t process number\t\t\t Size";
	for (int BB = 0; BB < noblocks; BB++)
	{
		cout << endl << BB + 1 << "\t\t" << BlockS[BB] << "\t\t";
		if (indicator[BB] == 1)
			cout << place[BB] + 1 << "\t\t\t" << ProcessS[place[BB]] << endl;
		else
			cout << "isn't allocated";
	}
	int again;
	cout << "choose" << endl << "1.new place" << endl << "2.end program" << endl;
	cin >> again;
	if (again == 1)
	{
		type();
	}
}

void worstfit()
{

	cout << "\n\t worst fit \n";
	int BlockS[30], ProcessS[30], noblocks, noprocess, Validation[30], place[30];

	for (int BB = 0; BB < 30; BB++)
	{
		Validation[BB] = 0;
		place[BB] = -1;
	}

	cout << "Number of blocks ? ";
	cin >> noblocks;
	cout << endl<<" Size of each block ? ";
	for (int BB = 0; BB < noblocks; BB++)
	{
		cin >> BlockS[BB];
	}

	cout << endl<<" Number of processes ? ";
	cin >> noprocess;
	cout << endl<<" Size of each process ? ";
	for (int BB = 0; BB < noprocess; BB++)
	{
		cin >> ProcessS[BB];
	}

	for (int BB = 0; BB < noprocess; BB++)
	{
		int temp = 0, flag = -1;
		for (int PP = 0; PP < noblocks; PP++)
		{
			if (Validation[PP] == 0)
			{
				if (ProcessS[BB] <= BlockS[PP] && BlockS[PP] >= temp) {
					temp = BlockS[PP];
					flag = PP;
				}
			}
		}

		if (flag != -1)
		{
			place[flag] = BB;
			Validation[flag] = 1;

		}
		flag = -1;
	}

	cout << endl<<"Block number\t Size \t process number\t\t\t Size";
	for (int BB = 0; BB < noblocks; BB++)
	{
		cout << endl << BB + 1 << "\t\t" << BlockS[BB] << "\t\t";
		if (Validation[BB] == 1)
			cout << place[BB] + 1 << "\t\t\t" << ProcessS[place[BB]];
		else
			cout << "isn't allocated";
	}
	cout << "\n\n\n";
	int again;
	cout << "choose" << endl << "1.new place" << endl << "2.end program" << endl;
	cin >> again;
	if (again == 1)
	{
		type();
	}
}


void type()
{

	int x;
	cout << "choose" << endl << "1-first fit" << endl << "2-best fit" << endl << "3-worst fit" << endl;
	cin >> x;
	if (x == 1)
		firstfit();
	else if (x == 2)
		bestfit();
	else if (x == 3)
		worstfit();
	

}
int main()
{	
	type();
}