#include <iostream>
using namespace std;

int main()
{
	int a[100],i,element=-1,num,j;
	char command,indicate;

	while(cin>>command){
		if(command=='e') {
			break;
		}
		cin>>indicate;

		if(command=='i'){
			cout<<"insert the desired num"<<endl;
			cin>>num;
			if(element == -1){
				a[0]=num;
				element++;
			}

			else{
				if(indicate=='f'){

					for(i=element;i>=0;i--){
						a[i+1]=a[i];
					}
					a[0]=num;
						element++;
				}

				if(indicate=='b'){
					a[element+1]=num;

					element++;
				}

			}
			for(i=0;i<=element;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;

		}

		if(command=='d'){
			if(element==-1){
				cout<<"array is empty"<<endl;
			}
			else{
				if(indicate=='f'){
					for(i=element;i>=0;i--){
						a[i-1]=a[i];
					}
					element--;
				}

				if(indicate=='b'){
					element--;
				}

				for(i=0;i<=element;i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;

			}

		}

	}

	return 0;
}
