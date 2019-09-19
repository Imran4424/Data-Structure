#include <iostream>
using namespace std;

void BuildTower(char source, char auxilary, char destination, int diskNum)
{
	// base classes
	if (1 == diskNum)
	{
		// top disk reached, so now move it from source to destination

		cout << "Moving Disk 1 from " << source << " to " << destination << endl;

		return;
	}

	// this call make the half process
	// n - 1 disks moved to auxilary 
	// n-th disk moved to source to destination

	BuildTower(source, destination, auxilary, diskNum - 1);

	cout << "Moving Disk " << diskNum << " from " << source << " to " << destination << endl;

	// this call make the other half process
	// n - 2 disks moved to auxilary 
	// (n-1)-th disk moved to source to destination

	BuildTower(auxilary, source, destination, diskNum - 1);
}

int main(int argc, char const *argv[])
{
	char source = 'A';
	char auxilary = 'B';
	char destination = 'C';

	cout << "enter the Disk number" << endl;

	int diskNum;
	cin >> diskNum;

	BuildTower(source, auxilary, destination, diskNum);

	return 0;
}