#include <iostream>
using namespace std;

void displayop()
{
    cout<<"press i to insert"<<endl;
    cout<<"press d to delete"<<endl;
    cout<<"press e to exit"<<endl;
}

void op()
{
    cout<<"press f for front action"<<endl;
    cout<<"press b for back action"<<endl;
}

int main()
{
	int a[100],i,element=-1,num,j;
	char command,indicate;


	while(1){
	    displayop();

        cin>>command;
		if(command=='e') {
			break;
		}
		op();

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
					for(i=0;i<=element;i++){
						a[i]=a[i+1];
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
				//cout<<a[element+1]<<"still here";

			}

		}

	}

	return 0;
}
