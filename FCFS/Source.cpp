#include<iostream>
#include<iomanip>
using namespace std;
void main() 
{
	struct process {
		int id, at, bt, wt;
	};
	process* arr;
	int num;
	cout << "Enter number of process..!";
	cin >> num;
	arr = new process [num]; //Dynamic array of struct
	

	cout << "\t Arrival Time  \t Burst Time  \n";
	for (int i = 0; i < num; i++) {
		arr[i].id = i + 1;
		cout << "P" << i + 1 << "\t";
		cin >> arr[i].at >> arr[i].bt;
	}
	//Bubble sort
	process temp;
	for (int i = 0; i < num - 1; i++) 
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i].at > arr[j].at)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	arr[0].wt = 0;
	int tot = 0;
	for (int i = 1; i < num; i++)
	{
		tot+=arr[i - 1].bt;
		arr[i].wt = tot - arr[i].at;
	}
	cout << "----------------------------------------------------------------\n";
	cout << "The Sequence of processes will be & wating time for each process \n";
	cout << "\t Arrival Time \t Burst Time \t waiting Time \t";

	for (int i = 0; i < num; i++)
	{
		cout << "P" << arr[i].id << "\t \t" << arr[i].at << "\t \t" << arr[i].bt << "\t \t" << arr[i].wt << endl;
			
	}
	cout << "----------------------------------------------------------------\n";
	cout << "Gant chart \n";
	for (int i = 0; i < num; i++)
	{
		cout << setw(arr[i].bt) << "P" << arr[i].id << "\t";
	}
	cout << endl <<"0";
	tot = 0;
	for (int i = 0; i < num; i++)
	{
		tot += arr[i].bt;
		cout << setfill('-') << "P" << setw(arr[i].bt*2)<<tot;
	}

	//Calculate Average waiting time

	int sum = 0;
	for (int i = 0; i < num; i++) 
	{
		sum += arr[i].wt;
	}

	cout << "\n \n Average waiting time =" << sum << "/" << num << " = " <<(float)sum/num<<endl;
	delete[] arr;
}
