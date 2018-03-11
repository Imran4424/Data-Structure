#include <iostream>
using  namespace std;

int element= -1,a[100];

void disop()
{
	cout<<"1.Insert"<<endl<<"2.delete"<<endl<<"3.Sorting"<<endl<<"4.exit\n"<<endl;
}

void disop2()
{
	cout<<"1.Front"<<endl<<"2.Back"<<endl<<"3.Anyplace"<<endl<<"4.Back to main menu\n"<<endl;
}

void display()
{
	int i,min=10000,max=0,total=0;
	double avg;
	for(i=0;i<=element;i++){
		total += a[i];
		if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }

	}
	for(i=0;i<=element;i++){
		cout<<a[i]<<" ";

	}
	cout<<endl;

	if(element>-1){
		avg =(double) total/(element+1);
		cout<<"Maximum value and minimum value "<<max<<" "<<min<<endl;
		cout<<"Total value and Average value "<<total<<" "<<avg<<endl;
	}
}


int insert()
{
	cout<<"Please insert your number"<<endl;
	int num,indicate,place,i;
	cin>>num;
	disop2();
	cin>>indicate;
	if(indicate==4){
		return 0;
	}

	if(element == -1){
		a[0]=num;
		element++;
	}

	else{
		if(indicate==1){
			place=0;
		}

		if(indicate==2){
			place=element+1;
		}

		if(indicate==3){
			cout<<"insert the desired place \n"<<endl;
			cin>>place;
		}
		if(place>element+1){
			cout<<"Sorry not possible \n"<<endl;
		}
		else if(place==element+1){
			a[element+1]=num;
			element++;
		}
		else{
			for(i=element;i>=place;i--){
				a[i+1]=a[i];
			}
			a[place]=num;
			element++;
		}




	}

	display();
	return 0;
}

int delete1()
{
	int indicate,place,i;
	disop2();
	cin>>indicate;
	if(indicate==4){
		return 0;
	}
	if(element==-1){
		cout<<"array is empty"<<endl;
	}
	else{
		if(indicate==1){
			place=0;
		}

		if(indicate==2){
			place=element;
		}
		if(indicate==3){
			cout<<"insert the desired place \n"<<endl;
			cin>>place;
		}
		if(place>element){
			cout<<"Sorry not possible \n"<<endl;
		}
		else if(place==element){
				element--;
		}
		else{
			for(i=place;i<=element;i++){
				a[i]=a[i+1];
			}
			element--;
		}


	}
		display();

		return 0;
}

int sorting()
{
	int indicate,i,j,temp;
	cout<<"Pick your choice\n"<<endl;
	cout<<"1.Ascending"<<endl<<"2.Descending"<<endl<<"3.Back to main menu\n"<<endl;
	cin>>indicate;

	if(indicate==3){
		return 0;
	}
	if(element>0){
		if(indicate==1){
			for(i=0;i<=element;i++){
        		for(j=0;j<=element-i-1;j++){
            		if(a[j]>a[j+1]){
                		temp=a[j];
                		a[j]=a[j+1];
                		a[j+1]=temp;
            		}
       	 		}
    		}
		}

		if(indicate==2){
			for(i=0;i<=element;i++){
        		for(j=0;j<=element-i-1;j++){
            		if(a[j]<a[j+1]){
                		temp=a[j];
                		a[j]=a[j+1];
                		a[j+1]=temp;
            		}
       	 		}
    		}

		}
	}
	if(element==-1){
		cout<<"Array is empty"<<endl;
	}

	display();
	return 0;
}

int main()
{
	int indicate;

	while(1){
		disop();
		cin>>indicate;
		if(indicate==1){
			insert();
		}
		if(indicate==2){
			delete1();
		}
		if(indicate==3){
			sorting();
		}
		if(indicate==4){
			break;
		}

	}

}
