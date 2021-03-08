#include<iostream>
#include<math.h>
#include<float.h>
#include<random>

using namespace std; 

class Point 
{ 
	public: 
	    int x, y; 
}; 


int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a;
    Point *p2 = (Point *)b; 

	return (p1->x - p2->x); 
} 

int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a;
    Point *p2 = (Point *)b; 

	return (p1->y - p2->y); 
} 


float dist(Point p1, Point p2) 
{ 
    double x_distance=pow((p1.x-p2.x),2);
    double y_distance=pow((p1.y-p2.y),2);

    return sqrt(x_distance+y_distance);
} 


float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

 
float min(float x, float y) 
{ 
	return (x < y)? x : y; 
} 


float stripClosest(Point strip[], int size, float d) 
{ 
	float min = d; 

	qsort(strip, size, sizeof(Point), compareY); 

	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 
	return min; 
} 


float closestUtil(Point P[], int n) 
{ 
	if (n <= 3) 
		return bruteForce(P, n); 

	int mid = n/2; 
	Point midPoint = P[mid]; 
 
	float dl = closestUtil(P, mid); 
	float dr = closestUtil(P + mid, n - mid); 
	float d = min(dl, dr); 

	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 

	return min(d, stripClosest(strip, j, d) ); 
} 


float closest(Point P[], int n) 
{ 
	qsort(P, n, sizeof(Point), compareX); 
	return closestUtil(P, n); 
} 


int main() 
{ 
    int num;
    cout<<"\nEnter the number of points in the Plane : ";
    cin>>num;


    Point P[num];

    for(int i=0;i<num;i++){
		P[i].x=((float)rand())/float(100);
		P[i].y=((float)rand())/float(100);
	}

	int n = sizeof(P) / sizeof(P[0]); 

    cout<<"\nThe points generated are :"<<endl;

    for (int i = 0; i < num; i++)
    {
        cout<<"p"<<i+1<<" "<<"("<<P[i].x<<","<<P[i].y<<")"<<endl;
    }
    
	cout << "The closest distance is " << closest(P, n); 
	
	return 0; 
} 

