#include<bits/stdc++.h>

using namespace std;

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
    private:
        int l,b,h;
    public:
        Box () {
            l = 0;
            b = 0;
            h = 0;
        }
        Box (int length, int breadth, int height) {
            l = length;
            b = breadth;
            h = height;
        }

        int getLength() { return l; }
        int getBreadth() { return b; }
        int getHeight() { return h; }
        
        Box (Box &box) {
            l = box.getLength();
            b = box.getBreadth();
            h = box.getHeight();
        }
        long long CalculateVolume() {
            long long volume = (long long)(l) * b * h;
            return volume;
        }
        bool operator < (Box &box) {
            bool result = false;
            int l2 = box.getLength();
            int b2 = box.getBreadth();
            int h2 = box.getHeight();
            if(l<l2 || (b<b2 && l==l2) || (h<h2 && b==b2 && l==l2)) {
                result = true;
            }
            return result;
        };
};

ostream& operator << (ostream &out, Box &box) {
    stringstream ss;
    ss << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();
    out << ss.str();
    return out;
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}