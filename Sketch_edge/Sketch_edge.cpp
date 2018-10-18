#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef struct Cube
{
	int left, right, height;
}cube;

void Compare_left(vector <cube> &V, int count)
{
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
		{
			cube temp;
			if ( V[i].left > V[j].left)
			{
				temp = V[i];
				V[i] = V[j];
				V[j] = temp;
			}
		}
}

void Contest(vector <cube> V, vector<int> &Vx, vector<int> &Vy, int i, int j)
{
	if (V[i].right < V[i + j].left)
	{
		Vx.push_back(V[i].right);
		Vy.push_back(V[i].height);
		Vx.push_back(V[i].right);
		Vy.push_back(0);
		Vx.push_back(V[i + j].left);
		Vy.push_back(0);
		Vx.push_back(V[i + j].left);
		Vx.push_back(V[i + j].height);
	} 
	else if(V[i].right == V[i + j].left)
	{
		if (v[i].height > v[i + j].height || v[i].height < v[i + j].height)
		{
			Vx.push_back(V[i].right);
			Vy.push_back(V[i].height);
			Vx.push_back(V[i].right);
			Vy.push_back(V[i + j].height);
		} 
	}
	else if(V[i].right > V[i + j].left)
	{
		if (v[i].height > v[i + j].height)
		{
			Vx.push_back(V[i].right);
			Vy.push_back(V[i].height);
			Vx.push_back(V[i].right);
			Vy.push_back(V[i + j].height);
		} 
		else if (v[i].height < v[i + j].height)
		{
			Vx.push_back(V[i + j].left);
			Vy.push_back(V[i].height);
			Vx.push_back(V[i + j].left);
			Vy.push_back(V[i + j].height);
		} 
	}
	if (V[i] == V.back())
	{
		Vx.push_back(V[i].right);
		Vy.push_back(V[i].height);
		Vx.push_back(V[i].right);
		Vy.push_back(0);
	} 
}


int main()
{	
	cube num;
	vector <cube> V;
	int count = 0;
	while (cin >> num.left)
	{
		cin >> num.height >> num.right;
		V.push_back(num);
		count++;
	}

	vector <int> Vx;
	vector <int> Vy;
	
	Vx.push_back(V[0].left);
	Vy.push_back(0);
	Vx.push_back(V[0].left);
	Vy.push_back(V[0].height);
	
	
	for(int i = 0; i < count; i++)
	{
		if (V[i].right < V[i + j].left)
	{
		Vx.push_back(V[i].right);
		Vy.push_back(V[i].height);
		Vx.push_back(V[i].right);
		Vy.push_back(0);
		Vx.push_back(V[i + j].left);
		Vy.push_back(0);
		Vx.push_back(V[i + j].left);
		Vx.push_back(V[i + j].height);
	} 
	else if(V[i].right == V[i + j].left)
	{
		if (v[i].height > v[i + j].height || v[i].height < v[i + j].height)
		{
			Vx.push_back(V[i].right);
			Vy.push_back(V[i].height);
			Vx.push_back(V[i].right);
			Vy.push_back(V[i + j].height);
		} 
	}
	else if(V[i].right > V[i + j].left)
	{
		if (V[i].right < V[i + j].right)
		if (v[i].height > v[i + j].height )
		{
			Vx.push_back(V[i].right);
			Vy.push_back(V[i].height);
			Vx.push_back(V[i].right);
			Vy.push_back(V[i + j].height);
		} 
		else if (v[i].height < v[i + j].height)
		{
			Vx.push_back(V[i + j].left);
			Vy.push_back(V[i].height);
			Vx.push_back(V[i + j].left);
			Vy.push_back(V[i + j].height);
		} 
	}
	else if
	}
	Vx.push_back(V.back().right);
	Vy.push_back(V.back().height);
	Vx.push_back(V.back().right);
	Vy.push_back(0);
	

}
